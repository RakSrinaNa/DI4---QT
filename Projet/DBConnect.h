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
	 * @return
	 */
	QList<ResourceType *> * getTypes();
	
	/**
	 * Get a ressource type by its ID.
	 * @param id The id to find.
	 * @return A ressource type or null if not found.
	 */
	ResourceType * getType(int id);
	
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

    bool changeResourceName(int ID, QString name);

    bool changeStaffName(int ID, QString firstName, QString lastName);

private:
	QSqlDatabase db;
};

#endif // DBCONNECT_H
