#include <QApplication>
#include "mainwindow.h"
#include "login.h"
#include "c_init_bd.h"
#include "dbconnect.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //std::cout << C_INIT_BD::Creation_BD() << std::endl;

    db = DBConnect();

    MainWindow w;
    Login login(&w);
    if(login.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;
}
