#ifndef STAFF_H
#define STAFF_H

#include <QObject>

#include <QStringList>

#include "ResourceType.h"

/**
 * Represents a staff memeber.
 */
class Staff : public QObject
{
Q_OBJECT
public:
	Staff(QString lastName, QString firstName, int typeId, QString typeName, QObject * parent = 0);
	
	Staff(QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject * parent = 0);
	
	Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QObject * parent = 0);
	
	Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject * parent = 0);
	
    ~Staff();

	/**
	 * Get the last name.
	 * @return The last name.
	 */
	QString getLastName();
	
	/**
	 * Get the first name.
	 * @return The first name.
	 */
	QString getFirstName();
	
	/**
	 * Get the resource type.
	 * @return The resource type.
	 */
	ResourceType * getResourceType();
	
	/**
	 * Get the login of the staff memeber.
	 * @return The login.
	 */
	QString getLogin();
	
	/**
	 * Get the password d of the staff memeber.
	 * @return The password.
	 */
    QString getPassword();
	
	/**
	 * Get a short description of the staff member (name and type)
	 * @return  The description
	 */
	QString getDescription();
	
	/**
	 * Get the ID of the staff member.
	 * @return Its ID.
	 */
	int getId();

signals:

public slots:

private:
	int id = 0;
	QString lastName;
	QString firstName;
	ResourceType * type;
	QString login;
	QString password;
};

#endif // STAFF_H
