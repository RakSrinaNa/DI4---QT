#include "newstaffdialog.h"
#include "ui_newstaffdialog.h"

extern DBConnect * db;

NewStaffDialog::NewStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStaffDialog)
{
    ui->setupUi(this);
    QList<RessourceType *> * ressources = db->getTypes();
    for(RessourceType * r : *ressources)
    {
        ui->typeComboBox->addItem(r->getName(), QVariant::fromValue(static_cast<void *>(r)));
    }
}

NewStaffDialog::~NewStaffDialog()
{
    delete ui;
}

Staff * NewStaffDialog::getStaff()
{
    int index = ui->typeComboBox->currentIndex();
    RessourceType * type = static_cast<RessourceType *>(ui->typeComboBox->currentData().value<void *>());

    if(type->getName() == "Informaticien")
        return new Staff(ui->lastNameLineEdit->text(), ui->firstNameLineEdit->text(), type->getId(), type->getName(), ui->loginLineEdit->text(), ui->passwordLineEdit->text());
    else
        return new Staff(ui->lastNameLineEdit->text(), ui->firstNameLineEdit->text(), type->getId(), type->getName());
}

void NewStaffDialog::upperCase_textEdited(const QString &arg1)
{
    QString s = arg1;
    QString cap = s.left(1).toUpper();
    QString text = s.length() > 1 ? s.right(s.length() -1).toLower() : "";
    qobject_cast<QLineEdit *>(sender())->setText(cap + text);
}

void NewStaffDialog::on_firstNameLineEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
}

void NewStaffDialog::on_lastNameLineEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
}

void NewStaffDialog::on_typeComboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Informaticien"){
        ui->loginLineEdit->setDisabled(false);
        ui->passwordLineEdit->setDisabled(false);
        ui->loginLineEdit->setStyleSheet("background-color:white;");
        ui->passwordLineEdit->setStyleSheet("background-color:white;");
    } else {
        ui->loginLineEdit->setText("");
        ui->passwordLineEdit->setText("");
        ui->loginLineEdit->setDisabled(true);
        ui->passwordLineEdit->setDisabled(true);
        ui->loginLineEdit->setStyleSheet("background-color:whitesmoke;");
        ui->passwordLineEdit->setStyleSheet("background-color:whitesmoke;");
    }
}

void NewStaffDialog::on_okButton_clicked()
{
    bool valid = true;
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


    if(ui->typeComboBox->currentText() == "Informaticien")
    {
        if(ui->loginLineEdit->text().isEmpty())
        {
            valid = false;
            ui->loginLineEdit->setStyleSheet("background-color:red;");
        }
        else
        {
            ui->loginLineEdit->setStyleSheet("background-color:white;");
        }

        if(ui->passwordLineEdit->text().isEmpty())
        {
            valid = false;
            ui->passwordLineEdit->setStyleSheet("background-color:red;");
        }
        else
        {
            ui->passwordLineEdit->setStyleSheet("background-color:white;");
        }
    }

    if(valid)
        accept();
}

void NewStaffDialog::on_cancelButton_clicked()
{
    reject();
}
