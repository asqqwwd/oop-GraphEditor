#include "file.h"

NewFileDialog::NewFileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
	ui->setupUi(this);
	connect(ui->okButton, SIGNAL(clicked()), this, SLOT(newfile_okButton_clicked()));
	//connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}
