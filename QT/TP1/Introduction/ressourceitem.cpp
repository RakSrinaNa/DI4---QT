#include "ressourceitem.h"

RessourceItem::RessourceItem(RessourceType *ressource, QWidget *parent) :
    QWidget(parent), ressource(ressource)
{
    setText(ressource->getName());
}

RessourceItem::~RessourceItem()
{
    delete ressource;
}
