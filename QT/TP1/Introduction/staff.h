#ifndef STAFF_H
#define STAFF_H

#include <QObject>

#include <QStringList>

#include "ressourcetype.h"

class Staff : public QObject
{
    Q_OBJECT
public:
    Staff(QString lastName, QString firstName, int typeId, QString typeName, QObject *parent = 0);
    Staff(QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject *parent = 0);
    Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QObject *parent = 0);
    Staff(int id, QString lastName, QString firstName, int typeId, QString typeName, QString login, QString password, QObject *parent = 0);

    QString getLastName();
    QString getFirstName();
    RessourceType getRessourceType();
    QString getType();
    QString getLogin();
    QString getPassword();

    QString getDescription();

signals:

public slots:

private:
    int id = 0;
    QString lastName;
    QString firstName;
    RessourceType type;
    QString login;
    QString password;

};

#endif // STAFF_H
