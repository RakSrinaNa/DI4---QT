#include "patient.h"

Patient::Patient(QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<RessourceType *> * resources, QString comment, QString phone, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), address(address), city(city), postalCode(postalCode), dayOfConsultation(dayOfConsultation), duration(duration), priority(priority), resources(resources), comment(comment), phone(phone)
{

}

Patient::Patient(int id, QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<RessourceType *> * resources, QString comment, QString phone, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), address(address), city(city), postalCode(postalCode), dayOfConsultation(dayOfConsultation), duration(duration), priority(priority), resources(resources), comment(comment), phone(phone)
{

}

QString Patient::getLastName()
{
    return lastName;
}

QString Patient::getFirstName()
{
    return firstName;
}

QString Patient::getAddress()
{
    return address;
}

QString Patient::getCity()
{
    return city;
}

QString Patient::getPostalCode()
{
    return postalCode;
}

QDate Patient::getDayOfConsultation()
{
    return dayOfConsultation;
}

QTime Patient::getDuration()
{
    return duration;
}

int Patient::getDurationInMin()
{
    return duration.hour() * 60 + duration.minute();
}

QString Patient::getPriority()
{
    return priority;
}

QString Patient::getComment()

{
    return comment;
}

QString Patient::getPhone()
{
    return phone;
}
