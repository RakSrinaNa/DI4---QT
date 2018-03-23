#include <QApplication>
#include <QDebug>
#include "MainWindow.h"
#include "Login.h"
#include "c_init_bd.h"

DBConnect * db;

using namespace std;

void printMe(const pair<int, string>& pair)
{
	cout << pair.first << " -> " << pair.second << endl;
}

int main(int argc, char * argv[])
{
	multimap<int, string> map = multimap<int, string>();
	map.insert(pair<int, string>(1, "titi"));
	map.insert(pair<int, string>(2, "toto"));
	map.insert(pair<int, string>(3, "tutu"));
	map.insert(pair<int, string>(4, "tata"));

	map.erase(3);

	map.insert(pair<int, string>(0, "tete"));

	std::for_each(map.begin(), map.end(), printMe);


	QApplication a(argc, argv);

    qDebug() << "Creating DB: " << (C_INIT_BD::Creation_BD() ? "true" : "false");
	db = new DBConnect();

	Login login(a.activeModalWidget());
	int result = 0;
	if(login.exec() == QDialog::Accepted) //If user is successfully logged in
	{
		MainWindow w;
        qDebug() << "User logged in";
		w.show();
		result = a.exec();
	}
	delete db;
	return result;
}
