#ifndef NEWSTAFFDIALOG_H
#define NEWSTAFFDIALOG_H

#include <QDialog>

#include "staff.h"
#include "DBConnect.h"
#include "ressourcetype.h"
#include "ressourceitem.h"

namespace Ui {
class NewStaffDialog;
}

class NewStaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStaffDialog(QWidget *parent = 0);
    ~NewStaffDialog();
    Staff * getStaff();

private slots:
    void upperCase_textEdited(const QString &arg1);

    void on_firstNameLineEdit_textEdited(const QString &arg1);
    void on_lastNameLineEdit_textEdited(const QString &arg1);

    void on_typeComboBox_currentIndexChanged(const QString &arg1);

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::NewStaffDialog *ui;
};

#endif // NEWSTAFFDIALOG_H
