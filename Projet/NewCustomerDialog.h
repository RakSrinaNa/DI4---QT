#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

#include <QDialog>
#include <QList>

#include "Customer.h"
#include "Staff.h"
#include "StaffItem.h"
#include "DBConnect.h"
#include "ResourceType.h"

using namespace std;

namespace Ui
{
	class NewCustomerDialog;
}

/**
 * Window to create a new customer.
 */
class NewCustomerDialog : public QDialog
{
Q_OBJECT

public:
	NewCustomerDialog(QWidget * parent = 0);

	~NewCustomerDialog();

	/**
	 * Get the resources that were selected.
	 * @return A list of the selected resources.
	 */
	QList<Staff *> * getResources();

	/**
	 * Get the created customer.
	 * @return The customer.
	 */
	Customer * getCustomer();

private:
	/**
	 * Used to transform a string into one that start uppercase and the rest is lowercase. (used by slots from textedit)
	 * @param arg1 The string to modify.
	 */
	void upperCase_textEdited(const QString &arg1);

private slots:

	/**
	 * Called when the last name is edited.
	 * @param arg1 The new value.
	 */
	void on_lastNameLineEdit_textEdited(const QString &arg1);

	/**
	 * Called when the first name is edited.
	 * @param arg1 The new value.
	 */
	void on_firstNameLineEdit_textEdited(const QString &arg1);

	/**
	 * Called when the city is edited.
	 * @param arg1 The new value.
	 */
	void on_cityLineEdit_textEdited(const QString &arg1);

	/**
	 * Called when ok button is clicked.
	 */
	void on_okButton_clicked();

	/**
	 * Called when cancel button is clicked.
	 */
	void on_cancelButton_clicked();

private:
	Ui::NewCustomerDialog * ui;
};

#endif // NEWPATIENTDIALOG_H
