#include <QApplication>
#include <QtSql>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <Qt>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// Setup db connection
	QSqlDatabase db_conn =
	QSqlDatabase::addDatabase("QMYSQL", "contact_db");
	db_conn.setHostName("127.0.0.1");
	db_conn.setDatabaseName("contact_db");
	db_conn.setUserName("root");
	db_conn.setPassword("");
	db_conn.setPort(3306);
	
	// Error checks
	if (!db_conn.open()) {
		qDebug() << db_conn.lastError(); return 1;
	}
	
	// Use Database model
	enum {
		ID = 0,
		LastName = 1,
		FirstName = 2,
		PhoneNumber = 3,
	};

	QSqlTableModel *contactsTableModel = new QSqlTableModel(0, db_conn);
	contactsTableModel->setTable("contacts");
	contactsTableModel->select();
	contactsTableModel->setHeaderData(ID, Qt::Horizontal, QObject::tr("ID"));
	contactsTableModel->setHeaderData(LastName, Qt::Horizontal, QObject::tr("Last Name"));
	contactsTableModel->setHeaderData(FirstName, Qt::Horizontal, QObject::tr("First Name"));
	contactsTableModel->setHeaderData(PhoneNumber, Qt::Horizontal, QObject::tr("Phone Number"));
	contactsTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Add view
	QTableView *contactsTableView = new QTableView();
	contactsTableView->setModel(contactsTableModel);
	contactsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
	contactsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	QHeaderView *header = contactsTableView->horizontalHeader();
	header->setStretchLastSection(true);

	QWidget window;
	QVBoxLayout *layout = new QVBoxLayout();
	QPushButton *saveToDbPushButton = new QPushButton("Save Changes");
	layout->addWidget(contactsTableView);
	layout->addWidget(saveToDbPushButton);

	QObject::connect(saveToDbPushButton, SIGNAL(clicked()), contactsTableModel, SLOT(submitAll()));
	window.setLayout(layout);
	window.show();
	return app.exec();
}