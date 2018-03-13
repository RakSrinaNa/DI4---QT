#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>

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
    void textExtension_textEdited(const QString &arg1);

private slots:
    void on_firstNameEdit_textEdited(const QString &arg1);
    void on_lastNameEdit_textEdited(const QString &arg1);

    void keyPressEvent(QKeyEvent * event);

    void on_planPushButton_clicked();

    void on_pathPushButton_clicked();

    void on_saveLineEdit_textEdited(const QString &arg1);

    void on_savePushButton_clicked();

    void on_actionExit_triggered();

    void on_actionCustomer_triggered();

    void on_actionStaff_triggered();

    void on_actionAbout_triggered();

    void on_table_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

signals:
    void statusChanged(QString &status);

};

#endif // MAINWINDOW_H
