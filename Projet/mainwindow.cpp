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

    //Initialize tab 1
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


    //Initialize tab 2
    ui->planDateEdit->setDate(QDate::currentDate());
    ui->pathLineEdit->setText(QDir::currentPath());

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

void MainWindow::textExtension_textEdited(const QString &arg1)
{
    int cursor = qobject_cast<QLineEdit *>(sender())->cursorPosition();
    QString oldText = arg1;
    QString newText = oldText;
    if(oldText == ".txt")
        newText = "";
    if(!oldText.endsWith(".txt"))
        newText = oldText + ".txt";

    qobject_cast<QLineEdit *>(sender())->setText(newText);
    qobject_cast<QLineEdit *>(sender())->setCursorPosition(cursor);
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

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
    case Qt::Key_Delete:
    {
        int current = ui->tableView->selectionModel()->currentIndex().row();
        if(current != -1){
            model->removeRow(current);
            model->submitAll();
            model->select();

            int total = ui->tableView->model()->rowCount();
            if(current >= total -1)
                current = total -1;
            ui->tableView->selectRow(current);

        }
        break;
    }

    case Qt::Key_0:
        db->test();
        break;
    }
    event->accept();
}

void MainWindow::on_planPushButton_clicked()
{

}

void MainWindow::on_pathPushButton_clicked()
{
    QString oldDir = ui->pathLineEdit->text();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), oldDir);
    ui->pathLineEdit->setText(dir);
}

void MainWindow::on_saveLineEdit_textEdited(const QString &arg1)
{
    textExtension_textEdited(arg1);
    if(!ui->saveLineEdit->text().isEmpty())
        ui->saveLineEdit->setStyleSheet("background-color:white;");
}

void MainWindow::on_savePushButton_clicked()
{
    QMessageBox message(this);
    message.setWindowTitle("Information");

    bool ok = true;

    if(!(ok = !ui->saveLineEdit->text().isEmpty()))
        ui->saveLineEdit->setStyleSheet("background-color:red;");
    if(!(ok = !ui->planTextBrowser->toPlainText().isEmpty()))
        ui->planTextBrowser->setStyleSheet("background-color:red;");

    if(ok){
        QFile file(ui->pathLineEdit->text() + "/" + ui->saveLineEdit->text());
        if(file.open( QIODevice::WriteOnly)){
            QTextStream stream(&file);
            stream << ui->planTextBrowser->toPlainText();
            file.close();
            message.setText("Wrote succesfully into file.");
        }
        else{
            message.setText("Failed to write into file.");
        }
        message.exec();
    }
}
