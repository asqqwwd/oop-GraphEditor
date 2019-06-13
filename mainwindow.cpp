#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	this->is_move = false;
	this->pLayer = nullptr;
	this->ui->setupUi(this);

	this->pFile = new MyFile(ui->menuFile, this);    //����File�࣬�����½��ļ����򿪣�����
	this->initWidgetPos();
	this->initTools();
	//setMouseTracking(true);
}

void MainWindow::initWidgetPos()
{
	//��ʼ����ʾ��λ��
	QDesktopWidget *desktop = QApplication::desktop();
	QRect screen = desktop->screenGeometry();
	int screenWidth = screen.width();
	int screenHeight = screen.height() - 100;
	this->ui->gridLayoutWidget->setGeometry(QRect(screenWidth / 2 - 400, screenHeight / 2 - 300, 800, 600));
	//��ʼ��ͼ�����λ��
	this->ui->label->setGeometry(QRect(screenWidth - 350, screenHeight - 450, 234, 395));
	//this->ui->label->setGeometry(QRect(1635, 545, 234, 395));
	this->ui->label->setPixmap(QPixmap("Resources/layerback.PNG"));
	this->ui->formLayoutWidget_2->setGeometry(QRect(screenWidth - 350, screenHeight - 450, 234, 395));

	//ui->listWidget->setViewMode(QListView::IconMode);
	//ui->listWidget->setFlow(QListView::LeftToRight);
	//ui->listWidget->setWrapping(true);

	//ui->listWidget->setSortingEnabled(true);
	//ui->listWidget->sortItems(Qt::DescendingOrder);

	/*QIcon icon;
	icon.addFile(QString::fromUtf8(":/icon/test.PNG"), QSize(), QIcon::Normal, QIcon::Off);
	QBrush brush(QColor(151, 215, 255, 255));
	brush.setStyle(Qt::SolidPattern);*/
}

void MainWindow::initTools()
{
	this->Rmenu = new QMenu(this);    //�����Ҽ��˵�
	this->Rmenu->addAction(tr("Save  \tCtrl+S"), this, SLOT(saveImage(QString)));    //��Ӳ˵�������Ŀǰ�������⣬�޷���Ӧ
	this->Rmenu->addAction(tr("Exit  \tALT+F4"), this, SLOT(close()));    //��Ӳ˵�����
	this->Rmenu->setStyleSheet("background: rgb(180,180,180)");    //���ñ���ɫ
}

void MainWindow::wheelEvent(QWheelEvent * event)
{
	//pass
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
	//pass
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
	//pass
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::RightButton) {
		this->Rmenu->exec(cursor().pos());    //�ڹ��λ�õ����˵�
	}
}


void MainWindow::createMainLayer(int width, int height, QString background)
{
	//����mylayer��ͼ�����
	this->pLayer = new MyLayer(width, height, background);
	//����myview��ʾ��
	this->pView = new MyView(this, pLayer, geometry());
	//�������view�ؼ�
	QGraphicsView *view = new QGraphicsView(pView, this);
	ui->gridLayout->addWidget(view);
	//Ϊ������ӹ���
	this->connect(ui->add_pushButton, SIGNAL(clicked()), this, SLOT(addSlice()));
	this->connect(ui->delete_pushButton, SIGNAL(clicked()), this, SLOT(removeSlice()));
	this->connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(updateLayerInfo(int)));
	this->connect(ui->trans_slider, SIGNAL(sliderMoved(int)), this, SLOT(changeOpacity(int)));
	this->connect(ui->visible_radioButton, SIGNAL(toggled(bool)), this, SLOT(changeVisible(bool)));
	this->connect(ui->mixmode_combox, SIGNAL(toggled(bool)), this, SLOT(changeVisible(bool)));

	this->connect(ui->pushButtonMove, SIGNAL(clicked()), this, SLOT(changeToolTypetoMove()));    //�ı�ѡ������Ϊֱ��
	this->connect(ui->pushButtonDrawLine, SIGNAL(clicked()), this, SLOT(changeToolTypetoLine()));    //�ı�ѡ������Ϊֱ��
	this->connect(ui->pushButtonDrawRectangle, SIGNAL(clicked()), this, SLOT(changeToolTypetoRectangle()));    //�ı�ѡ������Ϊ����
	this->connect(ui->pushButtonDrawCircle, SIGNAL(clicked()), this, SLOT(changeToolTypetoCircle()));    //�ı�ѡ������ΪԲ

	this->connect(ui->doubleSpinBoxLineWidth, SIGNAL(valueChanged(double)), this, SLOT(setLineWidth(double)));    //�߿�ı�
	this->connect(ui->comboBoxLineStyle, SIGNAL(activated(const QString)), this, SLOT(setLineStyle(const QString)));    //���͸ı�
	this->connect(ui->comboBoxFillStyle, SIGNAL(activated(const QString)), this, SLOT(setFillStyle(const QString)));

	ui->toolButtonLineColor->setStyleSheet("background: rgb(0, 255, 0)");
	connect(ui->toolButtonLineColor, SIGNAL(clicked(bool)), this, SLOT(setLineColor()));
	ui->toolButtonFillColor->setStyleSheet("background: rgb(205, 205, 205)");
	connect(ui->toolButtonFillColor, SIGNAL(clicked(bool)), this, SLOT(setFillColor()));


	//��ʼ��ͼ����ʾ��
	for (int k = 0;k <= pLayer->getCountID();k++) {
		this->ui->listWidget->item(10 - k)->setText("Layer" + QString::number(k));
		this->ui->listWidget->item(10 - k)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
	}
	this->ui->listWidget->setCurrentRow(10 - pLayer->getFocus());
	/*QBrush brush(QColor(151, 215, 255, 255));
	brush.setStyle(Qt::SolidPattern);
	this->ui->listWidget->currentItem()->setBackground(brush);*/
}

void MainWindow::updateLayerInfo(int currentRow)
{
	pLayer->setFocus(10 - currentRow);    //���ý��㣬�ؼ�һ��
	ui->mixmode_combox->setCurrentIndex(pLayer->getMixMode());    //��ȡmixmode
	ui->trans_slider->setValue(pLayer->getAlpha());    //��ȡ��͸����
	ui->visible_radioButton->setChecked(pLayer->getVisible());    //��ȡ�ɼ���
}

void MainWindow::addSlice()
{
	QListWidgetItem *tmp = new QListWidgetItem();
	QFont font;
	font.setPointSize(10);
	tmp->setFont(font);
	tmp->setText("Layer" + QString::number(pLayer->getCountID() + 1));
	tmp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
	ui->listWidget->removeItemWidget(ui->listWidget->item(0));
	delete ui->listWidget->item(0);
	ui->listWidget->insertItem(9 - pLayer->getFocus(), tmp);
	pLayer->createSlice();

	ui->listWidget->setCurrentRow(10 - pLayer->getFocus());
	pView->updateItem();
}

void MainWindow::removeSlice()
{
	if (ui->listWidget->row(ui->listWidget->currentItem()) != 10) {    //���һ�в���ɾ��
		pLayer->deleteSlice();
		QListWidgetItem *tmp = new QListWidgetItem();
		QFont font;
		font.setPointSize(10);
		tmp->setFont(font);
		tmp->setText("");
		tmp->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
		ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
		delete ui->listWidget->currentItem();    //focus�����¼�һ��
		ui->listWidget->insertItem(0, tmp);
		
		//this->ui->listWidget->setCurrentRow(10 - pLayer->getFocus());
		pView->updateItem();
	}
	else {
		//������ʾ
		QMessageBox msgBox;
		msgBox.setText("Cannot be deleted!");
		//msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		//msgBox.setDefaultButton(QMessageBox::Save);
		int ret = msgBox.exec();
		//msgBox.show();
	}
}

void MainWindow::changeOpacity(int value)
{
	pLayer->setAlpha(value);
	pView->updateItem();
}

void MainWindow::changeVisible(bool tar)
{
	pLayer->setVisile(tar);
	pView->updateItem();
}

void MainWindow::saveImage(QString file_path)
{
	if (file_path == nullptr) {
		this->pLayer->getImageRGB().save("save.png");
	}
	else {
		this->pLayer->getImageRGB().save(file_path);
	}
}

void MainWindow::changeToolTypetoMove()
{
	this->pView->setToolType(1);
}

void MainWindow::changeToolTypetoLine()
{
	this->pView->setToolType(2);
}

void MainWindow::changeToolTypetoRectangle()
{
	this->pView->setToolType(3);
}

void MainWindow::changeToolTypetoCircle()
{
	this->pView->setToolType(4);
}

void MainWindow::setLineWidth(double li)
{
	this->pView->setLineWidth((qreal)li);
}

void MainWindow::setLineColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
	if (color.isValid())
	{
		this->pView->setPenColor(color);
		QString r_tmp = QString::number(color.red(), 10);
		QString g_tmp = QString::number(color.green(), 10);
		QString b_tmp = QString::number(color.blue(), 10);
		QString tmp("background: rgb(" + r_tmp + ", " + g_tmp + ", " + b_tmp + ")");
		this->ui->toolButtonLineColor->setStyleSheet(tmp);
	}
}

void MainWindow::setFillColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
	if (color.isValid())
	{
		this->pView->setBrushColor(color);
		QString r_tmp = QString::number(color.red(), 10);
		QString g_tmp = QString::number(color.green(), 10);
		QString b_tmp = QString::number(color.blue(), 10);
		QString tmp("background: rgb(" + r_tmp + ", " + g_tmp + ", " + b_tmp + ")");
		this->ui->toolButtonFillColor->setStyleSheet(tmp);
	}
}

void MainWindow::setLineStyle(const QString st)
{
	if (st == "SolidLine") {
		this->pView->setPenStyle(Qt::SolidLine);
	}
	else if (st == "DashLine") {
		this->pView->setPenStyle(Qt::DashLine);
	}
	else if (st == "DotLine") {
		this->pView->setPenStyle(Qt::DotLine);
	}
}

void MainWindow::setFillStyle(const QString st)
{
	if (st == "NoBrush") {
		this->pView->setBrushStyle(Qt::SolidLine);
	}
	else if (st == "Solid") {
		this->pView->setBrushStyle(Qt::SolidPattern);
	}
	else if (st == "Linear") {
		this->pView->setBrushStyle(Qt::LinearGradientPattern);
	}
	else if (st == "Cross") {
		this->pView->setBrushStyle(Qt::CrossPattern);
	}
}
