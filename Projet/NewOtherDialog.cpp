#include "NewOtherDialog.h"
#include "ui_NewOtherDialog.h"

extern DBConnect * db;

NewOtherDialog::NewOtherDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::NewOtherDialog)
{
	ui->setupUi(this);
	ui->firstNameLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-zéè '-]+$"), this));
	ui->lastNameLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-zéè '-]+$"), this));
}

NewOtherDialog::~NewOtherDialog()
{
	delete ui;
}

void NewOtherDialog::upperCase_textEdited(const QString &arg1)
{
	const QString &s = arg1;
	QString cap = s.left(1).toUpper();
	QString text = s.length() > 1 ? s.right(s.length() -1).toLower() : "";
	qobject_cast<QLineEdit *>(sender())->setText(cap + text);
}

void NewOtherDialog::on_firstNameLineEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
}

void NewOtherDialog::on_lastNameLineEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
}

void NewOtherDialog::on_cancelButton_clicked()
{
	reject();
}

void NewOtherDialog::on_okButton_clicked()
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

	if(valid) //If all was ok, we valid the closing
		accept();
}

Staff * NewOtherDialog::getOther()
{
	ResourceType * type = db->getType("Divers");
	return new Staff(ui->lastNameLineEdit->text(), ui->firstNameLineEdit->text(), type->getId(), type->getName());
}
