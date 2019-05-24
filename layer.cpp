#include "layer.h"

/***单片图层实现部分***/
Slice::Slice(int id, int width, int height, QString _fill)
{
	this->id = id;
	this->visible = true;
	this->mix_mode = 0;    //0为Normal,2为Darken,3为Lighten
	this->fill = _fill;
	this->R = new uchar[height*width];
	this->G = new uchar[height*width];
	this->B = new uchar[height*width];
	this->offset[0] = this->offset[1] = 0;
	this->offset_bak[0] = this->offset_bak[1] = 0;
	
	if (fill == "Limpid") {    //透明，绘制透明格子
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

			}
		}
		this->Alpha = 0;
	}
	else if (fill == "White") {
		memset(R, 255, height*width);
		memset(G, 255, height*width);
		memset(B, 255, height*width);
		this->Alpha = 0;
	}
	else if (fill == "Black") {
		memset(R, 0, height*width);
		memset(G, 0, height*width);
		memset(B, 0, height*width);
		this->Alpha = 0;
	}
	else if (fill == "Yellow") {
		memset(R, 255, height*width);
		memset(G, 255, height*width);
		memset(B, 0, height*width);
		this->Alpha = 0;
	}
	else if (fill == "Default") {    //默认缺省，新建透明白色图层
		memset(R, 0, height*width);
		memset(G, 0, height*width);    //debug
		memset(B, 150, height*width);
		this->Alpha = 50;    //debug
	}
}

/***主图层大类实现部分***/
MyLayer::MyLayer(int _width, int _height, QString _background)
{
	this->width = _width;
	this->height = _height;
	this->focus = -1;    //初始为0号图层
	this->countID = -1;    //开始ID在-1
	this->createSlice("Limpid");    //创建0号图层，0号图层为根图层，不可删除
	if (_background != "Limpid") {    //如果背景为其他颜色，则新建一个图层
		this->createSlice(_background);
	}
	this->updateImage();
}

void MyLayer::updateImage()
{
	uchar *imageRGB_tmp = new uchar[3 * height*width];

	for (int i = 0; i<height; i++) {    //加载透明方格纸
		for (int j = 0; j<width; j++) {
			imageRGB_tmp[i * 3 * width + 3 * j] = lst[0]->R[i*width + j];
			imageRGB_tmp[i * 3 * width + 3 * j + 1] = lst[0]->G[i*width + j];
			imageRGB_tmp[i * 3 * width + 3 * j + 2] = lst[0]->B[i*width + j];
		}
	}

	for (int k = 1; k < lst.size(); k++) {
		if (!lst[k]->visible) {    //判断是否可视
			continue;
		}
		int Alpha_tmp = lst[k]->Alpha;
		int dx = lst[k]->offset[0];
		int dy = lst[k]->offset[1];
		for (int i = 0, m = 0; i < height; i++) {
			for (int j = 0, n = 0; j < width; j++) {
				//范围以内，错位更新叠加信息
				if (i >= dy && i < height + dy && j>= dx && j < width + dx) {
					//R(mix)=(1-alpha(1))*R(1) + alpha(1)*R(0)
					float factor = (float)Alpha_tmp / 100.0;
					imageRGB_tmp[i * 3 * width + 3 * j] = (1 - factor)*lst[k]->R[i*width + j - dy * width - dx] + factor * imageRGB_tmp[i * 3 * width + 3 * j];
					imageRGB_tmp[i * 3 * width + 3 * j + 1] = (1 - factor)*lst[k]->G[i*width + j - dy * width - dx] + factor * imageRGB_tmp[i * 3 * width + 3 * j + 1];
					imageRGB_tmp[i * 3 * width + 3 * j + 2] = (1 - factor)*lst[k]->B[i*width + j - dy * width - dx] + factor * imageRGB_tmp[i * 3 * width + 3 * j + 2];
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

void MyLayer::changeSliceOffset(int dx, int dy)
{
	lst[focus]->offset[0] = lst[focus]->offset_bak[0] + dx;    //可以加个范围
	lst[focus]->offset[1] = lst[focus]->offset_bak[1] + dy;
	this->updateImage();    //更新图像
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
	if (focus != 0) {    //0号图层不可删除
		this->lst.remove(focus, 1);
		this->updateImage();
	}
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



