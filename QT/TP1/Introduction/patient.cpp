#include "patient.h"

Patient::Patient(QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<RessourceType *> * resources, QString comment, QString phone, QObject *parent) : QObject(parent), lastName(lastName), firstName(firstName), address(address), city(city), postalCode(postalCode), dayOfConsultation(dayOfConsultation), duration(duration), priority(priority), resources(resources), comment(comment), phone(phone)
{

}

Patient::Patient(int id, QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<RessourceType *> * resources, QString comment, QString phone, QObject *parent) : QObject(parent), id(id), lastName(lastName), firstName(firstName), address(address), city(city), postalCode(postalCode), dayOfConsultation(dayOfConsultation), duration(duration), priority(priority), resources(resources), comment(comment), phone(phone)
{

}
