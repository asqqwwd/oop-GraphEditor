#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDesktopWidget>
#include "ui_mainwindow.h"
#include "file.h"
#include "layer.h"
#include "view.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = Q_NULLPTR);
	void initWidgetPos();    //��ʼ���ؼ�λ��
	void initTools();    //��ʼ��������

protected:
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	Ui::MainWindow *ui;    //������ʼui����һ���ô���ʵ������
	MyFile *pFile;    //�ļ���
	MyLayer *pLayer;    //��ͼ����
	MyView *pView;    //�ӿ���
	QMenu *Rmenu;    //�Ҽ��˵�

	QPoint press_point;    //��갴�µ�����<int>
	QPoint release_point;    //����ͷŵ�����<int>
	bool is_move;    //�����ƶ�״̬�ж�

//----------------------------------------------------------------------------------------//
public slots :    //����Ϊpublic
	void createMainLayer(int width, int height, QString background);    //OK��ť���º󴴽���ͼ�����
	void updateLayerInfo(int currentRow);    //ͼ�����ѡ�����ı�ʱ��Ӧ�Ĳۺ���
	void addSlice();    //�ӺŶ�Ӧ�Ĳۺ����������½�һ��
	void removeSlice();    //���Ŷ�Ӧ�Ĳۺ���������ɾ��һ��
	void changeOpacity(int value);    //slider��Ӧ�Ĳۺ��������ڸı佹��ͼ���͸����
	void changeVisible(bool tar);    //radio��Ӧ�Ĳۺ��������ڸı���ӻ�

	void saveImage(QString file_path = nullptr);    //�����ļ�����Ӧ����
	void changeToolTypetoMove();    //��ť����Ӧ���������������͸�Ϊץ��
	void changeToolTypetoLine();
	void changeToolTypetoRectangle();
	void changeToolTypetoCircle();

	void setLineWidth(double li);    //���û���ͼ���߿����Ӧ����
	void setLineColor();    //���û���ͼ��������ɫ
	void setFillColor();    //���û���ͼ�������ɫ
	void setLineStyle(const QString st);     //���û���ͼ���������
	void setFillStyle(const QString st);    //���û���ͼ�������
};

