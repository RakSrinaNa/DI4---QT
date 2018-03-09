#include "ressourcetype.h"

RessourceType::RessourceType(int id, QString name) : id(id), name(name)
{
}

int RessourceType::getId()
{
    return id;
}

QString RessourceType::getName()
{
    return name;
}

