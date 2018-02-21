#include "newstaffdialog.h"
#include "ui_newstaffdialog.h"

NewStaffDialog::NewStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStaffDialog)
{
    ui->setupUi(this);
    ui->typeComboBox->addItems(db.getTypes());
}

NewStaffDialog::~NewStaffDialog()
{
    delete ui;
}

Staff * NewStaffDialog::getStaff()
{
    return nullptr;
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
    } else {
        ui->loginLineEdit->setText("");
        ui->passwordLineEdit->setText("");
        ui->loginLineEdit->setDisabled(true);
        ui->passwordLineEdit->setDisabled(true);
    }
}

void NewStaffDialog::on_okButton_clicked()
{
    if(!ui->lastNameLineEdit->text().isEmpty() && !ui->firstNameLineEdit->text().isEmpty())
        if(ui->typeComboBox->currentText() != "Informaticien" || (!ui->loginLineEdit->text().isEmpty() && !ui->passwordLineEdit->text().isEmpty()))
            accept();
}

void NewStaffDialog::on_cancelButton_clicked()
{
    reject();
}
