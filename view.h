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
	
	void updateItem();    //����Item
	qreal getScaleRatio();    //��ȡ��ǰ���ű�
	QPoint convertPixCoordinate(QPointF);    //������pt��ת��Ϊͼ���е���������λ��
	bool isInItemScope(QPointF);    //�ж��Ƿ���Item��Χ��

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

	qreal scale_ratio;    //���ű�
	qreal max_scale_ration;
	qreal min_scale_ration;

	QRect view_scope;    //view��Χ
	QRect scene_scope;    //scene��Χ

	QPoint press_point;    //��갴�µ�����<int>
	QPoint release_point;    //����ͷŵ�����<int>
	QPoint latest_inscope_point;    //����ڷ�Χ�ڵĵ�
	bool is_move;    //�����ƶ�״̬�ж�
	
	QImage *canvas;    //������ƽ����image
	int tool_type;    //��������,1�϶���2ֱ�ߣ�3���Σ�4��Բ��5����Σ�6���ʣ�7��Ƥ����8���
	double line_width;    //�߿�
	int pen_style;    //�������
	int brush_style;    //�������
	QColor pen_color;    //ͼ��������ɫ
	QColor brush_color;    //ͼ�������ɫ

};