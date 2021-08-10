#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent){
	windowCentralWidget = new QWidget();
	mousePosition = new QLabel("Mouse Position");
	QVBoxLayout *innerLayout = new QVBoxLayout();

	innerLayout->addWidget(mousePosition);
	windowCentralWidget->setLayout(innerLayout);
	setCentralWidget(windowCentralWidget);
	
	statusBar()->showMessage("Ready");
	
	connect(this, SIGNAL(mouseMoved(QPoint)), this, SLOT(updateMousePosition(QPoint)));
}