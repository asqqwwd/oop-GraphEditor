#pragma once
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsItem>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneMouseEvent>
#include "layer.h"

class MyView : public QGraphicsScene
{
public:
	MyView(QWidget *parent, MyLayer *layer, QRect scope);
	
	void updateItem();    //更新Item
	qreal getScaleRatio();    //获取当前缩放比
	QPoint convertPixCoordinate(QPointF pt);    //将给定pt点转化为图层中的像素坐标位置
	bool isInItemScope(QPointF pt);    //判断是否在Item范围内

protected:
	void wheelEvent(QGraphicsSceneWheelEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
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
};