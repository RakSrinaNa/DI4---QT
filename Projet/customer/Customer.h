#ifndef PATIENT_H
#define PATIENT_H

#include <QObject>
#include <QDate>
#include <QTime>
#include <QList>

#include "staff/Staff.h"
#include "staff/RessourceType.h"

using namespace std;

/**
 * Represents a customer.
 */
class Customer : public QObject
{
Q_OBJECT
public:
	Customer(QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<ResourceType *> * resources, QString comment, QString phone, QObject * parent = 0);
	
	Customer(int id, QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<ResourceType *> * resources, QString comment, QString phone, QObject * parent = 0);
	
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
	 * Get the customer's address.
	 * @return The address.
	 */
	QString getAddress();
	
	/**
	 * Get the city.
	 * @return The city.
	 */
	QString getCity();
	
	/**
	 * Get the postal code.
	 * @return The postal code.
	 */
	QString getPostalCode();
	
	/**
	 * Get the day of the consultation.
	 * @return The day of the consultation.
	 */
	QDate getDayOfConsultation();
	
	/**
	 * Get the duration of the appointment.
	 * @return The duration.
	 */
	QTime getDuration();
	
	/**
	 * Get the duration of the appointment in minutest.
	 * @return The duration in minutes.
	 */
	int getDurationInMin();
	
	/**
	 * Get the priority of the appointment.
	 * @return The priority.
	 */
	QString getPriority();
	
	/**
	 * Get the resources the appointment will use.
	 * @return The resources.
	 */
	QList<ResourceType *> * getResources();
	
	/**
	 * Get the comment.
	 * @return The comment.
	 */
	QString getComment();
	
	/**
	 * Get the phone.
	 * @return The phone.
	 */
	QString getPhone();
	
	/**
	 * Get the customer as a string.
	 * @return The customer as string.
	 */
	QString toString();

signals:

public slots:

private:
	int id = 0;
	QString lastName;
	QString firstName;
	QString address;
	QString city;
	QString postalCode;
	QDate dayOfConsultation;
	QTime duration;
	QString priority;
	QList<ResourceType *> * resources;
	QString comment;
	QString phone;
};

#endif // PATIENT_H
