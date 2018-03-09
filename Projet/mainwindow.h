#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include "dbconnect.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setStatusText(QString status, int time = 0);

private:
    Ui::MainWindow *ui;
    QSqlTableModel * model;
    QSortFilterProxyModel * firstNameModel;
    QSortFilterProxyModel * lastNameModel;
    void upperCase_textEdited(const QString &arg1);

private slots:
    void on_actionPatient_triggered();
    void on_actionPersonnel_de_soin_triggered();

    void on_actionA_propos_triggered();

    void on_firstNameEdit_textEdited(const QString &arg1);

    void on_lastNameEdit_textEdited(const QString &arg1);

signals:
    void statusChanged(QString &status);

};

#endif // MAINWINDOW_H
