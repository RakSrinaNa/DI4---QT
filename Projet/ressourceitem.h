#ifndef RESSOURCEITEM_H
#define RESSOURCEITEM_H

#include <QListWidgetItem>

#include "ressourcetype.h"

class RessourceItem : public QListWidgetItem
{

public:
    RessourceItem(RessourceType * ressource, QListWidget *parent = 0);
    ~RessourceItem();
    RessourceType * getRessource();

private:
    RessourceType * ressource;

signals:

public slots:

};

#endif // RESSOURCEITEM_H
