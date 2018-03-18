#include "ResourceType.h"

ResourceType::ResourceType(int id, QString name) : id(id), name(name)
{
    qInfo() << "Creating resource type " << id << "(" << name << ")";
}

ResourceType::~ResourceType()
{
    qInfo() << "Destroying resource type " << id << "(" << name << ")";
}

int ResourceType::getId()
{
	return id;
}

QString ResourceType::getName()
{
	return name;
}

