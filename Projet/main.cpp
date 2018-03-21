#include <QApplication>
#include "MainWindow.h"
#include "Login.h"
#include "c_init_bd.h"

DBConnect * db;

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

    qInfo() << "Creating DB: " << (C_INIT_BD::Creation_BD() ? "true" : "false");
	db = new DBConnect();

    Login login(a.activeModalWidget());
	int result = 0;
	if(login.exec() == QDialog::Accepted) //If user is successfully logged in
	{

        MainWindow w;
        qInfo() << "User logged in";
		w.show();
		result = a.exec();
	}
	delete db;
	return result;
}
