#ifndef RESSOURCETYPE_H
#define RESSOURCETYPE_H

#include <QString>

/**
 * Represent a type of resource.
 */
class ResourceType
{
public:
	ResourceType(int id, QString name);
	
	/**
	 * Get the resource ID.
	 * @return The ID.
	 */
	int getId();
	
	/**
	 * Get the resource's name.
	 * @return The name.
	 */
	QString getName();

private:
	int id;
	QString name;
};

#endif // RESSOURCETYPE_H
