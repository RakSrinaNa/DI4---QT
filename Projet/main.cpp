#include <QApplication>
#include "main/MainWindow.h"
#include "login/Login.h"
#include "database/c_init_bd.h"

DBConnect * db;

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);
	
	printf("Création de la DBB: %s\n", C_INIT_BD::Creation_BD() ? "true" : "false");
	db = new DBConnect();
	
	MainWindow w;
	Login login(&w);
	int result = 0;
	if(login.exec() == QDialog::Accepted) //If user is successfully logged in
	{
		w.show();
		result = a.exec();
	}
	delete db;
	return result;
}
