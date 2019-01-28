#include "zadanie.h"
#include<iostream>
#include<string>

using namespace std;

zadanie::zadanie(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.t_100->setWidget(&this->widget1);
	ui.t_100->setBackgroundRole(QPalette::Dark);

	ui.t_1000->setWidget(&this->widget2);
	ui.t_1000->setBackgroundRole(QPalette::Dark);

	ui.t_10000->setWidget(&this->widget3);
	ui.t_10000->setBackgroundRole(QPalette::Dark);

	ui.t_1->setWidget(&this->widget4);
	ui.t_1->setBackgroundRole(QPalette::Dark);

	ui.t_2->setWidget(&this->widget5);
	ui.t_2->setBackgroundRole(QPalette::Dark);

	ui.t_3->setWidget(&this->widget6);
	ui.t_3->setBackgroundRole(QPalette::Dark);

	osi();
}

void zadanie::osi() {
	widget1.newImage(sirka, vyska);
	widget1.osi(sirka, vyska);
	widget2.newImage(sirka, vyska);
	widget2.osi(sirka, vyska);
	widget3.newImage(sirka, vyska);
	widget3.osi(sirka, vyska);
	widget4.newImage(sirka, vyska);
	widget4.osi2(sirka, vyska);
	widget5.newImage(sirka, vyska);
	widget5.osi2(sirka, vyska);
	widget6.newImage(sirka, vyska);
	widget6.osi2(sirka, vyska);
}


void zadanie::on_pocitaj_clicked(){
	osi();

	int pocet =100;
	widget1.delenie(sirka, vyska);
	widget2.delenie(sirka, vyska);
	widget3.delenie(sirka, vyska);


	
	widget1.trajektorie(1,1);
	widget2.trajektorie(2,1);
	widget3.trajektorie(3,1);


	widget4.trajektorie(1,0);
	widget5.trajektorie(2,0);
	widget6.trajektorie(3,0);

}

