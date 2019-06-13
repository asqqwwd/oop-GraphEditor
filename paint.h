#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#ifndef MYPAINT_H 
#define MYPAINT_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QToolBar>
#include <QAction>
#include <QPalette>
#include <QColor>
#include <QMenu>
#include <QFileDialog>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>
#include <QColorDialog>
#include <QDebug>
#include <QFontCombobox>

class MyPaint : public QLabel
{
    Q_OBJECT
public:
    explicit MyPaint(QWidget *parent = 0);
	virtual ~MyPaint();
protected:
    void paintEvent(QPaintEvent *);//重写窗体重绘事件
    //void mousePressEvent(QMouseEvent *);//重写鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *);//重写鼠标释放事件
    void mouseMoveEvent(QMouseEvent *);//重写鼠标移动事件
    void contextMenuEvent(QContextMenuEvent *);//重写菜单事件
    void keyPressEvent(QKeyEvent *e); //重写按键事件
	//void polygon_point_clear();
public:
	QImage *canvas;    //保存绘制结果的image

    int _lpress;//左键按下标志
    int _drag;//拖拽标志
    int _drawType;//描绘类型
    QMenu *_Rmenu;//右键菜单
    QPixmap _pixmap;//画布图片
    QTextEdit *_tEdit;//文本输入框
	QLabel *styleLabel;  //线型风格
	QComboBox *styleComboBox;
	QLabel *widthLabel;    //线宽
	QSpinBox *widthSpinBox;
	QToolButton *colorBtn;  //颜色
	QToolButton *clearBtn;  //清除
	QLabel *fontLabel;  //字体
	QComboBox *fontComboBox;
	QLabel *sizeLabel;   //字号
	QSpinBox *sizeSpinBox;
	QPoint CtrlZPoint;
	int CtrlZCount;

	int style;
	int width;
	QColor color;
	QString font;
	int fontSize;
	bool isDone;
	bool isPolygon;
	bool polygon_rightbutton;
	bool lpress_count;
	unsigned int number[7];//各种图形的索引
	QPoint freePoint;

	void paintLine(QPainter* pp) const;
	void paintCurve(QPainter* pp) const;
	void paintRectangle(QPainter* pp) const;
	void paintEllipse(QPainter* pp) const;
	void paintText(QPainter* pp) const;
	void paintPolygon(QPainter* pp, const int c) const;
	void paintPoints(QPainter* pp, const QVector<QPoint> ppoints)const;
	void set_pen(QPainter* pp,const int c);

public:
    QVector<QVector<QPoint> > _curve;//线条集合(一条线条可包含多个线段)
    QVector<QRect> _rectangle;//矩形集合
    QVector<QRect> _ellipse;//椭圆集合
    QVector<QRect>  _line;//直线集合
    QVector<QString>  _text;//文字集合
    QVector<QPoint>  _tpoint;//文字位置集合
    QVector<int>  _shape;//图形类型集合，用于撤回功能
	QVector<int> _width; //宽度集合
	QVector<int> _style; //线型集合
	QVector<QColor> _color;//颜色集合
	QVector<int> _fontSize;//字号集合
	QVector<QString> _font;//字体集合
    QPoint _begin;//鼠标按下坐标、用于最后一个图形移动
	QVector<QVector<QPoint>> _points;//锚点集合
	QVector<QPoint> _polygon_points;//多边形点集合
	//QVector<QPoint> _point;//锚点
	QVector<QPolygon> _polygon;//多边形集合
	QVector<int> _point_width; //宽度集合
	QVector<QColor> _point_color;//颜色集合
	QVector<int> _polygon_width; //宽度集合
	QVector<QColor> _polygon_color;//颜色集合

signals:

public slots:
    void Curve();
    void Rectangle();
    void Ellipses();
    void Line();
	void Polygon();
    void Texts();//文字
	void setStyle(int);
	void setWidth(int);
	void setColor(QColor);
	void set_font(QString);
	void setFontSize(int);
	void clear();
    void AddTexts();//添加文字
	void showStyle();//显示线型
	void showColor();//调色板
};
#endif // MYPAINT_H
