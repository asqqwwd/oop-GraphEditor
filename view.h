#pragma once
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsItem>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QtWidgets/QApplication>
#include <QColorDialog>
#include "layer.h"

class MyView : public QGraphicsScene
{
	Q_OBJECT
public:
	MyView(QWidget *parent, MyLayer *layer, QRect scope);
	
	void updateItem();    //更新Item
	qreal getScaleRatio();    //获取当前缩放比
	QPoint convertPixCoordinate(QPointF);    //将给定pt点转化为图层中的像素坐标位置
	bool isInItemScope(QPointF);    //判断是否在Item范围内

	void updateCanvas(QPoint);
	void setToolType(int);
	void setLineWidth(int);
	void setPenColor(QColor);
	void setPenStyle(int);
	void setBrushColor(QColor);
	void setBrushStyle(int);

protected:
	void wheelEvent(QGraphicsSceneWheelEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	QWidget *parent;
	MyLayer *pLayer;
	QGraphicsPixmapItem *pItem;

	qreal scale_ratio;    //缩放比
	qreal max_scale_ration;
	qreal min_scale_ration;

	QRect view_scope;    //view范围
	QRect scene_scope;    //scene范围

	QPoint press_point;    //鼠标按下的坐标<int>
	QPoint release_point;    //鼠标释放的坐标<int>
	QPoint latest_inscope_point;    //最近在范围内的点
	bool is_move;    //鼠标的移动状态判定
	
	QImage *canvas;    //保存绘制结果的image
	int tool_type;    //工具类型,1拖动，2直线，3矩形，4椭圆，5多边形，6画笔，7橡皮擦，8填充
	double line_width;    //线宽
	int pen_style;    //线条风格
	int brush_style;    //线条风格
	QColor pen_color;    //图形线条颜色
	QColor brush_color;    //图形填充颜色

};