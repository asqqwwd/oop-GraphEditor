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
	
	void updateItem();    //����Item
	qreal getScaleRatio();    //��ȡ��ǰ���ű�
	QPoint convertPixCoordinate(QPointF pt);    //������pt��ת��Ϊͼ���е���������λ��
	bool isInItemScope(QPointF pt);    //�ж��Ƿ���Item��Χ��

protected:
	void wheelEvent(QGraphicsSceneWheelEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	MyLayer *pLayer;
	QGraphicsPixmapItem *pItem;

	qreal scale_ratio;    //���ű�
	qreal max_scale_ration;
	qreal min_scale_ration;

	QRect view_scope;    //view��Χ
	QRect scene_scope;    //scene��Χ

	QPoint press_point;    //��갴�µ�����<int>
	QPoint release_point;    //����ͷŵ�����<int>
	QPoint latest_inscope_point;    //����ڷ�Χ�ڵĵ�
	bool is_move;    //�����ƶ�״̬�ж�
};