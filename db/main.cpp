#include <QApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[]) {
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
		qDebug() << db_conn.lastError();
		return 1;
	} else {
		qDebug() << "Database connection established !";
	}

	// Create table
	QString table_definition = "use contact_db;\n"
		"CREATE TABLE IF NOT EXISTS contacts (\n"
		"id INT AUTO_INCREMENT,\n"
		"last_name VARCHAR(255) NOT NULL,\n"
		"first_name VARCHAR(255) NOT NULL,\n"
		"phone_number VARCHAR(255) NOT NULL,\n"
		"PRIMARY KEY (id)\n"
		") ENGINE=INNODB;";
	QSqlQuery table_creator(table_definition, db_conn);
}