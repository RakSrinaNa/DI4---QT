#ifndef NEWSTAFFDIALOG_H
#define NEWSTAFFDIALOG_H

#include <QDialog>

#include "Staff.h"
#include "database/DBConnect.h"
#include "RessourceType.h"
#include "ressourceitem.h"

namespace Ui
{
	class NewStaffDialog;
}

class NewStaffDialog : public QDialog
{
Q_OBJECT

public:
	explicit NewStaffDialog(QWidget * parent = 0);
	
	~NewStaffDialog();
	
	Staff * getStaff();

private:
	/**
	 * Used to transform a string into one that start uppercase and the rest is lowercase. (used by slots from textedit)
	 * @param arg1 The string to modify.
	 */
	void upperCase_textEdited(const QString &arg1);

private slots:
	
	/**
	 * Called when the first name is edited.
	 * @param arg1 The new value.
	 */
	void on_firstNameLineEdit_textEdited(const QString &arg1);
	
	/**
	 * Called when the last name is edited.
	 * @param arg1 The new value.
	 */
	void on_lastNameLineEdit_textEdited(const QString &arg1);
	
	/**
	 * Called when resource type is edited.
	 * @param arg1 The new value.
	 */
	void on_typeComboBox_currentIndexChanged(const QString &arg1);
	
	/**
	 * Called when ok button is clicked.
	 */
	void on_okButton_clicked();
	
	/**
	 * Called when cancel button is clicked.
	 */
	void on_cancelButton_clicked();

private:
	Ui::NewStaffDialog * ui;
};

#endif // NEWSTAFFDIALOG_H
