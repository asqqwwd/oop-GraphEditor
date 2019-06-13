#pragma once
#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QFileDialog>
#include "ui_newfile.h"

class NewFileDialog : public QDialog
{
	Q_OBJECT
public:
	explicit NewFileDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog *ui;

	//----------------------------------------------------------------------------------------//
signals:
	void hasCreate(int, int, QString);    //��������ź�

public slots :
	void newfile_okButton_clicked() {     //�������ļ�
		int _width = ui->width_spinBox->value();
		int _height = ui->height_spinBox->value();
		QString _background = ui->background_comboBox->currentText();
		emit this->hasCreate(_width, _height, _background);    //�㲥��������ź�
	}
};

class MyFile : public QDialog
{
	Q_OBJECT
public:
	MyFile(QMenu *menuFile, QMainWindow *parent);

private:
	QMainWindow *parent;
	NewFileDialog *newfile_dialog;

signals:
	void saveSignal(QString);    //�����ź�

public slots:    //����Ϊpublic
	void createNewFileDialog() {
		newfile_dialog->show();
	}

	void openPic() {    //��ͼƬ
		//�����ļ��򿪶Ի���
		QString pic_path = QFileDialog::getOpenFileName(this, tr("Open"), "", "Image Files(*.jpg *.png *.bmp)");
		if (!pic_path.isEmpty())
		{
			QPixmap tmp(pic_path);
			emit newfile_dialog->hasCreate(tmp.width(), tmp.height(), pic_path);    //�㲥��������ź�
		}
	}

	void savePic() {    //����ͼƬ
		//�����ļ�����Ի���
		QString	file_path = QFileDialog::getSaveFileName(this, tr("Save"), "save.png", "Image (*.jpg *.png *.bmp)");    //����ɼ��������ʽ
		if (file_path.length() > 0)
		{
			emit saveSignal(file_path);
		}
	}
};
