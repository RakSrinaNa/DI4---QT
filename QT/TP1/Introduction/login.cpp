#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Connection");
}

Login::~Login()
{
    delete ui;
}

void Login::on_okButton_clicked()
{
    QString login = ui->loginEdit->text();
    QString password = ui->passwordEdit->text();

    if(checkLogin(&login, &password))
        accept();
    else{
        ui->passwordEdit->setText("");
        QMessageBox::warning(this, "Error", "Wrong password or login");
    }

}

bool Login::checkLogin(QString *login, QString *password){
    return *login == "Thomas" && *password == "Couchoud";
}
