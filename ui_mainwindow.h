/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
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
    QPushButton *pushButtonDrawLine;
    QPushButton *pushButtonDrawRectangle;
    QPushButton *pushButtonDrawCircle;
    QPushButton *pushButtonMove;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxLineWidth;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBoxLineStyle;
    QLabel *label_10;
    QComboBox *comboBoxFillStyle;
    QToolButton *toolButtonLineColor;
    QToolButton *toolButtonFillColor;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1120, 866);
        actionNewfile = new QAction(MainWindow);
        actionNewfile->setObjectName(QStringLiteral("actionNewfile"));
        actionOpenfile = new QAction(MainWindow);
        actionOpenfile->setObjectName(QStringLiteral("actionOpenfile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(210, 50, 621, 751));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(860, 370, 234, 395));
        formLayout = new QFormLayout(formLayoutWidget_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(7);
        formLayout->setVerticalSpacing(7);
        formLayout->setContentsMargins(10, 10, 0, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
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
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(180, 285));
        listWidget->setMaximumSize(QSize(180, 285));

        horizontalLayout->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        add_pushButton = new QPushButton(formLayoutWidget_2);
        add_pushButton->setObjectName(QStringLiteral("add_pushButton"));
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
        delete_pushButton->setObjectName(QStringLiteral("delete_pushButton"));
        delete_pushButton->setMinimumSize(QSize(25, 25));
        delete_pushButton->setMaximumSize(QSize(25, 25));
        QFont font2;
        font2.setPointSize(19);
        font2.setBold(true);
        font2.setWeight(75);
        delete_pushButton->setFont(font2);

        verticalLayout->addWidget(delete_pushButton);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(25, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(7);
        formLayout_2->setVerticalSpacing(10);
        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        mixmode_combox = new QComboBox(formLayoutWidget_2);
        mixmode_combox->setObjectName(QStringLiteral("mixmode_combox"));
        mixmode_combox->setMinimumSize(QSize(125, 20));
        mixmode_combox->setMaximumSize(QSize(125, 20));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mixmode_combox);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        trans_slider = new QSlider(formLayoutWidget_2);
        trans_slider->setObjectName(QStringLiteral("trans_slider"));
        trans_slider->setMinimumSize(QSize(125, 20));
        trans_slider->setMaximumSize(QSize(125, 20));
        trans_slider->setMaximum(100);
        trans_slider->setValue(100);
        trans_slider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, trans_slider);

        visible_radioButton = new QRadioButton(formLayoutWidget_2);
        visible_radioButton->setObjectName(QStringLiteral("visible_radioButton"));
        visible_radioButton->setCheckable(true);
        visible_radioButton->setChecked(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, visible_radioButton);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_5);


        formLayout->setLayout(0, QFormLayout::SpanningRole, formLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(910, 800, 72, 15));
        pushButtonDrawLine = new QPushButton(centralwidget);
        pushButtonDrawLine->setObjectName(QStringLiteral("pushButtonDrawLine"));
        pushButtonDrawLine->setGeometry(QRect(30, 130, 93, 28));
        pushButtonDrawRectangle = new QPushButton(centralwidget);
        pushButtonDrawRectangle->setObjectName(QStringLiteral("pushButtonDrawRectangle"));
        pushButtonDrawRectangle->setGeometry(QRect(30, 190, 93, 28));
        pushButtonDrawCircle = new QPushButton(centralwidget);
        pushButtonDrawCircle->setObjectName(QStringLiteral("pushButtonDrawCircle"));
        pushButtonDrawCircle->setGeometry(QRect(30, 250, 93, 28));
        pushButtonMove = new QPushButton(centralwidget);
        pushButtonMove->setObjectName(QStringLiteral("pushButtonMove"));
        pushButtonMove->setGeometry(QRect(30, 80, 93, 28));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 10, 91, 21));
        doubleSpinBoxLineWidth = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxLineWidth->setObjectName(QStringLiteral("doubleSpinBoxLineWidth"));
        doubleSpinBoxLineWidth->setGeometry(QRect(140, 10, 70, 22));
        doubleSpinBoxLineWidth->setDecimals(1);
        doubleSpinBoxLineWidth->setMinimum(1);
        doubleSpinBoxLineWidth->setMaximum(10);
        doubleSpinBoxLineWidth->setValue(3);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(250, 10, 101, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(680, 10, 101, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(430, 10, 101, 21));
        comboBoxLineStyle = new QComboBox(centralwidget);
        comboBoxLineStyle->setObjectName(QStringLiteral("comboBoxLineStyle"));
        comboBoxLineStyle->setGeometry(QRect(530, 10, 101, 22));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(860, 10, 101, 21));
        comboBoxFillStyle = new QComboBox(centralwidget);
        comboBoxFillStyle->setObjectName(QStringLiteral("comboBoxFillStyle"));
        comboBoxFillStyle->setGeometry(QRect(980, 10, 111, 22));
        toolButtonLineColor = new QToolButton(centralwidget);
        toolButtonLineColor->setObjectName(QStringLiteral("toolButtonLineColor"));
        toolButtonLineColor->setGeometry(QRect(350, 10, 47, 21));
        toolButtonFillColor = new QToolButton(centralwidget);
        toolButtonFillColor->setObjectName(QStringLiteral("toolButtonFillColor"));
        toolButtonFillColor->setGeometry(QRect(780, 10, 47, 21));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        gridLayoutWidget->raise();
        formLayoutWidget_2->raise();
        pushButtonDrawLine->raise();
        pushButtonDrawRectangle->raise();
        pushButtonDrawCircle->raise();
        pushButtonMove->raise();
        label_6->raise();
        doubleSpinBoxLineWidth->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        comboBoxLineStyle->raise();
        label_10->raise();
        comboBoxFillStyle->raise();
        toolButtonLineColor->raise();
        toolButtonFillColor->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1120, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNewfile->setText(QApplication::translate("MainWindow", "Newfile", Q_NULLPTR));
        actionOpenfile->setText(QApplication::translate("MainWindow", "Openfile", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        listWidget->setSortingEnabled(__sortingEnabled);

        add_pushButton->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        delete_pushButton->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        label_4->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Mix Mode:", Q_NULLPTR));
        mixmode_combox->clear();
        mixmode_combox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Normal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Darken", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Lighten", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Multiply", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Screen", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Overlay", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Difference", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Exclusion", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "Opacity:", Q_NULLPTR));
        visible_radioButton->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Visible:", Q_NULLPTR));
        label->setText(QString());
        pushButtonDrawLine->setText(QApplication::translate("MainWindow", "Line", Q_NULLPTR));
        pushButtonDrawRectangle->setText(QApplication::translate("MainWindow", "Rectangle", Q_NULLPTR));
        pushButtonDrawCircle->setText(QApplication::translate("MainWindow", "Circle", Q_NULLPTR));
        pushButtonMove->setText(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Line Width:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Line Color:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Fill Color:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Line Style:", Q_NULLPTR));
        comboBoxLineStyle->clear();
        comboBoxLineStyle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SolidLine", Q_NULLPTR)
         << QApplication::translate("MainWindow", "DashLine", Q_NULLPTR)
         << QApplication::translate("MainWindow", "DotLine", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("MainWindow", "Fill Style:", Q_NULLPTR));
        comboBoxFillStyle->clear();
        comboBoxFillStyle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NoBrush", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Solid", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Linear", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cross", Q_NULLPTR)
        );
        toolButtonLineColor->setText(QString());
        toolButtonFillColor->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
