#pragma once
#include <QPixmap>
#include <QtWidgets/QLabel>
#include <QMessageBox>

class Slice
{
public:
	Slice(int _id, int _width, int _height, QString _fill = "Default");
	void resolveImage(QImage *img);

	int id;    //唯一ID
	bool visible;    //可见性
	int mix_mode;    //混合模式
	QString fill;    //填充颜色
	int Alpha;    //透明度，100%为完全透明，0%为不透明
	uchar *R, *G, *B, *A;    //A代表每个像素的存在状态，255为存在，0为不存在，且只有0与255两个值，与上边的Alpha意义完全相反，注意!!!
	int offset[2];    //当前图成的偏移量
	int offset_bak[2];    //偏移量的备份
	int width;
	int height;
};

class MyLayer
{
public:
	MyLayer(int _width, int _height, QString _background);
	void updateImage();    //更新图像
	void changeSliceOffset(int dx, int dy);    //改变偏移量，用于移动图层
	void changeOffsetbak(int dx, int dy);    //为了提高准确性引入的函数
	void createSlice(QString fill = "Default");    //在当前focus的上层新建图层
	void deleteSlice();    //删除当前foucs对应的图层
	void addCanvastoImage(QImage more);    //将more加到当前选定图层

	//QVector<Slice*> getList();    //获取全部图层信息
	Slice *getFocusSlice();     //获取当前focus的slice
	QPixmap getImageRGB();    //用于获取合成图层
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
	int focus;    //当前选定图层
	int countID;    //ID计数器，只增不减，每个图层ID唯一
	QPixmap imageRGB;    //所有图层合成结果，包括根图层
	QVector<Slice*> lst;    //所有图层，0号为根图层
};