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
	newfile_dialog = new NewFileDialog();    //�½��ļ��Ӵ��ڣ���ʱ����
	newfile_dialog->hide();
	QObject::connect(newfile_dialog, SIGNAL(hasCreate(int, int, QString)), parent, SLOT(createMainLayer(int, int, QString)));
	QObject::connect(this, SIGNAL(saveSignal(QString)), parent, SLOT(saveImage(QString)));

	QAction *newfileAction = new QAction(QString::fromUtf8("NewFile"), parent);//�򿪶���
	//newfileAction->setIcon(QIcon(""));//ͼ��
	newfileAction->setShortcut(QKeySequence(QString::fromUtf8("Ctrl+N")));//�ȼ�
	menuFile->addAction(newfileAction);//��ӵ�������

	QAction *openAction = new QAction(QString::fromUtf8("Open"), parent);//�򿪶���
	openAction->setIcon(QIcon("Resources/open.png"));//ͼ��
	openAction->setShortcut(QKeySequence(QString::fromUtf8("Ctrl+O")));//�ȼ�
	menuFile->addAction(openAction);//��ӵ�������

	QAction *saveAction = new QAction(QString::fromUtf8("Save"), parent);//���涯��
	saveAction->setIcon(QIcon("Resources/save.png"));//ͼ��
	saveAction->setShortcut(QKeySequence(QString::fromUtf8("Ctrl+S")));//�ȼ�
	menuFile->addAction(saveAction);//��ӵ�������
	 
	QObject::connect(newfileAction, SIGNAL(triggered()), this, SLOT(createNewFileDialog()));
	QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(savePic()));
	QObject::connect(openAction, SIGNAL(triggered()), this, SLOT(openPic()));
}
