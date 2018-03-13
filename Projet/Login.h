#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

#include "DBConnect.h"

namespace Ui
{
	class Login;
}

/**
 * Login dialog.
 */
class Login : public QDialog
{
Q_OBJECT

public:
	explicit Login(QWidget * parent = 0);
	
	~Login();

private slots:
	
	/**
	 * Slot to verify credentials when OK is clicked.
	 */
	void on_okButton_clicked();

private:
	Ui::Login * ui;
};

#endif // LOGIN_H
