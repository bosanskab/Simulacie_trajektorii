#pragma once

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QtWidgets>

class QtClass : public QWidget
{
	Q_OBJECT

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
public:
	QtClass(QWidget *parent = Q_NULLPTR);
	~QtClass();
	
	int pocet=100;
	float points[100];
	float position[100];
	int dobre_trajektorie[3];
	int d=0;

	float mean=0; //stredna hodnota
	float standard_deviation=1;  //rozptyl
	void newImage(int x, int y);
	void osi(int vyska, int sirka);
	void osi2(int vyska, int sirka);
	QImage *img;
	void delenie( int vyska, int sirka);
	void trajektorie(int volanie, int z);
	void kresli1();
	void kresli2();

};

