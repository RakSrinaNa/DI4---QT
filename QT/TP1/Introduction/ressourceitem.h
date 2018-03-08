#ifndef RESSOURCEITEM_H
#define RESSOURCEITEM_H

#include <QListWidgetItem>

#include "ressourcetype.h"

class RessourceItem : public QListWidgetItem
{
    Q_OBJECT
public:
    RessourceItem(RessourceType * ressource, QWidget *parent = 0);
    ~RessourceItem();

private:
    RessourceType * ressource;

signals:

public slots:

};

#endif // RESSOURCEITEM_H
