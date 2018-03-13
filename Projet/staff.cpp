#include "staff.h"

Staff::Staff(QString lastName, QString firstName, int typeId, QString typeName, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), type(ResourceType(typeId, typeName)), login(""), password("")
{}

Staff::Staff(QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject *parent) : Staff(lastName, firstName, typeId, typeName, parent)
{
    this->login = login;
    this->password = password;
}

Staff::Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), type(ResourceType(typeId, typeName)), login(""), password("")
{}

Staff::Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject *parent) : Staff(id, lastName, firstName, typeId, typeName, parent)
{
    this->login = login;
    this->password = password;
}

QString Staff::getLastName()
{
    return lastName;
}

QString Staff::getFirstName()
{
    return firstName;
}

ResourceType Staff::getRessourceType()
{
    return type;
}

QString Staff::getType()
{
    return type.getName();
}

QString Staff::getLogin()
{
    return login;
}

QString Staff::getPassword()
{
    return password;
}

QString Staff::getDescription()
{
    return lastName + " " + firstName + " [" + type.getName() + "]";
}
