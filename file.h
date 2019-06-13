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
	void hasCreate(int, int, QString);    //创建完成信号

public slots :
	void newfile_okButton_clicked() {     //创建新文件
		int _width = ui->width_spinBox->value();
		int _height = ui->height_spinBox->value();
		QString _background = ui->background_comboBox->currentText();
		emit this->hasCreate(_width, _height, _background);    //广播创建完成信号
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
	void saveSignal(QString);    //保存信号

public slots:    //必须为public
	void createNewFileDialog() {
		newfile_dialog->show();
	}

	void openPic() {    //打开图片
		//弹出文件打开对话框
		QString pic_path = QFileDialog::getOpenFileName(this, tr("Open"), "", "Image Files(*.jpg *.png *.bmp)");
		if (!pic_path.isEmpty())
		{
			QPixmap tmp(pic_path);
			emit newfile_dialog->hasCreate(tmp.width(), tmp.height(), pic_path);    //广播创建完成信号
		}
	}

	void savePic() {    //保存图片
		//弹出文件保存对话框
		QString	file_path = QFileDialog::getSaveFileName(this, tr("Save"), "save.png", "Image (*.jpg *.png *.bmp)");    //这里可加入特殊格式
		if (file_path.length() > 0)
		{
			emit saveSignal(file_path);
		}
	}
};
