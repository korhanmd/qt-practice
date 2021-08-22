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
		
	for (int i = 0; i < contactsTableModel->rowCount(); ++i) {
		QSqlRecord record = contactsTableModel->record(i);
		QString id = record.value("id").toString();
		QString last_name = record.value("last_name").toString();
		QString first_name = record.value("first_name").toString();
		QString phone_number = record.value("phone_number").toString();
		qDebug() << id << " : " << first_name << " : " << last_name << " : " << phone_number;
	}

	// Insert Row
	int row = contactsTableModel->rowCount();
	contactsTableModel->insertRows(row, 1);
	contactsTableModel->setData(contactsTableModel->index(row, 1), "Stokes");
	contactsTableModel->setData(contactsTableModel->index(row, 2), "Nick");
	contactsTableModel->setData(contactsTableModel->index(row, 3), "+443569948");
	contactsTableModel->submitAll();

	// Custom filter
	qDebug() << "\nCustom filter: \n";
	contactsTableModel->setFilter("id=12 AND last_name like'Stokes'");
	contactsTableModel->select();
	for (int i = 0; i < contactsTableModel->rowCount(); ++i) {
		QSqlRecord record = contactsTableModel->record(i);
		QString id = record.value("id").toString();
		QString last_name = record.value("last_name").toString();
		QString first_name = record.value("first_name").toString();
		QString phone_number = record.value("phone_number").toString();
		qDebug() << id << " : " << first_name << " : " << last_name << " : " << phone_number;
	}
}