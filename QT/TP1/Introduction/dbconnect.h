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

class DBConnect
{
public:
    DBConnect();
    ~DBConnect();
    Patient *getPatient(int id);
    Staff *getStaff(int id, bool logPass = false);
    QList<RessourceType> * getTypes();

private:
    QSqlDatabase db;
};

#endif // DBCONNECT_H
