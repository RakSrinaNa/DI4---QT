#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "newstaffdialog.h"
#include "aproposdialog.h"

extern DBConnect * db;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    ui->setupUi(this);
    setWindowTitle("Application");
    setStatusText("You are connected");
    ui->tabWidget->tabBar()->setExpanding(true);

   model = new QSqlTableModel(this, db->getDb());
   model->setTable("TClient");
   model->setEditStrategy(QSqlTableModel::OnFieldChange);
   model->select();
   model->setHeaderData(0, Qt::Horizontal, tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
   model->setHeaderData(2, Qt::Horizontal, tr("Last name"));
   model->setHeaderData(3, Qt::Horizontal, tr("Adsress"));
   model->setHeaderData(4, Qt::Horizontal, tr("City"));
   model->setHeaderData(5, Qt::Horizontal, tr("Postal Code"));
   model->setHeaderData(6, Qt::Horizontal, tr("Comment"));
   model->setHeaderData(7, Qt::Horizontal, tr("Phone"));
   model->setHeaderData(8, Qt::Horizontal, tr("Date"));
   model->setHeaderData(9, Qt::Horizontal, tr("Length"));
   model->setHeaderData(10, Qt::Horizontal, tr("Priority"));

   firstNameModel = new QSortFilterProxyModel(this);
   lastNameModel = new QSortFilterProxyModel(this);
   ui->tableView->setModel(lastNameModel);
   firstNameModel->setSourceModel(model);
   firstNameModel->setFilterKeyColumn(1);
   lastNameModel->setSourceModel(firstNameModel);
   lastNameModel->setFilterKeyColumn(2);
   ui->tableView->setColumnHidden(0, true);

   ui->tableView->resizeColumnsToContents();

   //connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
   //connect(ui->revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStatusText(QString status, int time)
{
    ui->statusBar->showMessage(status, time);
}

void MainWindow::on_actionPatient_triggered()
{
    NewPatientDialog newPatient;
    if(newPatient.exec() == QDialog::Accepted){
        if(db->addPatient(newPatient.getPatient()))
        {
            setStatusText("A new patient was added", 5000);
            model->select();
        }
        else
            setStatusText("Failed to add a new patient", 5000);
    }
}

void MainWindow::on_actionPersonnel_de_soin_triggered()
{
    NewStaffDialog newStaff;
    if(newStaff.exec() == QDialog::Accepted){
        if(db->addStaff(newStaff.getStaff()))
            setStatusText("A new staff member was added", 5000);
        else
            setStatusText("Fail to add new staff member", 5000);
    }
}

void MainWindow::on_actionA_propos_triggered()
{
    AProposDialog APropos;
    APropos.exec();
}

void MainWindow::upperCase_textEdited(const QString &arg1)
{
    QString s = arg1;
    QString cap = s.left(1).toUpper();
    QString text = s.length() > 1 ? s.right(s.length() -1).toLower() : "";
    qobject_cast<QLineEdit *>(sender())->setText(cap + text);
}

void MainWindow::on_firstNameEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
    firstNameModel->setFilterRegExp(qobject_cast<QLineEdit *>(sender())->text());
}

void MainWindow::on_lastNameEdit_textEdited(const QString &arg1)
{
    upperCase_textEdited(arg1);
    lastNameModel->setFilterRegExp(qobject_cast<QLineEdit *>(sender())->text());
}
