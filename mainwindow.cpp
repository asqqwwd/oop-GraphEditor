#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	this->is_move = false;
	this->newfile_dialog = nullptr;
	this->pLayer = nullptr;
	this->ui->setupUi(this);

	this->connect(ui->actionNewfile, SIGNAL(triggered()), this, SLOT(createNewFileDialog()));
	this->initWidgetPos();
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
	this->ui->label->setPixmap(QPixmap("3.PNG"));
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
	//pass
}


void MainWindow::createNewFileDialog()
{
	newfile_dialog = new NewFileDialog(this);    //�½��ļ��Ӵ���
	newfile_dialog->setModal(true);
	newfile_dialog->show();
	this->connect(newfile_dialog, SIGNAL(hasCreate(int, int, QString)), this, SLOT(createMainLayer(int, int, QString)));
}

void MainWindow::createMainLayer(int height, int width, QString background)
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
		QListWidgetItem *tmp = new QListWidgetItem();
		QFont font;
		font.setPointSize(10);
		tmp->setFont(font);
		tmp->setText("");
		tmp->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
		ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
		delete ui->listWidget->currentItem();
		ui->listWidget->insertItem(0, tmp);
		pLayer->deleteSlice();

		this->ui->listWidget->setCurrentRow(10 - pLayer->getFocus());
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
