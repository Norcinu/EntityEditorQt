#include "window.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Window w;
	w.show();
	return a.exec();
}
