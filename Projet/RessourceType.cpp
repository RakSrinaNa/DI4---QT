#include "RessourceType.h"

ResourceType::ResourceType(int id, QString name) : id(id), name(name)
{
}

int ResourceType::getId()
{
	return id;
}

QString ResourceType::getName()
{
	return name;
}

