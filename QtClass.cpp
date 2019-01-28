#include "QtClass.h"
#include <QtMath>

#include <time.h>
#include<iostream>
#include<string>
#include <QMessageBox>
#include <iomanip>


using namespace std;


QtClass::QtClass(QWidget *parent)
	: QWidget(parent) {
}


QtClass::~QtClass()
{
}

void QtClass::newImage(int x, int y) {
	img = new QImage(x, y, QImage::Format_RGB32);
	img->fill(Qt::white);

	update();
}

void QtClass::osi(int sirka, int vyska) {
	QPainter painter(img);

	painter.setPen(QPen(Qt::black, 1));
	painter.drawLine(10, vyska /2, sirka - 10, vyska / 2);
	painter.drawLine(10, 10, 10, vyska - 10);
	painter.drawText(sirka - 10, vyska / 2 - 10, "t");
}

void QtClass::osi2(int sirka, int vyska) {
	QPainter painter(img);

	painter.setPen(QPen(Qt::black, 1));
	painter.drawLine(10, vyska / 2, sirka - 10, vyska / 2);
	painter.drawLine(sirka/2, 10, sirka/2, vyska - 10);
	painter.drawText(sirka / 2+10, 10, "B2");
	painter.drawText(20, vyska / 2 - 10, "B1");
}

void QtClass::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	QRect area = event->rect();
	painter.drawImage(area, *img, area);
}

void QtClass::delenie( int sirka, int vyska) {
	QPainter painter(img);

	painter.setPen(QPen(Qt::black, 1));

	for (int i = 0; i < pocet; i++) {
		painter.drawPoint(10 + i * (sirka - 20) / pocet, vyska /2 + 1);
		painter.drawPoint(10 + i * (sirka - 20) / pocet, vyska /2 - 1);
		points[i] = 10 + i * (sirka - 20) / pocet;
	}
	
}




void QtClass::trajektorie(int volanie, int z){
	
	position[0]=img->height() /2;

	int opakovanie;
	if (volanie == 1) opakovanie = 100;
	if (volanie == 2) opakovanie = 1000;
	if (volanie == 3) opakovanie = 10000;

	for (int j = 1; j <= opakovanie; j++) {
		for (int i = 1; i <= pocet; i++) {
			static const double epsilon = std::numeric_limits<double>::min();

			thread_local double z1;
			thread_local bool generate;
			generate = !generate;

			if (!generate)
				position[i] = position[i - 1] - (z1 * standard_deviation + mean);

			double u1, u2;
			do {
				u1 = ((double)rand() / RAND_MAX);
				u2 = ((double)rand() / RAND_MAX);
			} while (u1 <= epsilon);

			double z0;
			z0 = sqrt(-300.0 * log(u1)) * cos(2 * M_PI* u2);
			z1 = sqrt(-300.0 * log(u1)) * sin(2 * M_PI * u2);
			position[i] = position[i - 1] -(z0 * standard_deviation + mean);

		}

		if(z==1) kresli1();
		
		if(z==0) kresli2();
		
	}
	if (z == 1) {
		if (volanie == 1)  cout << "Pravdepodobnost nastatia je:  " << d<< "/" << 100 << "\n";
		if (volanie == 2)  cout << "Pravdepodobnost nastatia je:  " << d << "/" << 1000 << "\n";
		if (volanie == 3)  cout << "Pravdepodobnost nastatia je:  " << d << "/" << 10000 << "\n";
	}
}

void QtClass::kresli1() {
	QPainter painter(img);
	
	if (position[1] < (img->height() / 2) && position[2] <(img->height() / 2) && position[1] > position[2]) {
		for (int j = 1; j < pocet; j++) {
			painter.setPen(QPen(Qt::red, 2));
			painter.drawLine(points[j - 1], position[j - 1], points[j], position[j]);
		}

		d++;
	}
	else {
		for (int j = 1; j < pocet; j++) {
			painter.setPen(QPen(Qt::black, 1));
			painter.drawLine(points[j - 1], position[j - 1], points[j], position[j]);
		}
	}
}


void QtClass::kresli2() {
	QPainter painter(img);
	
	if (position[1] < (img->height() / 2) && position[2] <(img->height() / 2) && position[1] > position[2]) {
		painter.setPen(QPen(Qt::red, 2));
		painter.drawEllipse(QPointF((position[1]- img->height() / 2 + img->width() / 2), position[2]), 1, 1);
		//painter.drawEllipse(QPointF((position[2] - img->height() / 2 + img->width() / 2), position[1]), 1, 1);
	
	}
	else {
		painter.setPen(QPen(Qt::black, 2));
		painter.drawEllipse(QPointF((position[1]- img->height() / 2+ img->width() / 2), position[2]), 1, 1);
		//painter.drawEllipse(QPointF((position[2] - img->height() / 2 + img->width() / 2), position[1]), 1, 1);
	}
	
			
	
}
