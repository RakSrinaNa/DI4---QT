#include <QApplication>
#include "mainwindow.h"
#include "login.h"
#include "c_init_bd.h"
#include "dbconnect.h"

#include <iostream>

DBConnect * db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::cout << C_INIT_BD::Creation_BD() << std::endl;

    db = new DBConnect();

    MainWindow w;
    Login login(&w);
    int result = 0;
    if(login.exec() == QDialog::Accepted)
    {
        w.show();
        result = a.exec();
    }
    delete db;
    return result;
}
