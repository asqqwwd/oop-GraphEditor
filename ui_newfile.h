/********************************************************************************
** Form generated from reading UI file 'newfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILE_H
#define UI_NEWFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *height_spinBox;
    QSpinBox *width_spinBox;
    QComboBox *background_comboBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 248);
        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(60, 190, 93, 28));
        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 190, 93, 28));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 72, 15));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 90, 72, 15));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 140, 91, 16));
        height_spinBox = new QSpinBox(Dialog);
        height_spinBox->setObjectName(QString::fromUtf8("height_spinBox"));
        height_spinBox->setGeometry(QRect(200, 40, 111, 22));
        height_spinBox->setMinimum(1);
        height_spinBox->setMaximum(900);
        height_spinBox->setValue(300);
        width_spinBox = new QSpinBox(Dialog);
        width_spinBox->setObjectName(QString::fromUtf8("width_spinBox"));
        width_spinBox->setGeometry(QRect(200, 90, 111, 22));
        width_spinBox->setMinimum(1);
        width_spinBox->setMaximum(1000);
        width_spinBox->setValue(400);
        background_comboBox = new QComboBox(Dialog);
        background_comboBox->addItem(QString());
        background_comboBox->addItem(QString());
        background_comboBox->addItem(QString());
        background_comboBox->addItem(QString());
        background_comboBox->setObjectName(QString::fromUtf8("background_comboBox"));
        background_comboBox->setGeometry(QRect(200, 140, 111, 22));
#ifndef QT_NO_SHORTCUT
        label->setBuddy(height_spinBox);
        label_2->setBuddy(width_spinBox);
        label_3->setBuddy(background_comboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        okButton->setText(QApplication::translate("Dialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", nullptr));
        label->setText(QApplication::translate("Dialog", "height:", nullptr));
        label_2->setText(QApplication::translate("Dialog", "width:", nullptr));
        label_3->setText(QApplication::translate("Dialog", "background:", nullptr));
        background_comboBox->setItemText(0, QApplication::translate("Dialog", "Limpid", nullptr));
        background_comboBox->setItemText(1, QApplication::translate("Dialog", "White", nullptr));
        background_comboBox->setItemText(2, QApplication::translate("Dialog", "Black", nullptr));
        background_comboBox->setItemText(3, QApplication::translate("Dialog", "Yellow", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILE_H
