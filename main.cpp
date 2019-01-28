#include "zadanie.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	zadanie w;
	w.show();
	return a.exec();
}
