#include "Staff.h"

Staff::Staff(QString lastName, QString firstName, int typeId, QString typeName, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), type(new ResourceType(typeId, typeName)), login(""), password("")
{}

Staff::Staff(QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject *parent) : Staff(lastName, firstName, typeId, typeName, parent)
{
    this->login = login;
    this->password = password;
}

Staff::Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), type(new ResourceType(typeId, typeName)), login(""), password("")
{}

Staff::Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject *parent) : Staff(id, lastName, firstName, typeId, typeName, parent)
{
    this->login = login;
    this->password = password;
}

Staff::~Staff(){
    delete type;
}

QString Staff::getLastName()
{
    return lastName;
}

QString Staff::getFirstName()
{
    return firstName;
}

ResourceType *Staff::getResourceType()
{
    return type;
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
    return firstName + " " + lastName + " [" + type->getName() + "]";
}

int Staff::getId()
{
    return id;
}
