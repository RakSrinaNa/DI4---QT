#ifndef STAFF_H
#define STAFF_H

#include <QObject>

#include <QStringList>

class Staff : public QObject
{
    Q_OBJECT
public:
    Staff(QString lastName, QString firstName, QString type, QObject *parent = 0);
    Staff(QString lastName, QString firstName, QString type, QString login, QString password, QObject *parent = 0);
    Staff(int id, QString lastName, QString firstName, QString type, QObject *parent = 0);
    Staff(int id, QString lastName, QString firstName, QString type, QString login, QString password, QObject *parent = 0);

    QString getType();
    QString getDescription();

signals:

public slots:

private:
    int id = 0;
    QString lastName;
    QString firstName;
    QString type;
    QString login;
    QString password;

};

#endif // STAFF_H
