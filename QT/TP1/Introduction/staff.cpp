#include "staff.h"

Staff::Staff(QString lastName, QString firstName, QString type, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), type(type), login(""), password("")
{}

Staff::Staff(QString lastName, QString firstName, QString type, QString login, QString password, QObject *parent) : Staff(lastName, firstName, type, parent), login(login), password(password)
{}

Staff::Staff(int id, QString lastName, QString firstName, QString type, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), type(type), login(""), password("")
{}

Staff::Staff(int id, QString lastName, QString firstName, QString type, QString login, QString password, QObject *parent) : Staff(id, lastName, firstName, type, parent), login(login), password(password)
{}

QString Staff::getType()
{
    return type;
}

QString Staff::getDescription()
{
    return lastName + " " + firstName + " [" + type + "]";
}
