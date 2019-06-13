#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDesktopWidget>
#include "ui_mainwindow.h"
#include "file.h"
#include "layer.h"
#include "view.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = Q_NULLPTR);
	void initWidgetPos();    //初始化控件位置
	void initTools();    //初始化工具栏

protected:
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	Ui::MainWindow *ui;    //创建初始ui对象，一定得创建实例对象
	MyFile *pFile;    //文件类
	MyLayer *pLayer;    //主图层类
	MyView *pView;    //视口类
	QMenu *Rmenu;    //右键菜单

	QPoint press_point;    //鼠标按下的坐标<int>
	QPoint release_point;    //鼠标释放的坐标<int>
	bool is_move;    //鼠标的移动状态判定

//----------------------------------------------------------------------------------------//
public slots :    //必须为public
	void createMainLayer(int width, int height, QString background);    //OK按钮按下后创建主图层对象
	void updateLayerInfo(int currentRow);    //图层面板选择对象改变时对应的槽函数
	void addSlice();    //加号对应的槽函数，用于新建一层
	void removeSlice();    //减号对应的槽函数，用于删除一层
	void changeOpacity(int value);    //slider对应的槽函数，用于改变焦点图层的透明度
	void changeVisible(bool tar);    //radio对应的槽函数，用于改变可视化

	void saveImage(QString file_path = nullptr);    //保存文件的响应函数
	void changeToolTypetoMove();    //按钮的响应函数，将工具类型改为抓手
	void changeToolTypetoLine();
	void changeToolTypetoRectangle();
	void changeToolTypetoCircle();

	void setLineWidth(double li);    //设置绘制图形线宽的响应函数
	void setLineColor();    //设置绘制图形线条颜色
	void setFillColor();    //设置绘制图形填充颜色
	void setLineStyle(const QString st);     //设置绘制图形线条风格
	void setFillStyle(const QString st);    //设置绘制图形填充风格
};

