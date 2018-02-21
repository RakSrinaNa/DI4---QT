#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "newstaffdialog.h"
#include "aproposdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Application");

    setStatusText("You are connected");

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
