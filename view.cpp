#include "view.h"

MyView::MyView(QWidget *parent, MyLayer *layer, QRect scope) : QGraphicsScene(parent)
{
	this->parent = parent;
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

	this->canvas = new QImage(layer->getImageRGB().width(), layer->getImageRGB().height(), QImage::Format_ARGB32);    //ARGB aarrggbb
	this->tool_type = 1;    //��ʼ��Ϊ�϶�
	this->line_width = 3;    //�߿�
	this->pen_style = Qt::SolidLine;
	this->brush_style = Qt::NoBrush;
	this->pen_color = Qt::green;    //����Ϊ��ɫ
	this->brush_color = Qt::gray;    //���Ϊ��ɫ
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
		return QPoint((x - 100 - pLayer->getFocusSlice()->offset_bak[0]) / scale_ratio, (y - 100 - pLayer->getFocusSlice()->offset_bak[1]) / scale_ratio);
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

void MyView::updateCanvas(QPoint end_point)
{
	QPainter pp(canvas);//��canvas��Ϊ����
	pp.setPen(QPen(pen_color, line_width, (Qt::PenStyle)(pen_style)));    //������ɫ
	pp.setBrush(QBrush(brush_color, (Qt::BrushStyle)(brush_style)));    //���
	switch (tool_type)
	{
	case 2:    //ֱ��
		pp.drawLine(press_point, end_point);
		break;
	case 3:    //����
		pp.drawRect(QRect(press_point, end_point));
		break;
	case 4:    //Բ��
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
	if (QApplication::keyboardModifiers() == Qt::ControlModifier && event->delta() > 0) {    //��סctrl+���Ϲ���Ϊ�Ŵ�
		float new_ratio = scale_ratio*1.1;
		if (new_ratio <= max_scale_ration && new_ratio >= min_scale_ration) {
			this->scale_ratio = new_ratio;
		}
	}
	else if(QApplication::keyboardModifiers() == Qt::ControlModifier && event->delta() < 0){    //��סctrl+��������Ϊ��С
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
			this->press_point = convertPixCoordinate(event->scenePos());    ////��scene����ת��Ϊpix����
			latest_inscope_point = press_point;    //һ��Ҫ��ֵΪpress_point
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
		case 1:    //�϶�
			pLayer->changeSliceOffset(latest_inscope_point.x() - press_point.x(), latest_inscope_point.y() - press_point.y());    //����mylayer����ʵ���ƶ�
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
		this->release_point = convertPixCoordinate(event->scenePos());    //��scene����ת��Ϊpix���꣬�����Գ������鷶Χ
		switch (tool_type)
		{
		case 1:    //�϶�
			dx = latest_inscope_point.x() - press_point.x();
			dy = latest_inscope_point.y() - press_point.y();
			pLayer->changeOffsetbak(dx, dy);    //����offset���ݵ�ֵ
			break;
		default:    //������״��updateCanvas���������
			updateCanvas(release_point);
			pLayer->addCanvastoImage(*canvas);
			this->updateItem();
			break;
		}
	}
}
