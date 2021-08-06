#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMoveEvent>

class MainWindow: public QMainWindow {
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = 0);
	
	protected:
		void moveEvent(QMoveEvent *event);
};

#endif