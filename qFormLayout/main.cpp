#include <QApplication>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QStringList>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget *window = new QWidget;
	
	QLineEdit *firstNameLineEdit= new QLineEdit;
	QLineEdit *lastNameLineEdit= new QLineEdit;
	
	QSpinBox *ageSpingBox = new QSpinBox;
	
	QComboBox *employmentStatusComboBox= new QComboBox;
	QStringList employmentStatus = {"Unemployed", "Employed", "NA"};
	ageSpingBox->setRange(1, 100);

	employmentStatusComboBox->addItems(employmentStatus);

	QFormLayout *personalInfoformLayout = new QFormLayout;
	personalInfoformLayout->addRow("First Name:", firstNameLineEdit);
	personalInfoformLayout->addRow("Last Name:", lastNameLineEdit );
	personalInfoformLayout->addRow("Age", ageSpingBox);
	personalInfoformLayout->addRow("Employment Status",	employmentStatusComboBox);

	window->setLayout(personalInfoformLayout);
	window->show();
	
	return app.exec();
}