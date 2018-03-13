#ifndef PATIENT_H
#define PATIENT_H

#include <QObject>
#include <QDate>
#include <QTime>
#include <QList>

#include "staff.h"
#include "ressourcetype.h"

using namespace std;

class Customer : public QObject
{
    Q_OBJECT
public:
    Customer(QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<ResourceType *> * resources, QString comment, QString phone, QObject *parent = 0);
    Customer(int id, QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<ResourceType *> * resources, QString comment, QString phone, QObject *parent = 0);


    QString getLastName();
    QString getFirstName();
    QString getAddress();
    QString getCity();
    QString getPostalCode();
    QDate getDayOfConsultation();
    QTime getDuration();
    int getDurationInMin();
    QString getPriority();
    QList<ResourceType *> * getResources();
    QString getComment();
    QString getPhone();

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
