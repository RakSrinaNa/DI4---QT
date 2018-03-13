#ifndef RESSOURCEITEM_H
#define RESSOURCEITEM_H

#include <QListWidgetItem>

#include "ressourcetype.h"

class RessourceItem : public QListWidgetItem
{

public:
    RessourceItem(ResourceType * ressource, QListWidget *parent = 0);
    ~RessourceItem();
    ResourceType * getRessource();

private:
    ResourceType * ressource;

signals:

public slots:

};

#endif // RESSOURCEITEM_H
