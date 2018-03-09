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

   model = new QSqlTableModel(this, db->getDb());
   model->setTable("Person");
   model->setEditStrategy(QSqlTableModel::OnFieldChange);
   model->select();
   model->setHeaderData(0, Qt::Horizontal, tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, tr("Adresse"));
   model->setHeaderData(4, Qt::Horizontal, tr("Ville"));
   model->setHeaderData(5, Qt::Horizontal, tr("CP"));
   model->setHeaderData(6, Qt::Horizontal, tr("Commentaire"));
   model->setHeaderData(7, Qt::Horizontal, tr("Tel"));
   model->setHeaderData(8, Qt::Horizontal, tr("DateRdv"));
   model->setHeaderData(9, Qt::Horizontal, tr("DureeRdv"));
   model->setHeaderData(10, Qt::Horizontal, tr("Priorite"));
   ui->tableView->setModel(model);
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
        newPatient.getPatient();
        setStatusText("A new patient was added", 5000);
    }
}

void MainWindow::on_actionPersonnel_de_soin_triggered()
{
    NewStaffDialog newStaff;
    if(newStaff.exec() == QDialog::Accepted){
        newStaff.getStaff();
        setStatusText("A new staff member was added", 5000);
    }
}

void MainWindow::on_actionA_propos_triggered()
{
    AProposDialog APropos;
    APropos.exec();
}
