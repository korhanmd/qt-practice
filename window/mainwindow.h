#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QtGui>
#include <QMenuBar>
#include <QMenu>
#include <Qt>
#include <QPushButton>
#include <QToolBar>
#include <QTableView>
#include <QLabel>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <QInputDialog>

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		MainWindow();
	private slots:
		void saveButtonClicked();
		void aboutDialog();
		void clearAllRecords();
		void deleteSavedRecord();
	private:
		QWidget *mainWidget;
		QVBoxLayout *centralWidgetLayout;
		QGridLayout *formLayout;
		QHBoxLayout *buttonsLayout;
		QLabel *nameLabel;
		QLabel *dateOfBirthLabel;
		QLabel *phoneNumberLabel;
		QPushButton *savePushButton;
		QPushButton *clearPushButton;
		QLineEdit *nameLineEdit;
		QDateEdit *dateOfBirthEdit;
		QLineEdit *phoneNumberLineEdit;
		QTableView *appTable;
		QStandardItemModel *model;
		// Menus
		QMenu *fileMenu;
		QMenu *helpMenu;
		// Actions
		QAction *quitAction;
		QAction *aboutAction;
		QAction *saveAction;
		QAction *cancelAction;
		QAction *openAction;
		QAction *newAction;
		QAction *aboutQtAction;
		// Toolbar
		QToolBar *toolbar;
		QAction *newToolBarAction;
		QAction *openToolBarAction;
		QAction *closeToolBarAction;
		QAction *clearToolBarAction;
		QAction *deleteOneEntryToolBarAction;
		// Icons
		QPixmap newIcon;
		QPixmap openIcon;
		QPixmap closeIcon;
		QPixmap clearIcon;
		QPixmap deleteIcon;
		// init methods
		void clearFields();
		void createIcons();
		void createMenuBar();
		void createToolBar();
		void setupSignalsAndSlots();
		void setupCoreWidgets();
};

#endif