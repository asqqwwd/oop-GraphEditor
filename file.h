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
	void hasCreate(int, int, QString);    //��������ź�

public slots :
	void newfile_okButton_clicked() {     //�������ļ�
		int _height = ui->height_spinBox->value();
		int _width = ui->width_spinBox->value();
		QString _background = ui->background_comboBox->currentText();
		emit hasCreate(_height, _width, _background);    //�㲥��������ź�
	}
};
