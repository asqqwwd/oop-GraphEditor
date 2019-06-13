#include "view.h"

MyView::MyView(QWidget *parent, MyLayer *layer, QRect scope) : QGraphicsScene(parent)
{
	this->parent = parent;
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

	this->canvas = new QImage(layer->getImageRGB().width(), layer->getImageRGB().height(), QImage::Format_ARGB32);    //ARGB aarrggbb
	this->tool_type = 1;    //初始化为拖动
	this->line_width = 3;    //线宽
	this->pen_style = Qt::SolidLine;
	this->brush_style = Qt::NoBrush;
	this->pen_color = Qt::green;    //线条为绿色
	this->brush_color = Qt::gray;    //填充为灰色
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
		return QPoint((x - 100 - pLayer->getFocusSlice()->offset_bak[0]) / scale_ratio, (y - 100 - pLayer->getFocusSlice()->offset_bak[1]) / scale_ratio);
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

void MyView::updateCanvas(QPoint end_point)
{
	QPainter pp(canvas);//将canvas作为画布
	pp.setPen(QPen(pen_color, line_width, (Qt::PenStyle)(pen_style)));    //线条颜色
	pp.setBrush(QBrush(brush_color, (Qt::BrushStyle)(brush_style)));    //填充
	switch (tool_type)
	{
	case 2:    //直线
		pp.drawLine(press_point, end_point);
		break;
	case 3:    //矩形
		pp.drawRect(QRect(press_point, end_point));
		break;
	case 4:    //圆形
		pp.drawEllipse(QRect(press_point, end_point));
	default:
		break;
	}
	//pp.drawImage(QPoint(0, 0), *canvas);
}

void MyView::setToolType(int t)
{
	this->tool_type = t;
}

void MyView::setLineWidth(int li)
{
	this->line_width = li;
}

void MyView::setPenColor(QColor pc)
{
	this->pen_color = pc;
}

void MyView::setPenStyle(int s)
{
	this->pen_style = s;
}

void MyView::setBrushColor(QColor bc)
{
	this->brush_color = bc;
}

void MyView::setBrushStyle(int s)
{
	this->brush_style = s;
}

void MyView::wheelEvent(QGraphicsSceneWheelEvent * event)
{
	if (QApplication::keyboardModifiers() == Qt::ControlModifier && event->delta() > 0) {    //按住ctrl+向上滚动为放大
		float new_ratio = scale_ratio*1.1;
		if (new_ratio <= max_scale_ration && new_ratio >= min_scale_ration) {
			this->scale_ratio = new_ratio;
		}
	}
	else if(QApplication::keyboardModifiers() == Qt::ControlModifier && event->delta() < 0){    //按住ctrl+滚轮向下为缩小
		float new_ratio = scale_ratio/1.1;
		if (new_ratio <= max_scale_ration && new_ratio >= min_scale_ration) {
			this->scale_ratio = new_ratio;
		}
	}
	else {
		//pass
	}
	this->updateItem();
}

void MyView::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if (isInItemScope(event->scenePos())) {
		switch (event->button())
		{
		case Qt::LeftButton:
			this->canvas->fill(0);
			this->is_move = true;
			this->press_point = convertPixCoordinate(event->scenePos());    ////将scene坐标转换为pix坐标
			latest_inscope_point = press_point;    //一定要赋值为press_point
			break;
		case Qt::RightButton:
			break;
		default:
			break;
		}
	}
}

void MyView::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	if (this->is_move == true && isInItemScope(event->scenePos())) {
		latest_inscope_point = convertPixCoordinate(event->scenePos());
		switch (tool_type)
		{
		case 1:    //拖动
			pLayer->changeSliceOffset(latest_inscope_point.x() - press_point.x(), latest_inscope_point.y() - press_point.y());    //调用mylayer方法实现移动
			this->updateItem();
			break;
		default:
			//updateCanvas(convertPixCoordinate(event->scenePos()));
			break;
		}
	}
}

void MyView::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	if (this->is_move == true) {
		int dx, dy;
		this->is_move = false;
		this->release_point = convertPixCoordinate(event->scenePos());    //将scene坐标转换为pix坐标，不可以超过数组范围
		switch (tool_type)
		{
		case 1:    //拖动
			dx = latest_inscope_point.x() - press_point.x();
			dy = latest_inscope_point.y() - press_point.y();
			pLayer->changeOffsetbak(dx, dy);    //更新offset备份的值
			break;
		default:    //其他形状在updateCanvas函数里绘制
			updateCanvas(release_point);
			pLayer->addCanvastoImage(*canvas);
			this->updateItem();
			break;
		}
	}
}
