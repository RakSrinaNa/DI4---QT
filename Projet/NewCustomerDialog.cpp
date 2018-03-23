#include "NewCustomerDialog.h"
#include "ui_NewCustomerDialog.h"

extern DBConnect * db;

NewCustomerDialog::NewCustomerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewCustomerDialog)
{
    qDebug() << "Opening new customer dialog";
	ui->setupUi(this);

	ui->dayOfConsultationDateEdit->setDate(QDate::currentDate());
	ui->priorityComboBox->addItems({"1", "2", "3", "4", "5"});

	ui->firstNameLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-zéè '-]+$"), this));
	ui->lastNameLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-zéè '-]+$"), this));
	ui->addressLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[1-9]\\d* [A-Za-zéè '-]+$"), this));
	ui->cityLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-zéèà '-/]+$"), this));
	ui->postalCodeLineEdit->setValidator(new QIntValidator(1, 99999, this));
	ui->phoneLineEdit->setValidator(new QIntValidator(0, 999999999, this));

	//Add all available resources
	QList<Staff *> * resources = db->getAllStaff();
	for(Staff * s : *resources)
		ui->resourcesListWidget->addItem(new StaffItem(s, ui->resourcesListWidget));

}

NewCustomerDialog::~NewCustomerDialog()
{
    qDebug() << "Destroying new customer dialog";
	delete ui;
}

Customer * NewCustomerDialog::getCustomer()
{
	return new Customer(ui->lastNameLineEdit->text(), ui->firstNameLineEdit->text(), ui->addressLineEdit->text(), ui->cityLineEdit->text(), ui->postalCodeLineEdit->text(), ui->dayOfConsultationDateEdit->date(), ui->durationTimeEdit->time(), ui->priorityComboBox->currentText(), getResources(), ui->commentLineEdit->text() + "\n" + ui->remarqueLineEdit->text(), ui->phoneLineEdit->text());
}

QList<Staff *> * NewCustomerDialog::getResources()
{
	auto * list = new QList<Staff *>;
	for(QListWidgetItem * item : ui->resourcesListWidget->selectedItems())
		*(list) << dynamic_cast<StaffItem *>(item)->getStaff();
	return list;
}

void NewCustomerDialog::upperCase_textEdited(const QString &arg1)
{
	const QString &s = arg1;
	QString cap = s.left(1).toUpper();
	QString text = s.length() > 1 ? s.right(s.length() -1).toLower() : "";
	qobject_cast<QLineEdit *>(sender())->setText(cap + text);
}

void NewCustomerDialog::on_lastNameLineEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
}

void NewCustomerDialog::on_firstNameLineEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
}

void NewCustomerDialog::on_cityLineEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
}

void NewCustomerDialog::on_okButton_clicked()
{
	bool valid = true; //Verify fields
	if(ui->lastNameLineEdit->text().isEmpty())
	{
		valid = false;
		ui->lastNameLineEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->lastNameLineEdit->setStyleSheet("background-color:white;");
	}

	if(ui->firstNameLineEdit->text().isEmpty())
	{
		valid = false;
		ui->firstNameLineEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->firstNameLineEdit->setStyleSheet("background-color:white;");
	}

	if(ui->addressLineEdit->text().isEmpty())
	{
		valid = false;
		ui->addressLineEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->addressLineEdit->setStyleSheet("background-color:white;");
	}

	if(ui->cityLineEdit->text().isEmpty())
	{
		valid = false;
		ui->cityLineEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->cityLineEdit->setStyleSheet("background-color:white;");
	}

	if(ui->postalCodeLineEdit->text().size() != 5)
	{
		valid = false;
		ui->postalCodeLineEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->postalCodeLineEdit->setStyleSheet("background-color:white;");
	}

	if(ui->dayOfConsultationDateEdit->date() < QDate::currentDate() || ui->dayOfConsultationDateEdit->date() > QDate::currentDate().addDays(30))
	{
		valid = false;
		ui->dayOfConsultationDateEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->dayOfConsultationDateEdit->setStyleSheet("background-color:white;");
	}

	if(ui->durationTimeEdit->time().minute() + ui->durationTimeEdit->time().hour() < 1)
	{
		valid = false;
		ui->durationTimeEdit->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->durationTimeEdit->setStyleSheet("background-color:white;");
	}
	if(ui->resourcesListWidget->selectedItems().size() <= 0)
	{
		valid = false;
		ui->resourcesListWidget->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->resourcesListWidget->setStyleSheet("background-color:white;");
	}

	if(valid) //If all was ok, we valid the closing
		accept();
}

void NewCustomerDialog::on_cancelButton_clicked()
{
	reject();
}
