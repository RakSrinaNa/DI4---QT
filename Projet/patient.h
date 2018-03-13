#ifndef PATIENT_H
#define PATIENT_H

#include <QObject>
#include <QDate>
#include <QTime>
#include <QList>

#include "staff.h"
#include "ressourcetype.h"

using namespace std;

class Patient : public QObject
{
    Q_OBJECT
public:
    Patient(QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<RessourceType *> * resources, QString comment, QString phone, QObject *parent = 0);
    Patient(int id, QString lastName, QString firstName, QString address, QString city, QString postalCode, QDate dayOfConsultation, QTime duration, QString priority, QList<RessourceType *> * resources, QString comment, QString phone, QObject *parent = 0);


    QString getLastName();
    QString getFirstName();
    QString getAddress();
    QString getCity();
    QString getPostalCode();
    QDate getDayOfConsultation();
    QTime getDuration();
    int getDurationInMin();
    QString getPriority();
    QList<RessourceType *> * getResources();
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
    QList<RessourceType *> * resources;
    QString comment;
    QString phone;
};

#endif // PATIENT_H
