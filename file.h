#pragma once
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
		int _height = ui->height_spinBox->value();
		int _width = ui->width_spinBox->value();
		QString _background = ui->background_comboBox->currentText();
		emit hasCreate(_height, _width, _background);    //广播创建完成信号
	}
};
