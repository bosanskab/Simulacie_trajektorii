#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_zadanie.h"
#include <QDebug>
#include "QtClass.h"

class zadanie : public QMainWindow
{
	Q_OBJECT

public:
	zadanie(QWidget *parent = Q_NULLPTR);
	
	public slots:
	void on_pocitaj_clicked();
private:
	Ui::zadanieClass ui;
	QtClass widget1, widget2, widget3, widget4, widget5, widget6;
	int vyska =490, sirka = 700;
	void osi();
	
};
