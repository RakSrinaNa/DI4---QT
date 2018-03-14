#include "ressourceitem.h"

ResourceItem::ResourceItem(ResourceType * ressource, QListWidget * parent) : QListWidgetItem(parent), ressource(ressource)
{
	setText(ressource->getName());
}

ResourceItem::~ResourceItem()
{
	delete ressource;
}

ResourceType * ResourceItem::getRessource()
{
	return ressource;
}
