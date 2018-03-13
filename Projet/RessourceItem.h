#ifndef RESSOURCEITEM_H
#define RESSOURCEITEM_H

#include <QListWidgetItem>

#include "ressourcetype.h"

/**
 * Class to display a resource type in a widget.
 */
class ResourceItem : public QListWidgetItem
{

public:
    ResourceItem(ResourceType * ressource, QListWidget *parent = 0);
    ~ResourceItem();
    
    /**
     * Get the resource type.
     * @return The resource type.
     */
    ResourceType * getRessource();

private:
    ResourceType * ressource;

signals:

public slots:

};

#endif // RESSOURCEITEM_H
