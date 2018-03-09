#include "ressourceitem.h"

RessourceItem::RessourceItem(RessourceType *ressource, QListWidget *parent) :
    QListWidgetItem(parent), ressource(ressource)
{
    setText(ressource->getName());
}

RessourceItem::~RessourceItem()
{
    delete ressource;
}
