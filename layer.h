#pragma once
#include <QPixmap>
#include <QtWidgets/QLabel>
#include <QMessageBox>

class Slice
{
public:
	Slice(int _id, int _width, int _height, QString _fill = "Default");
	void resolveImage(QImage *img);

	int id;    //ΨһID
	bool visible;    //�ɼ���
	int mix_mode;    //���ģʽ
	QString fill;    //�����ɫ
	int Alpha;    //͸���ȣ�100%Ϊ��ȫ͸����0%Ϊ��͸��
	uchar *R, *G, *B, *A;    //A����ÿ�����صĴ���״̬��255Ϊ���ڣ�0Ϊ�����ڣ���ֻ��0��255����ֵ�����ϱߵ�Alpha������ȫ�෴��ע��!!!
	int offset[2];    //��ǰͼ�ɵ�ƫ����
	int offset_bak[2];    //ƫ�����ı���
	int width;
	int height;
};

class MyLayer
{
public:
	MyLayer(int _width, int _height, QString _background);
	void updateImage();    //����ͼ��
	void changeSliceOffset(int dx, int dy);    //�ı�ƫ�����������ƶ�ͼ��
	void changeOffsetbak(int dx, int dy);    //Ϊ�����׼ȷ������ĺ���
	void createSlice(QString fill = "Default");    //�ڵ�ǰfocus���ϲ��½�ͼ��
	void deleteSlice();    //ɾ����ǰfoucs��Ӧ��ͼ��
	void addCanvastoImage(QImage more);    //��more�ӵ���ǰѡ��ͼ��

	//QVector<Slice*> getList();    //��ȡȫ��ͼ����Ϣ
	Slice *getFocusSlice();     //��ȡ��ǰfocus��slice
	QPixmap getImageRGB();    //���ڻ�ȡ�ϳ�ͼ��
	int getCountID();
	int getFocus();
	int getAlpha();
	int getMixMode();
	bool getVisible();

	void setFocus(int tar);
	void setAlpha(int tar);
	void setMixMode(int tar);
	void setVisile(bool tar);

private:
	int width;
	int height;
	int focus;    //��ǰѡ��ͼ��
	int countID;    //ID��������ֻ��������ÿ��ͼ��IDΨһ
	QPixmap imageRGB;    //����ͼ��ϳɽ����������ͼ��
	QVector<Slice*> lst;    //����ͼ�㣬0��Ϊ��ͼ��
};