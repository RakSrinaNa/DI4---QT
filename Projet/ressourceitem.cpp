#include "ressourceitem.h"

RessourceItem::RessourceItem(ResourceType *ressource, QListWidget *parent) :
    QListWidgetItem(parent), ressource(ressource)
{
    setText(ressource->getName());
}

RessourceItem::~RessourceItem()
{
    delete ressource;
}

ResourceType * RessourceItem::getRessource()
{
    return ressource;
}
