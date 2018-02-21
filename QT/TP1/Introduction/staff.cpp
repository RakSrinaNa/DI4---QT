#include "staff.h"

Staff::Staff(QString lastName, QString firstName, QString type, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), type(type)
{

}

Staff::Staff(QString lastName, QString firstName, QString type, QString login, QString password, QObject *parent) : Staff(lastName, firstName, type, parent)
{
    this->login = login;
    this->password = password;
}

Staff::Staff(int id, QString lastName, QString firstName, QString type, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), type(type)
{

}

Staff::Staff(int id, QString lastName, QString firstName, QString type, QString login, QString password, QObject *parent) : Staff(id, lastName, firstName, type, parent)
{
    this->login = login;
    this->password = password;
}

QString Staff::getType()
{
    return type;
}

QString Staff::getDescription()
{
    return lastName + " " + firstName + " [" + type + "]";
}
