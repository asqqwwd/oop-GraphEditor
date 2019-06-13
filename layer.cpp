#include "layer.h"

/***��Ƭͼ��ʵ�ֲ���***/
Slice::Slice(int id, int width, int height, QString _fill)
{
	this->id = id;
	this->visible = true;
	this->mix_mode = 0;    //0ΪNormal,2ΪDarken,3ΪLighten
	this->fill = _fill;
	this->R = new uchar[height*width];
	this->G = new uchar[height*width];
	this->B = new uchar[height*width];
	this->A = new uchar[height*width];
	this->offset[0] = this->offset[1] = 0;
	this->offset_bak[0] = this->offset_bak[1] = 0;
	this->width = width;
	this->height = height;
	
	if (fill == "Limpid") {    //͸��������͸������
		int pix = 10;
		int pix2 = 2 * pix;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j%pix2 < pix ^ i%pix2 < pix) {
					R[i*width + j] = G[i*width + j] = B[i*width + j] = 255;
				}
				else {
					R[i*width + j] = G[i*width + j] = B[i*width + j] = 204;
				}
				this->A[i*width + j] = 255;
			}
		}
		this->Alpha = 0;
	}
	else if (fill == "White") {
		memset(R, 255, height*width);
		memset(G, 255, height*width);
		memset(B, 255, height*width);
		memset(A, 255, height*width);
		this->Alpha = 0;
	}
	else if (fill == "Black") {
		memset(R, 0, height*width);
		memset(G, 0, height*width);
		memset(B, 0, height*width);
		memset(A, 255, height*width);
		this->Alpha = 0;
	}
	else if (fill == "Yellow") {
		memset(R, 255, height*width);
		memset(G, 255, height*width);
		memset(B, 0, height*width);
		memset(A, 255, height*width);
		this->Alpha = 0;
	}
	else if (fill == "Default") {    //ȱʡ���½�͸����ɫͼ�㣬���ɼ���Ϊ0!!!
		memset(R, 0, height*width);
		memset(G, 0, height*width);
		memset(B, 0, height*width);
		memset(A, 0, height*width);
		this->Alpha = 0;
	}
	else {    //����ΪͼƬ
		QImage img(fill);
		this->resolveImage(&img);
	}
}

void Slice::resolveImage(QImage *img)
{
	uchar *line = new uchar[4 * width];
	for (int i = 0;i < height;i++) {
		line = img->scanLine(i);
		for (int j = 0;j < width;j++) {    //RGB 0xffrrggbb
			B[i*width + j] = line[4 * j];
			G[i*width + j] = line[4 * j + 1];
			R[i*width + j] = line[4 * j + 2];
			A[i*width + j] = 255;    //???
		}
	}
	this->Alpha = 0;

}

/***��ͼ�����ʵ�ֲ���***/
MyLayer::MyLayer(int _width, int _height, QString _background)
{
	this->width = _width;
	this->height = _height;
	if (width % 4 != 0) {    //��֤���Ϊ4�ı���!!!
		this->width = width + 4 - width % 4;
	}
	this->focus = -1;    //��ʼΪ0��ͼ��
	this->countID = -1;    //��ʼID��-1
	this->createSlice("Limpid");    //����0��ͼ�㣬0��ͼ��Ϊ��ͼ�㣬����ɾ��
	if (_background != "Limpid") {    //�������Ϊ������ɫ�����½�һ��ͼ��
		this->createSlice(_background);
	}
	this->updateImage();
}

void MyLayer::updateImage()
{
	uchar *imageRGB_tmp = new uchar[3 * height*width];    //������4�ı���

	for (int i = 0; i<height; i++) {    //����͸������ֽ
		for (int j = 0; j<width; j++) {
			imageRGB_tmp[i * 3 * width + 3 * j] = lst[0]->R[i*width + j];
			imageRGB_tmp[i * 3 * width + 3 * j + 1] = lst[0]->B[i*width + j];
			imageRGB_tmp[i * 3 * width + 3 * j + 2] = lst[0]->G[i*width + j];
		}
	}

	for (int k = 1; k < lst.size(); k++) {
		if (!lst[k]->visible) {    //�ж��Ƿ����
			continue;
		}
		int Alpha_tmp = lst[k]->Alpha;
		int dx = lst[k]->offset[0];
		int dy = lst[k]->offset[1];
		for (int i = 0, m = 0; i < height; i++) {
			for (int j = 0, n = 0; j < width; j++) {
				//��Χ���ڣ���λ���µ�����Ϣ
				if (i >= dy && i < height + dy && j>= dx && j < width + dx) {
					int xx = i * width + j - dy * width - dx;
					int yy = i * 3 * width + 3 * j;
					float factor = (float)Alpha_tmp / 100.0;
					//R(mix)=(1-alpha(1))*R(1) + alpha(1)*R(0)
					if (lst[k]->A[xx] == 255) {
						imageRGB_tmp[yy] = (1 - factor)*lst[k]->R[xx] + factor * imageRGB_tmp[yy];
						imageRGB_tmp[yy + 1] = (1 - factor)*lst[k]->G[xx] + factor * imageRGB_tmp[yy + 1];
						imageRGB_tmp[yy + 2] = (1 - factor)*lst[k]->B[xx] + factor * imageRGB_tmp[yy + 2];
					}
				}
			}
		}
	}
	QImage *tmp = new QImage(imageRGB_tmp, width, height, QImage::Format_RGB888);
	imageRGB = QPixmap::fromImage(*tmp);
	if (imageRGB_tmp != nullptr) {
		delete[] imageRGB_tmp;
		
	}
	if (tmp != nullptr) {
		delete[] tmp;

	}
}

void MyLayer::addCanvastoImage(QImage more)
{
	uchar *line = new uchar[4 * width];
	//int dx = lst[focus]->offset[0];
	//int dy = lst[focus]->offset[1];
	for (int i = 0;i < height;i++) {
		line = more.scanLine(i);
		for (int j = 0;j < width;j++) {    //ARGB aarrggbb
			if (line[4 * j + 3] != 0) {    //A��Ϊ͸��,255Ϊ��͸��
				/*if (i >= dy && i < height + dy && j >= dx && j < width + dx) {
					lst[focus]->B[i*width + j - dy * width - dx] = line[4 * j];
					lst[focus]->G[i*width + j - dy * width - dx] = line[4 * j + 1];
					lst[focus]->R[i*width + j - dy * width - dx] = line[4 * j + 2];
				}*/
				lst[focus]->B[i*width + j] = line[4 * j];
				lst[focus]->G[i*width + j] = line[4 * j + 1];
				lst[focus]->R[i*width + j] = line[4 * j + 2];
				lst[focus]->A[i*width + j] = 255;    //��Ӧ���ص�Ϊ�ɼ�
			}
		}
	}
	this->updateImage();
}

void MyLayer::changeSliceOffset(int dx, int dy)
{
	lst[focus]->offset[0] = lst[focus]->offset_bak[0] + dx;    //���ԼӸ���Χ
	lst[focus]->offset[1] = lst[focus]->offset_bak[1] + dy;
	this->updateImage();    //����ͼ��
}

void MyLayer::changeOffsetbak(int dx, int dy)
{
	this->lst[focus]->offset_bak[0] += dx;
	this->lst[focus]->offset_bak[1] += dy;
}

void MyLayer::createSlice(QString fill)
{
	this->lst.insert(++focus, new class Slice(++countID, width, height, fill));
	this->updateImage();
}

void MyLayer::deleteSlice()
{
	if (focus != 0) {    //0��ͼ�㲻��ɾ��
		this->lst.remove(focus, 1);
		this->updateImage();
	}
}

Slice * MyLayer::getFocusSlice()
{
	return this->lst[focus];
}

QPixmap MyLayer::getImageRGB()
{
	return this->imageRGB;
}

int MyLayer::getCountID()
{
	return this->countID;
}

int MyLayer::getFocus()
{
	return this->focus;
}

int MyLayer::getAlpha()
{
	return lst[focus]->Alpha;
}

int MyLayer::getMixMode()
{
	return lst[focus]->mix_mode;
}

bool MyLayer::getVisible()
{
	return lst[focus]->visible;
}

void MyLayer::setFocus(int tar)
{
	this->focus = tar;
	/*if (tar >= 0 && tar < lst.size()) {
		this->focus = tar;
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("Fatal error!");
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		int ret = msgBox.exec();
	}*/
}

void MyLayer::setAlpha(int tar)
{
	lst[focus]->Alpha = tar;
	this->updateImage();
}

void MyLayer::setMixMode(int tar)
{
	lst[focus]->mix_mode = tar;
	this->updateImage();
}

void MyLayer::setVisile(bool tar)
{
	lst[focus]->visible = tar;
	this->updateImage();
}



