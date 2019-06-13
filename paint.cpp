#include "paint.h"

MyPaint::MyPaint(QWidget *parent) :
    QLabel(parent)
{
     _lpress = false;//初始鼠标左键未按下
	 lpress_count = true;
     _drawType = 0;//初始为什么都不画
     _drag = 0;//默认非拖拽模式
	 isDone = false;
	 polygon_rightbutton = false;
     _begin = pos();//拖拽的参考坐标，方便计算位移
     _tEdit = new QTextEdit(this);//初始化文本输入框
     _tEdit->hide();//隐藏
     this->setGeometry(350,200,600,400);//设置窗体大小、位置
     setMouseTracking(true);//开启鼠标实时追踪，监听鼠标移动事件，默认只有按下时才监听
     //设置背景黑色
     //方法一
//     QPalette palt(this->palette());
//     palt.setColor(QPalette::Background, Qt::white);
//     this->setAutoFillBackground(true);
//     this->setPalette(palt);
     //方法二
       this->setStyleSheet("background-color:white;");

    //创建工具栏
    QToolBar *tbar = addToolBar(tr("工具栏"));
    tbar->setMovable(false);//工具栏不可移动
    tbar->setIconSize(QSize(16, 16));//设置动作图标的尺寸
    tbar->setStyleSheet("background-color:rgb(199,237,204)");//背景色

    _Rmenu = new QMenu(this);//创建右键菜单
    _Rmenu->addAction(tr("Save  \tCtrl+S"), this, SLOT(SavePic()));//添加菜单动作
    _Rmenu->addAction(tr("Exit  \tALT+F4"), this, SLOT(close()));//添加菜单动作
    _Rmenu->setStyleSheet("background-color:rgb(199,237,204)");//设置背景色

    QAction *openAction = new QAction(tr("Open"), this);//打开动作
    openAction->setIcon(QIcon(":/png/images/open.png"));//图标
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));//热键
    tbar->addAction(openAction);//添加到工具栏

    QAction *saveAction = new QAction(tr("Save"), this);//保存动作
    saveAction->setIcon(QIcon(":/png/images/save.png"));//图标
    saveAction->setShortcut(QKeySequence(tr("Ctrl+S")));//热键
    tbar->addAction(saveAction);//添加到工具栏

    QAction *saveasAction = new QAction(tr("Save As"), this);//保存动作
    saveasAction->setIcon(QIcon(":/png/images/saveas.png"));//图标
    saveasAction->setShortcut(QKeySequence(tr("Ctrl+ALT+S")));//热键
    tbar->addAction(saveasAction);//添加到工具栏

    QAction *lineAction = new QAction(tr("Line"), this);//直线动作
    lineAction->setIcon(QIcon(":/png/images/line.png"));//图标
    lineAction->setShortcut(QKeySequence(tr("Ctrl+L")));//热键
    tbar->addAction(lineAction);//添加到工具栏

    QAction *curveAction = new QAction(tr("pencil"), this);//铅笔动作
    curveAction->setIcon(QIcon(":/png/images/lines.png"));//图标
    curveAction->setShortcut(QKeySequence(tr("Ctrl+P")));//热键
    tbar->addAction(curveAction);//添加到工具栏

    QAction *rectAction = new QAction(tr("Rectangle"), this);//矩形动作
    rectAction->setIcon(QIcon(":/png/images/rect.png"));//图标
    rectAction->setShortcut(QKeySequence(tr("Ctrl+R")));//热键
    tbar->addAction(rectAction);

    QAction *ellipseAction = new QAction(tr("Ellipse"), this);//椭圆动作
    ellipseAction->setIcon(QIcon(":/png/images/ellipse.png"));//图标
    ellipseAction->setShortcut(QKeySequence(tr("Ctrl+E")));//热键
    tbar->addAction(ellipseAction);

	QAction *polygonAction = new QAction(tr("Polygon"), this);//多边形动作
	polygonAction->setIcon(QIcon(":/png/images/polygon.png"));//图标
	polygonAction->setShortcut(QKeySequence(tr("Ctrl+P")));//热键
	tbar->addAction(polygonAction);

    QAction *textAction = new QAction(tr("Text"), this);//文字动作
    textAction->setIcon(QIcon(":/png/images/texts.png"));//图标
    textAction->setShortcut(QKeySequence(tr("Ctrl+T")));//热键
    tbar->addAction(textAction);

    //连接信号与槽函数
    connect(curveAction, SIGNAL(triggered()), this, SLOT(Curve()));
    connect(rectAction, SIGNAL(triggered()), this, SLOT(Rectangle()));
    connect(ellipseAction, SIGNAL(triggered()), this, SLOT(Ellipses()));
    connect(lineAction, SIGNAL(triggered()), this, SLOT(Line()));
	connect(polygonAction, SIGNAL(triggered()), this, SLOT(Polygon()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(SavePic()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(OpenPic()));
    connect(textAction, SIGNAL(triggered()), this, SLOT(Texts()));
    connect(_tEdit, SIGNAL(textChanged()), this, SLOT(AddTexts()));

	styleLabel = new QLabel(tr("线型风格： "));  //线型风格
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
	styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	styleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	showStyle();
	//setStyle(static_cast<int>(Qt::SolidLine));
	//_style.append(styleComboBox->currentIndex());
	connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(showStyle()));

	widthLabel = new QLabel(tr("线宽：")); //设置笔的线宽
	widthSpinBox = new QSpinBox;
	widthSpinBox->setValue(1);
	//_width.append(1);
	setWidth(1);//初始化线宽为1
	connect(widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));

	fontComboBox = new QFontComboBox(this);
	QFont font(QString::fromLocal8Bit("微软雅黑"), 10);
	fontComboBox->setFont(font);
	fontComboBox->setCurrentText("仿宋");
	set_font("仿宋");//字体初始化为仿宋
	//_font.append("仿宋");
	connect(fontComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(set_font(QString)));

	sizeLabel = new QLabel(tr("字号：")); //设置笔的线宽
	sizeSpinBox = new QSpinBox(this);
	sizeSpinBox->setRange(6, 40);
	sizeSpinBox->setValue(20);
	setFontSize(20);            //默认字号20
	//_fontSize.append(20);
	connect(sizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setFontSize(int)));

	colorBtn = new QToolButton; //设置按钮的格式
	QPixmap pixmap(30, 30);
	pixmap.fill(Qt::black);
	colorBtn->setIcon(QIcon(pixmap));
	connect(colorBtn, SIGNAL(clicked(bool)), this, SLOT(showColor()));

	clearBtn = new QToolButton;
	clearBtn->setText(tr("清除"));
    connect(clearBtn, SIGNAL(clicked(bool)), this, SLOT(clear()));

	tbar->addWidget(styleLabel);
	tbar->addWidget(styleComboBox);
	tbar->addWidget(widthLabel);
	tbar->addWidget(widthSpinBox);
	tbar->addWidget(fontComboBox);
	tbar->addWidget(sizeLabel);
	tbar->addWidget(sizeSpinBox);
	tbar->addWidget(colorBtn);
	tbar->addWidget(clearBtn);
}

MyPaint::~MyPaint()
{
	delete _tEdit;
	delete _Rmenu;
}
void MyPaint::paintEvent(QPaintEvent *)
{
    //QPixmap pix = _pixmap;//以_pixmap作为画布
    QPainter p(canvas);//将canvas作为画布
	for (int i = 0; i < 7; i++)
	{
		number[i] = 0;
	}
    for(int c = 0;c<_shape.size(); c++)//控制用户当前所绘图形总数
    {
		set_pen(&p, c);
		switch (_shape.at(c))
		{  
		   case 1:
			   paintCurve(&p); number[1]++; break;
		   case 2:
			   paintRectangle(&p); number[2]++; break;
		   case 3:
			   paintEllipse(&p); number[3]++; break;
		   case 4:
			   paintLine(&p); number[4]++; break;
		   case 5:
			   paintText(&p); number[5]++; break;
		   case 6:
			   { 
			       int k = 0;
				   for (int j = 0; j < c; j++)
				   {
					   if (_shape.at(j) == 6)
					   {
						   set_pen(&p, j);
						   paintPolygon(&p, k++);
					   }
				   }
			   }
			   if (!isDone)
			   {
					/*int k = 0;
					for (int j = 0; j < c; j++)
					{
						if (_shape.at(j) == 6)
						{
							set_pen(&p, j);
							paintPolygon(&p, k++);
							//paintPolygon(&p, _points.at(k));
							//paintPoints(&p, _points.at(k));
							//k++;
						}
					}*/
				  // p.setPen(QPen(Qt::green, 20));
				   //p.drawPoint(40, 40);
				    paintPoints(&p, _polygon_points);
			   }
			   else
			   {
				   //paintPolygon(&p, _polygon_points);
				   //p.drawPolygon(_polygon.at(number[6]));
				   //paintPoints(&p, _polygon_points);
				   set_pen(&p, c);
				   paintPolygon(&p, number[6]);
				   _polygon_points.clear();
				   //lpress_count = true;
			   }
			   
			   number[6]++; 
			   break;
		   default:
			   break;
		}
    }
    p.end();
    p.begin(this);//将当前窗体作为画布
	p.drawImage(QPoint(0, 0), *canvas);
    //p.drawPixmap(0,0, pix);//将pixmap画到窗体
}

void MyPaint::set_pen(QPainter* pp, const int c)
{
	switch (_shape.at(c))
	{
	  case 1:
	  case 2:
	  case 3:
	  case 4:
	  case 6:
		  pp->setPen(QPen(_color.at(c), _width.at(c), (Qt::PenStyle)(_style.at(c))));
		  pp->setBrush(QBrush(Qt::green, Qt::SolidPattern));
		  return;
	  case 5:
		  //pp->setBrush(QBrush(Qt::green, Qt::SolidPattern));
		  if (c != _shape.size() - 1)
		  {
			  if (c == 0)
			  {
				  pp->setPen(QPen(_color.at(c), _width.at(c), (Qt::PenStyle)(_style.at(c))));
				  pp->setFont(QFont(_font.at(c), _fontSize.at(c)));
				  //pp->setBrush(QBrush(Qt::green, Qt::SolidPattern));
			  }
			  else
			  {
				  pp->setPen(QPen(_color.at(c + 1), _width.at(c + 1), (Qt::PenStyle)(_style.at(c + 1))));
				  pp->setFont(QFont(_font.at(c + 1), _fontSize.at(c + 1)));
			  }
		  }
		  else {
			  pp->setPen(QPen(_color.at(c), _width.at(c), (Qt::PenStyle)(_style.at(c))));
			  pp->setFont(QFont(_font.at(c), _fontSize.at(c)));
		  }
	  default: break;
	}
}

void MyPaint::paintPoints(QPainter* pp,const QVector<QPoint> ppoints) const
{
	pp->setPen(QPen(Qt::red, 5));//设置锚点
	//pp->setBrush(QBrush(Qt::green, Qt::SolidPattern));
	for (int i = 0; i < ppoints.size(); i++)
		pp->drawPoint(ppoints.at(i));
}

void MyPaint::paintCurve(QPainter* pp) const
{
	const QVector<QPoint> line = _curve.at(number[1]);//取出一条线条
	for (int j = 0; j < line.size() - 1; j++)//将线条的所有线段描绘出
	{
		pp->drawLine(line.at(j), line.at(j + 1));
	}
}

void MyPaint::paintRectangle(QPainter* pp) const
{
	pp->drawRect(_rectangle.at(number[2]));
	
}
void MyPaint::paintEllipse(QPainter* pp) const
{
	pp->drawEllipse(_ellipse.at(number[3]));
}
void MyPaint::paintLine(QPainter* pp) const
{
	pp->drawLine(_line.at(number[4]).topLeft(), _line.at(number[4]).bottomRight());

}
void MyPaint::paintText(QPainter* pp) const
{
	pp->drawText(_tpoint.at(number[5]), _text.at(number[5]));

}
void MyPaint::paintPolygon(QPainter* pp,const int c) const
{
	/*for (int i = 0; i < ppoints.size() - 1; i++)
		pp->drawLine(ppoints[i], ppoints[i + 1]);
	pp->drawLine(ppoints.back(), ppoints.front());*/
	pp->drawPolygon(_polygon.at(c));
	paintPoints(pp, _points.at(c));
}

void MyPaint::AddTexts()//当输入框文本改变时调用
{
	QString& last = _text.last();//拿到最后一个文本
	last = _tEdit->toPlainText();//将输入框文本作为文本
}

void MyPaint::mouseMoveEvent(QMouseEvent *e)
{
	if (_drag && ((_drawType == 2 && _rectangle.last().contains(e->pos()))
		|| (_drawType == 3 && _ellipse.last().contains(e->pos()))))
	{
		setCursor(Qt::SizeAllCursor);//拖拽模式下，并且在拖拽图形中，将光标形状改为十字
	}
	else
	{
		setCursor(Qt::ArrowCursor);//恢复原始光标形状
		_drag = 0;
	}

	if (_lpress)
	{
		if (_drawType == 1)//铅笔画线
		{
			if (_curve.size() <= 0) return;//线条集合为空，不画线
			QVector<QPoint>& lastLine = _curve.last();//最后添加的线条，就是最新画的
			lastLine.append(e->pos());//记录鼠标的坐标(线条的轨迹)
			update();//触发窗体重绘
		}
		else if (_drawType == 2)
		{
			if (_drag == 0)//非拖拽
			{
				QRect& lastRect = _rectangle.last();//拿到新矩形
				lastRect.setBottomRight(e->pos());//更新矩形的右下角坐标
			}
			else//拖拽模式
			{
				QRect& lastRect = _rectangle.last();//拿到最后添加的矩形
				if (lastRect.contains(e->pos()))//在矩形的内部
				{
					int dx = e->pos().x() - _begin.x();//横向移动x
					int dy = e->pos().y() - _begin.y();//纵向移动y
					lastRect = lastRect.adjusted(dx, dy, dx, dy);//更新矩形的位置
					_begin = e->pos();//刷新拖拽点起始坐标
				}

			}
			update();//触发窗体重绘

		}
		else if (_drawType == 3)
		{
			if (_drag == 0)//非拖拽
			{
				QRect& lastEllipse = _ellipse.last();//拿到新椭圆
				lastEllipse.setBottomRight(e->pos());//更新椭圆的右下角坐标)

			}
			else//拖拽
			{
				QRect& lastEllipse = _ellipse.last();//拿到最后添加的矩形
				if (lastEllipse.contains(e->pos()))//在椭圆内部
				{
					int dx = e->pos().x() - _begin.x();//横向移动x
					int dy = e->pos().y() - _begin.y();//纵向移动y
					lastEllipse = lastEllipse.adjusted(dx, dy, dx, dy);
					_begin = e->pos();//刷新拖拽点起始坐标
				}

			}
			update();//触发窗体重绘
		}
		else if (_drawType == 4)
		{
			QRect& lastLine = _line.last();//拿到新直线
			lastLine.setBottomRight(e->pos());//更新直线另一端)
			update();//触发窗体重绘
		}
	}
}

void MyPaint::mouseReleaseEvent(QMouseEvent *e)
{
	if (_lpress)
	{
		if (_drawType == 1)
		{
			QVector<QPoint>& lastLine = _curve.last();//最后添加的线条，就是最新画的
			lastLine.append(e->pos());//记录线条的结束坐标
			_lpress = false;//标志左键释放
		}
		else if (_drawType == 2)
		{
			QRect& lastRect = _rectangle.last();//拿到新矩形
			if (!_drag)
			{
				lastRect.setBottomRight(e->pos());//不是拖拽时，更新矩形的右下角坐标)
				//刚画完矩形，将光标设置到新矩形的中心位置，并进入拖拽模式
				this->cursor().setPos(this->cursor().pos().x() - lastRect.width() / 2, this->cursor().pos().y() - lastRect.height() / 2);
				_drag = 1;

			}
			_lpress = false;

		}
		else if (_drawType == 3)
		{
			QRect& lastEllipse = _ellipse.last();//拿到新椭圆
			if (!_drag)
			{
				lastEllipse.setBottomRight(e->pos());//不是拖拽时，更新椭圆的右下角坐标)
				//刚画完椭圆，将光标设置到新椭圆的中心位置，并进入拖拽模式
				this->cursor().setPos(this->cursor().pos().x() - lastEllipse.width() / 2, this->cursor().pos().y() - lastEllipse.height() / 2);
				_drag = 1;

			}
			_lpress = false;
		}
		else if (_drawType == 4)
		{
			QRect& lastLine = _line.last();//拿到新矩形
			lastLine.setBottomRight(e->pos());//更新矩形的右下角坐标)
			_lpress = false;
		}
	}
}
void MyPaint::Curve()
{
    _drawType = 1;//铅笔
    _tEdit->hide();//文本框隐藏
}

void MyPaint::Rectangle()
{
    _drawType = 2;//矩形
    _tEdit->hide();

}

void MyPaint::Ellipses()
{
    _drawType = 3;//椭圆
    _tEdit->hide();
}

void MyPaint::Texts()
{
    _drawType = 5;//文字
}

void MyPaint::Line()
{
	_drawType = 4;//直线
	_tEdit->hide();
}
void MyPaint::Polygon()
{
	_drawType = 6;//多边形
	_tEdit->hide();
}

void MyPaint::setStyle(int s)
{
	style = s;
}

void MyPaint::setWidth(int w)
{
	width = w;
}

void MyPaint::setColor(QColor c)
{
	color = c;
}

void MyPaint::set_font(QString f)
{
	font = f;
}

void MyPaint::setFontSize(int s)
{
	fontSize = s;
}

void MyPaint::showColor()
{
	QColor color1 = QColorDialog::getColor(static_cast<int>(Qt::black), this);
	if (color1.isValid())
	{
		this->setColor(color1);
		QPixmap p(20, 20);
		p.fill(color1);
		colorBtn->setIcon(QIcon(p));
	}
}

void MyPaint::showStyle()
{
	this->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
}


void MyPaint::contextMenuEvent(QContextMenuEvent *)  //右键菜单事件
{
    _Rmenu->exec(cursor().pos());//在光标位置弹出菜单
}

void MyPaint::keyPressEvent(QKeyEvent *e) //按键事件
{

	//Ctrl+Z撤销
	this->grabKeyboard();  //keyPressEvent一次响应一个按键事件
	if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_Z)
	{
		//CtrlZPoint = *(new QPoint(_tpoint.back()));
		if (_shape.size() > 0)
		{
			CtrlZCount = 0;
			switch (_shape.last())
			{
			case 1:
				   _curve.pop_back();
				   break;
			case 2:
				   _rectangle.pop_back();
				   break;
			case 3:
				   _ellipse.pop_back();
				   break;
			case 4:
				   _line.pop_back();
				   break;
			case 6:
				 _polygon.pop_back();
				 _points.pop_back();
				 break;
			case 5:
			      if (CtrlZCount++)
				  {
					_text.pop_back();
					_tpoint.pop_back();
					break;
				  }
			}
			_color.pop_back();
			_width.pop_back();
			_style.pop_back();
			_font.pop_back();
			_fontSize.pop_back();
			_shape.pop_back();
			_drag = 0;//设置为非拖拽模式
			update();
		}
	}
	/*else if (_drawType == 5)
	{
		// _tpoint.append(CtrlZPoint);
		CtrlZCount = 0;
		update();//触发窗体重绘
		QPoint p;//鼠标按下，文字开始
		_tpoint.append(p);//将文字坐标添加到文字位置集合
		QPoint& lastp = _tpoint.last();//拿到新文字
		lastp = e->pos();//记录鼠标的坐标
		_tEdit->setGeometry(lastp.x() - 6, lastp.y() - 17, 90, 90);//设置文本框的位置、大小

		//_tpoint.append(CtrlZPoint);
		_tEdit->show();//显示文本输入框
		_text.append("");//添加文本到文本集合
		_tEdit->clear();//因为全局只有一个，所以使用之前要清空
		_shape.append(5);
	}*/
}
void MyPaint::clear()
{
	while (_shape.size())
	{
		_shape.pop_back();
		_width.pop_back();
		_style.pop_back();
		_color.pop_back();
		_font.pop_back();
		_fontSize.pop_back();
	}
	_tEdit->hide();
	update();
}
