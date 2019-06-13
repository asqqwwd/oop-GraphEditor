#include "file.h"

NewFileDialog::NewFileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
	ui->setupUi(this);
	this->setModal(true);
	connect(ui->okButton, SIGNAL(clicked()), this, SLOT(newfile_okButton_clicked()));
	//connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

MyFile::MyFile(QMenu *menuFile, QMainWindow * parent)
{
	this->parent = parent;
	newfile_dialog = new NewFileDialog();    //新建文件子窗口，暂时隐藏
	newfile_dialog->hide();
	QObject::connect(newfile_dialog, SIGNAL(hasCreate(int, int, QString)), parent, SLOT(createMainLayer(int, int, QString)));
	QObject::connect(this, SIGNAL(saveSignal(QString)), parent, SLOT(saveImage(QString)));

	QAction *newfileAction = new QAction(QString::fromUtf8("NewFile"), parent);//打开动作
	//newfileAction->setIcon(QIcon(""));//图标
	newfileAction->setShortcut(QKeySequence(QString::fromUtf8("Ctrl+N")));//热键
	menuFile->addAction(newfileAction);//添加到工具栏

	QAction *openAction = new QAction(QString::fromUtf8("Open"), parent);//打开动作
	openAction->setIcon(QIcon("Resources/open.png"));//图标
	openAction->setShortcut(QKeySequence(QString::fromUtf8("Ctrl+O")));//热键
	menuFile->addAction(openAction);//添加到工具栏

	QAction *saveAction = new QAction(QString::fromUtf8("Save"), parent);//保存动作
	saveAction->setIcon(QIcon("Resources/save.png"));//图标
	saveAction->setShortcut(QKeySequence(QString::fromUtf8("Ctrl+S")));//热键
	menuFile->addAction(saveAction);//添加到工具栏
	 
	QObject::connect(newfileAction, SIGNAL(triggered()), this, SLOT(createNewFileDialog()));
	QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(savePic()));
	QObject::connect(openAction, SIGNAL(triggered()), this, SLOT(openPic()));
}
