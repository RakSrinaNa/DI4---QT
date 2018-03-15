#include "Customer.h"

Customer::Customer(QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<Staff *> * resources, QString comment, QString phone, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), address(address), city(city), postalCode(postalCode), dayOfConsultation(dayOfConsultation), duration(duration), priority(priority), resources(resources), comment(comment), phone(phone)
{

}

Customer::Customer(int id, QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<Staff *> * resources, QString comment, QString phone, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), address(address), city(city), postalCode(postalCode), dayOfConsultation(dayOfConsultation), duration(duration), priority(priority), resources(resources), comment(comment), phone(phone)
{

}

QString Customer::getLastName()
{
    return lastName;
}

QString Customer::getFirstName()
{
    return firstName;
}

QString Customer::getAddress()
{
    return address;
}

QString Customer::getCity()
{
    return city;
}

QString Customer::getPostalCode()
{
    return postalCode;
}

QDate Customer::getDayOfConsultation()
{
    return dayOfConsultation;
}

QTime Customer::getDuration()
{
    return duration;
}

int Customer::getDurationInMin()
{
    return getDuration().hour() * 60 + getDuration().minute();
}

QString Customer::getPriority()
{
    return priority;
}

QList<Staff *> * Customer::getResources()
{
    return resources;
}

QString Customer::getComment()

{
    return comment;
}

QString Customer::getPhone()
{
    return phone;
}

QString Customer::toString()
{
   return firstName + " " + lastName;
}
