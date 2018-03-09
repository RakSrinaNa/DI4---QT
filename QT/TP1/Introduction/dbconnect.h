#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <exception>

#include "patient.h"
#include "staff.h"
#include "ressourcetype.h"

class DBConnect
{
public:
    DBConnect();
    ~DBConnect();

    Patient *getPatient(int id);
    Staff *getStaff(int id, bool logPass = false);

    bool logUser(QString &user, QString &pass);

    QList<RessourceType *> *getTypes();
    RessourceType * getType(int id);

    bool addPatient(Patient * patient);
    bool addStaff(Staff * staff);


private:
    QSqlDatabase db;
};

#endif // DBCONNECT_H
