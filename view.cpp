#include "view.h"

MyView::MyView(QWidget *parent, MyLayer *layer, QRect scope) : QGraphicsScene(parent)
{
	this->pLayer = layer;
	this->view_scope = QRect(scope.width() / 2 - 600, scope.height() / 2 - 800, 1200, 900);    //�޹ؽ�Ҫ
	this->scene_scope = QRect(0, 0, layer->getImageRGB().width() + 200, layer->getImageRGB().height() + 200);

	this->pItem = new QGraphicsPixmapItem();
	this->pItem->setPixmap(pLayer->getImageRGB());
	this->pItem->setOffset(100, 100);    //������scene�߿��Ϊ100
	this->addItem(pItem);
	this->setSceneRect(scene_scope);
	//pItem->setFlag(QGraphicsPixmapItem::ItemIsSelectable);    //����item����ѡȡ
	
	this->scale_ratio = 1.0;    //1����ԭʼ��С
	this->max_scale_ration = 4.0;    //���Ŵ�4��
	this->min_scale_ration = 0.25;    //������С��4��
}

void MyView::updateItem()
{
	int image_width = pLayer->getImageRGB().width()*scale_ratio;
	int image_height = pLayer->getImageRGB().height()*scale_ratio;
	this->scene_scope = QRect(0, 0, image_width + 200, image_height + 200);
	this->pItem->setPixmap(pLayer->getImageRGB().scaled(image_width, image_height));
	this->setSceneRect(scene_scope);
}

qreal MyView::getScaleRatio()
{
	return this->scale_ratio;
}

QPoint MyView::convertPixCoordinate(QPointF pt)
{
	int x = pt.x();
	int y = pt.y();
	if (isInItemScope(pt)) {    //�ڷ�Χ����
		return QPoint((x - 100) / scale_ratio, (y - 100) / scale_ratio);
	}
	else {    //�ڷ�Χ����
		//x�����߽�
		if (x >= scene_scope.width() - 100) {    
			x = scene_scope.width();
		}
		else if (x < 100) {
			x = 0;
		}
		//y�����߽�
		if (y >= scene_scope.height() - 100) {   
			y = scene_scope.height();
		}
		else if (y < 100) {
			y = 0;
		}
		return QPoint(x, y);
	}
	
}

bool MyView::isInItemScope(QPointF pt)
{
	int x = pt.x();
	int y = pt.y();
	if (x >= 100 && x < scene_scope.width() - 100 && y >= 100 && y < scene_scope.height() - 100) {
		return true;
	}
	else {
		return false;
	}
}

void MyView::wheelEvent(QGraphicsSceneWheelEvent * event)
{
	if (event->delta() > 0) {    //���Ϲ���Ϊ�Ŵ�
		float new_ratio = scale_ratio*1.1;
		if (new_ratio <= max_scale_ration && new_ratio >= min_scale_ration) {
			this->scale_ratio = new_ratio;
		}
	}
	else {    //��������Ϊ��С
		float new_ratio = scale_ratio/1.1;
		if (new_ratio <= max_scale_ration && new_ratio >= min_scale_ration) {
			this->scale_ratio = new_ratio;
		}
	}
	this->updateItem();
}

void MyView::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if (event->button() == Qt::LeftButton && isInItemScope(event->scenePos())) {
		this->is_move = true;
		this->press_point = convertPixCoordinate(event->scenePos());    ////��scene����ת��Ϊpix����
		latest_inscope_point = press_point;    //һ��Ҫ��ֵΪpress_point
	}
}

void MyView::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	if (this->is_move == true && isInItemScope(event->scenePos())) {
		//int dx = (event->scenePos().x() - event->lastScenePos().x())/scale_ratio;    //���ַ���ƽ�Ʋ�׼ȷ
		//int dy = (event->scenePos().y() - event->lastScenePos().y())/scale_ratio;
		latest_inscope_point = convertPixCoordinate(event->scenePos());
		pLayer->changeSliceOffset(latest_inscope_point.x() - press_point.x(), latest_inscope_point.y() - press_point.y());    //����mylayer����ʵ���ƶ�
		this->updateItem();
	}
}

void MyView::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	if (this->is_move == true) {
		this->is_move = false;
		this->release_point = convertPixCoordinate(event->scenePos());    //��scene����ת��Ϊpix���꣬�����Գ������鷶Χ
		int dx = latest_inscope_point.x() - press_point.x();
		int dy = latest_inscope_point.y() - press_point.y();
		pLayer->changeOffsetbak(dx, dy);    //����offset���ݵ�ֵ
	}
}
