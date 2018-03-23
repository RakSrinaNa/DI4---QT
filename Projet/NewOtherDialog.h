#ifndef NEWOTHERDIALOG_H
#define NEWOTHERDIALOG_H

#include <QDialog>

#include "DBConnect.h"

namespace Ui {
	class NewOtherDialog;
}

class NewOtherDialog : public QDialog
{
	Q_OBJECT

public:
	explicit NewOtherDialog(QWidget *parent = 0);
	~NewOtherDialog();
	Staff * getOther();

private slots:
	void on_firstNameLineEdit_textEdited(const QString &arg1);

	void on_lastNameLineEdit_textEdited(const QString &arg1);

	void on_cancelButton_clicked();

	void on_okButton_clicked();

private:
	Ui::NewOtherDialog *ui;

	/**
	 * Used to transform a string into one that start uppercase and the rest is lowercase. (used by slots from textedit)
	 * @param arg1 The string to modify.
	 */
	void upperCase_textEdited(const QString &arg1);
};

#endif // NEWOTHERDIALOG_H
