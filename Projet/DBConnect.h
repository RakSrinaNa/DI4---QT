#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <exception>

#include "Customer.h"
#include "Staff.h"
#include "ResourceType.h"

/**
 * Class to handle database queries.
 */
class DBConnect
{
public:
	DBConnect();

	~DBConnect();

	/**
	 * Get the database object.
	 *
	 * @return The database.
	 */
	QSqlDatabase &getDB();

	/**
	 * Get the patient by its id.
	 *
	 * @param id The patient id.
	 *
	 * @return A pointer to the patient or null.
	 */
	Customer * getCustomer(int id);

	/**
	 * Get a staff member by its id.
	 * @param id The staff id.
	 * @param logPass If we should get his login informations.
	 * @return The staff memeber or null if not found.
	 */
	Staff * getStaff(int id, bool logPass = false);

	/**
	 * Try to log a user with his username and password.
	 * @param user The username.
	 * @param pass The password.
	 * @return True if the informations were correct, false otherwise.
	 */
	bool logUser(QString &user, QString &pass);

	/**
	 * Get all the available resource type.
	 * @return The available types.
	 */
	QList<ResourceType *> * getTypes();

	/**
	 * Get a ressource type by its ID.
	 * @param id The id to find.
	 * @return A ressource type or null if not found.
	 */
	ResourceType * getType(int id);

	/**
	 * Get a ressource type by its name.
	 * @param name The name to find.
	 * @return A ressource type or null if not found.
	 */
	ResourceType * getType(QString name);

	/**
	 * Add a customer to the database.
	 * @param customer The customer to add.
	 * @return True if added, false otherwise.
	 */
	bool addCustomer(Customer * customer);

	/**
	 * Add a staff member to the database.
	 * @param staff The staff to add.
	 * @return True if added, false otherwise.
	 */
	bool addStaff(Staff * staff);

	/**
	 * Get all the customers that have an appointment on a specific date.
	 * @param date The concerned date.
	 * @return The customers on this date.
	 */
	QList<Customer *> * getClientsFromDate(QDate date);

	/**
	 * Get all the staff members
	 * @return All the staff members
	 */
	QList<Staff *> * getAllStaff();

	/**
	 * Get all the staff members
	 * @return All the staff members
	 */
	QList<Staff *> * getStaffByType(int id);

	/**
	 * Change the resource name.
	 * @param ID The resource ID.
	 * @param name The new name.
	 * @return True if successful, false otherwise.
	 */
	bool changeResourceName(int ID, QString name);

	/**
	 * Change the name of a staff.
	 * @param ID The staff ID.
	 * @param firstName The new firstName.
	 * @param lastName The new lastName.
	 * @return True if successful, false otherwise.
	 */
	bool changeStaffName(int ID, QString firstName, QString lastName);

	/**
	 * Change the resource type of a staff.
	 * @param ID The staff ID.
	 * @param rID The new resource ID.
	 * @return True if successful, false otherwise.
	 */
	bool changeStaffResource(int ID, int rID);

	/**
	 * Tell if a resource exists.
	 * @param ID The ID of the resource to check.
	 * @return True if exists, false otherwise.
	 */
	bool resourceExists(int ID);

	/**
	 * Delete a staff.
	 * @param ID The ID of the staff to remove.
	 * @return True if successful, false otherwise.
	 */
	bool removeStaff(int ID);

	/**
	 * Remove a resource type. All the staff of this kind will be deleted too. All the customers needing this resource, won't need it anymore.
	 * @param ID The ID of the resource to delete.
	 * @return True if successful, false otherwise.
	 */
	bool removeResourceType(int ID);

	/**
	 * Remove all the staff of this resource.
	 * @param ID The ID of the resource the staff have.
	 * @return True if successful, false otherwise.
	 */
	bool removeAllStaffOfType(int ID);

private:
	QSqlDatabase db;
};

#endif // DBCONNECT_H
