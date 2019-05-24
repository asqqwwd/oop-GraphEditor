#include "view.h"

MyView::MyView(QWidget *parent, MyLayer *layer, QRect scope) : QGraphicsScene(parent)
{
	this->pLayer = layer;
	this->view_scope = QRect(scope.width() / 2 - 600, scope.height() / 2 - 800, 1200, 900);    //无关紧要
	this->scene_scope = QRect(0, 0, layer->getImageRGB().width() + 200, layer->getImageRGB().height() + 200);

	this->pItem = new QGraphicsPixmapItem();
	this->pItem->setPixmap(pLayer->getImageRGB());
	this->pItem->setOffset(100, 100);    //设置与scene边框距为100
	this->addItem(pItem);
	this->setSceneRect(scene_scope);
	//pItem->setFlag(QGraphicsPixmapItem::ItemIsSelectable);    //设置item可以选取
	
	this->scale_ratio = 1.0;    //1代表原始大小
	this->max_scale_ration = 4.0;    //最大放大到4倍
	this->min_scale_ration = 0.25;    //最下缩小到4倍
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
	if (isInItemScope(pt)) {    //在范围以内
		return QPoint((x - 100) / scale_ratio, (y - 100) / scale_ratio);
	}
	else {    //在范围以外
		//x超出边界
		if (x >= scene_scope.width() - 100) {    
			x = scene_scope.width();
		}
		else if (x < 100) {
			x = 0;
		}
		//y超出边界
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
	if (event->delta() > 0) {    //向上滚动为放大
		float new_ratio = scale_ratio*1.1;
		if (new_ratio <= max_scale_ration && new_ratio >= min_scale_ration) {
			this->scale_ratio = new_ratio;
		}
	}
	else {    //滚轮向下为缩小
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
		this->press_point = convertPixCoordinate(event->scenePos());    ////将scene坐标转换为pix坐标
		latest_inscope_point = press_point;    //一定要赋值为press_point
	}
}

void MyView::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	if (this->is_move == true && isInItemScope(event->scenePos())) {
		//int dx = (event->scenePos().x() - event->lastScenePos().x())/scale_ratio;    //这种方法平移不准确
		//int dy = (event->scenePos().y() - event->lastScenePos().y())/scale_ratio;
		latest_inscope_point = convertPixCoordinate(event->scenePos());
		pLayer->changeSliceOffset(latest_inscope_point.x() - press_point.x(), latest_inscope_point.y() - press_point.y());    //调用mylayer方法实现移动
		this->updateItem();
	}
}

void MyView::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	if (this->is_move == true) {
		this->is_move = false;
		this->release_point = convertPixCoordinate(event->scenePos());    //将scene坐标转换为pix坐标，不可以超过数组范围
		int dx = latest_inscope_point.x() - press_point.x();
		int dy = latest_inscope_point.y() - press_point.y();
		pLayer->changeOffsetbak(dx, dy);    //更新offset备份的值
	}
}
