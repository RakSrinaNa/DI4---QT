#include "Login.h"
#include "ui_Login.h"

extern DBConnect * db;

Login::Login(QWidget * parent) : QDialog (parent), ui(new Ui::Login)
{
    qInfo() << "Opening login dialog";
	ui->setupUi(this);
	this->setWindowTitle("Connection");
}

Login::~Login()
{
    qInfo() << "Destroying login dialog";
	delete ui;
}

void Login::on_okButton_clicked()
{
	QString login = ui->loginEdit->text();
	QString password = ui->passwordEdit->text();
	
	if(db->logUser(login, password))
		accept();
	else //Reset password and display error
	{
		ui->passwordEdit->setText("");
		QMessageBox::warning(this, "Error", "Wrong password or login");
	}
}
