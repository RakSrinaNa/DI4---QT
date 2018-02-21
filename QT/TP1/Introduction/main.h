#ifndef MAIN_H
#define MAIN_H

#include <qapplication.h>

class Main{
    Q_OBJECT
private:
    bool logged;
public:
    Main();
    void start();
public slots:
    void loginClose(int result);
};

#endif // MAIN_H
