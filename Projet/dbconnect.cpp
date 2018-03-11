#include "dbconnect.h"

#include <iostream>

DBConnect::DBConnect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        db.setDatabaseName("base_tmp.sqli");
        db.open();

        if(!db.isOpen())
        {
            qDebug() << db.lastError().text();
            qDebug() << "Erreur à louverture de la base !\n";
            throw std::exception();
        }

    }
    else
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à création de la base !\n";
        throw std::exception();
    }

}

DBConnect::~DBConnect(){
    db.close();
    db.removeDatabase("QSQLITE");
}

QSqlDatabase & DBConnect::getDb()
{
    return db;
}

Patient * DBConnect::getPatient(int id)
{
    QSqlQuery query;
    Patient * patient = nullptr;
    QList<RessourceType *> * resources = new QList<RessourceType *>();

    //Get the resources of the patient
    query.prepare("SELECT TRessource.Id "
                  "FROM TClient "
                  "INNER JOIN TRdv ON TClient.Id = TRdv.IdClient "
                  "INNER JOIN TRessource ON TRessource.id = TRdv.TRdv.IdRessource "
                  "WHERE TClient.Id = :id");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        printf("Error getting patient's ressources %d! %s\n", id, query.lastError().text().toStdString().c_str());
        return NULL;
    }

    while(query.next()){
        (*resources) << (getType(query.value("TRessource.Id").toInt()));
    }

    //Get the rest of the patient
    query.prepare("SELECT * FROM TClient WHERE `Id` = :id");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        printf("Error getting patient %d! %s\n", id, query.lastError().text().toStdString().c_str());
        return NULL;
    }

    if(query.next())
        patient = new Patient(id, query.value("Nom").toString(), query.value("Prénom").toString(), query.value("Adresse").toString(), query.value("Ville").toString(), query.value("CP").toString(), QDate::fromString(query.value("DateRdv").toString(), "yyyy-MM-dd"), QTime::fromString(query.value("DureeRdv").toString()), query.value("Priorite").toString(), resources, query.value("Commentaire").toString(), query.value("Tel").toString());

    return patient;
}

Staff * DBConnect::getStaff(int id, bool logPass)
{
    QSqlQuery query;
    Staff * staff = nullptr;

    //Get the staff member
    if(logPass)
        query.prepare("SELECT TRessource.Id, TRessource.Nom, TRessource.Prenom, TType.Id, TType.Label, TCompte.Login, TCompte.Mdp "
                      "FROM TRessource "
                      "INNER JOIN TType ON TRessource.IdType = TType.Id "
                      "INNER JOIN TCompte ON TCompte.IdRessource = TRessource.Id "
                      "WHERE `Id` = :id");
    else
        query.prepare("SELECT TRessource.Id, TRessource.Nom, TRessource.Prenom, TType.id, TType.Label "
                      "FROM TRessource "
                      "INNER JOIN TType ON TRessource.IdType = TType.Id "
                      "WHERE `Id` = :id");

    query.bindValue(":id", id);
    if(!query.exec())
    {
        printf("Error getting staff %d, %s! %s\n", id, logPass ? "true" : "false", query.lastError().text().toStdString().c_str());
        return NULL;
    }

    if(query.next()){
        if(logPass)
            staff = new Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(2).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString());
        else
            staff = new Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toString());
    }

    return staff;
}

QList<RessourceType *> * DBConnect::getTypes()
{
    QList<RessourceType *> * list = new QList<RessourceType *>();
    QSqlQuery query;
    if(!query.exec("SELECT Id, Label FROM TType ORDER BY Label;"))
    {
        printf("Error getting types! %s\n", query.lastError().text().toStdString().c_str());
        return NULL;
    }

    while(query.next())
    {
        (*list) << new RessourceType(query.value("Id").toInt(), query.value("Label").toString());
    }
    return list;
}

RessourceType * DBConnect::getType(int id)
{
    QSqlQuery query;
    query.prepare("SELECT Id, Label FROM TType WHERE Id = :id;");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        printf("Error getting types! %s\n", query.lastError().text().toStdString().c_str());
        return NULL;
    }

    if(query.next())
    {
        return new RessourceType(query.value("Id").toInt(), query.value("Label").toString());
    }
    return nullptr;
}

bool DBConnect::logUser(QString &user, QString &pass)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM TCompte WHERE Login = :login AND MdP = :mdp");
    query.bindValue(":login", user);
    query.bindValue(":mdp", pass);
    if(!query.exec())
    {
        printf("Error getting login state! %s\n", query.lastError().text().toStdString().c_str());
        return false;
    }

    return query.next();
}

bool DBConnect::addPatient(Patient * patient)
{
    if(patient == nullptr)
        return false;

    QSqlQuery query;
    query.prepare("INSERT INTO TClient (Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) "
                  "VALUES ((SELECT max(Id) +1 FROM TClient), :firstName, :lastName, :address, :city, :postal, :comm, :tel, :date, :dura, :prio);");
    query.bindValue(":lastName", patient->getLastName());
    query.bindValue(":firstName", patient->getFirstName());
    query.bindValue(":address", patient->getAddress());
    query.bindValue(":city", patient->getCity());
    query.bindValue(":postal", patient->getPostalCode());
    query.bindValue(":comm", patient->getComment());
    query.bindValue(":tel", patient->getPhone());
    query.bindValue(":date", patient->getDayOfConsultation().toString("yyyy-MM-dd"));
    query.bindValue(":dura", patient->getDurationInMin());
    query.bindValue(":prio", patient->getPriority());

    if(!query.exec())
        return false;

    QList<RessourceType *> * resources = patient->getResources();
    for(int i = 0; i < resources->size(); i++){
        QSqlQuery query2;
        query2.prepare("INSERT INTO TRdv (Id, IdClient, IdRessource) "
                       "VALUES ((SELECT max(Id) +1 FROM TRdv), (SELECT max(Id) FROM TClient), :idressources)");
        query2.bindValue(":idressource", "" + resources->at(i)->getId());
        if(!query2.exec())
            return false;
    }

    return true;
}

bool DBConnect::addStaff(Staff * staff)
{
    if(staff == nullptr)
        return false;

    QSqlQuery query;
    query.prepare("INSERT INTO TRessource (Id, Nom, Prenom, Type) "
                  "VALUES ((SELECT max(Id) +1 FROM TRessource), :firstName, :lastName, :type);");
    query.bindValue(":lastName", staff->getLastName());
    query.bindValue(":firstName", staff->getFirstName());
    query.bindValue(":address", staff->getRessourceType().getId());

    return query.exec();
}
