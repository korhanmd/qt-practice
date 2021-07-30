#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
	
	MainWindow mainWindow;
	mainWindow.show();
	
	return a.exec();
}