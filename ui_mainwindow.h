/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewfile;
    QAction *actionOpenfile;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add_pushButton;
    QPushButton *delete_pushButton;
    QLabel *label_4;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QComboBox *mixmode_combox;
    QLabel *label_3;
    QSlider *trans_slider;
    QRadioButton *visible_radioButton;
    QLabel *label_5;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 866);
        actionNewfile = new QAction(MainWindow);
        actionNewfile->setObjectName(QString::fromUtf8("actionNewfile"));
        actionOpenfile = new QAction(MainWindow);
        actionOpenfile->setObjectName(QString::fromUtf8("actionOpenfile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(90, 50, 741, 751));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(860, 370, 234, 395));
        formLayout = new QFormLayout(formLayoutWidget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(7);
        formLayout->setVerticalSpacing(7);
        formLayout->setContentsMargins(10, 10, 0, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget = new QListWidget(formLayoutWidget_2);
        QFont font;
        font.setPointSize(10);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font);
        __qlistwidgetitem3->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setFont(font);
        __qlistwidgetitem4->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setFont(font);
        __qlistwidgetitem5->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget);
        __qlistwidgetitem6->setFont(font);
        __qlistwidgetitem6->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget);
        __qlistwidgetitem7->setFont(font);
        __qlistwidgetitem7->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(listWidget);
        __qlistwidgetitem8->setFont(font);
        __qlistwidgetitem8->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(listWidget);
        __qlistwidgetitem9->setFont(font);
        __qlistwidgetitem9->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(listWidget);
        __qlistwidgetitem10->setFont(font);
        __qlistwidgetitem10->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(180, 285));
        listWidget->setMaximumSize(QSize(180, 285));

        horizontalLayout->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        add_pushButton = new QPushButton(formLayoutWidget_2);
        add_pushButton->setObjectName(QString::fromUtf8("add_pushButton"));
        add_pushButton->setMinimumSize(QSize(25, 25));
        add_pushButton->setMaximumSize(QSize(25, 25));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        add_pushButton->setFont(font1);
        add_pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(add_pushButton);

        delete_pushButton = new QPushButton(formLayoutWidget_2);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setMinimumSize(QSize(25, 25));
        delete_pushButton->setMaximumSize(QSize(25, 25));
        QFont font2;
        font2.setPointSize(19);
        font2.setBold(true);
        font2.setWeight(75);
        delete_pushButton->setFont(font2);

        verticalLayout->addWidget(delete_pushButton);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(25, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(7);
        formLayout_2->setVerticalSpacing(10);
        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        mixmode_combox = new QComboBox(formLayoutWidget_2);
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->addItem(QString());
        mixmode_combox->setObjectName(QString::fromUtf8("mixmode_combox"));
        mixmode_combox->setMinimumSize(QSize(125, 20));
        mixmode_combox->setMaximumSize(QSize(125, 20));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mixmode_combox);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        trans_slider = new QSlider(formLayoutWidget_2);
        trans_slider->setObjectName(QString::fromUtf8("trans_slider"));
        trans_slider->setMinimumSize(QSize(125, 20));
        trans_slider->setMaximumSize(QSize(125, 20));
        trans_slider->setMaximum(100);
        trans_slider->setValue(0);
        trans_slider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, trans_slider);

        visible_radioButton = new QRadioButton(formLayoutWidget_2);
        visible_radioButton->setObjectName(QString::fromUtf8("visible_radioButton"));
        visible_radioButton->setCheckable(true);
        visible_radioButton->setChecked(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, visible_radioButton);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_5);


        formLayout->setLayout(0, QFormLayout::SpanningRole, formLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(910, 800, 72, 15));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        gridLayoutWidget->raise();
        formLayoutWidget_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1120, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNewfile);
        menuFile->addAction(actionOpenfile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNewfile->setText(QApplication::translate("MainWindow", "Newfile", nullptr));
        actionOpenfile->setText(QApplication::translate("MainWindow", "Openfile", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        listWidget->setSortingEnabled(__sortingEnabled);

        add_pushButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        delete_pushButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_4->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Mix Mode:", nullptr));
        mixmode_combox->setItemText(0, QApplication::translate("MainWindow", "Normal", nullptr));
        mixmode_combox->setItemText(1, QApplication::translate("MainWindow", "Darken", nullptr));
        mixmode_combox->setItemText(2, QApplication::translate("MainWindow", "Lighten", nullptr));
        mixmode_combox->setItemText(3, QApplication::translate("MainWindow", "Multiply", nullptr));
        mixmode_combox->setItemText(4, QApplication::translate("MainWindow", "Screen", nullptr));
        mixmode_combox->setItemText(5, QApplication::translate("MainWindow", "Overlay", nullptr));
        mixmode_combox->setItemText(6, QApplication::translate("MainWindow", "Difference", nullptr));
        mixmode_combox->setItemText(7, QApplication::translate("MainWindow", "Exclusion", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "Opacity:", nullptr));
        visible_radioButton->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Visible:", nullptr));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
