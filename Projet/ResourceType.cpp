#include "ResourceType.h"

ResourceType::ResourceType(int id, QString name) : id(id), name(name)
{
    qDebug() << "Creating resource type " << id << "(" << name << ")";
}

ResourceType::~ResourceType()
{
    qDebug() << "Destroying resource type " << id << "(" << name << ")";
}

int ResourceType::getId()
{
	return id;
}

QString ResourceType::getName()
{
	return name;
}

