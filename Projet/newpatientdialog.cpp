#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"

extern DBConnect * db;

NewPatientDialog::NewPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPatientDialog)
{
    ui->setupUi(this);

    ui->dayOfConsultationDateEdit->setDate(QDate::currentDate());
    ui->priorityComboBox->addItems({"1", "2", "3", "4", "5"});
    ui->postalCodeLineEdit->setValidator(new QIntValidator(1, 99999, this));
    ui->phoneLineEdit->setValidator(new QIntValidator(0, 999999999, this));

    QList<RessourceType *> * ressources = db->getTypes();
    for(ResourceType * r : *ressources)
        ui->resourcesListWidget->addItem(new RessourceItem(r, ui->resourcesListWidget));

}

NewPatientDialog::~NewPatientDialog()
{
    delete ui;
}

Customer * NewPatientDialog::getPatient()
{
    return new Customer(ui->lastNameLineEdit->text(), ui->firstNameLineEdit->text(), ui->addressLineEdit->text(), ui->cityLineEdit->text(), ui->postalCodeLineEdit->text(), ui->dayOfConsultationDateEdit->date(), ui->durationTimeEdit->time(), ui->priorityComboBox->currentText(), getResources(), ui->commentLineEdit->text(), ui->phoneLineEdit->text());
}

QList<ResourceType *> * NewPatientDialog::getResources()
{
    QList<RessourceType *> * list = new QList<ResourceType *>;
    for(QListWidgetItem * item : ui->resourcesListWidget->selectedItems())
        *(list) << dynamic_cast<RessourceItem *>(item)->getRessource();
    return list;
}

void NewPatientDialog::upperCase_textEdited(const QString &arg1)
{
    QString s = arg1;
    QString cap = s.left(1).toUpper();
    QString text = s.length() > 1 ? s.right(s.length() -1).toLower() : "";
    qobject_cast<QLineEdit *>(sender())->setText(cap + text);
}

void NewPatientDialog::on_lastNameLineEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
}

void NewPatientDialog::on_firstNameLineEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
}

void NewPatientDialog::on_cityLineEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
}

void NewPatientDialog::on_okButton_clicked()
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

    if(ui->dayOfConsultationDateEdit->date() < QDate::currentDate())
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

    if(valid)
        accept();
}

void NewPatientDialog::on_cancelButton_clicked()
{
    reject();
}
