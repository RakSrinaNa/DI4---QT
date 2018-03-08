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

Patient * DBConnect::getPatient(int id)
{
    QSqlQuery query;
    Patient * patient = nullptr;
    vector<Staff *> * resources = new vector<Staff *>;

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
        resources->push_back(getStaff(query.value("TRessource.Id").toInt()));
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
        query.prepare("SELECT TRessource.Id, TRessource.Nom, TRessource.Prenom, TType.Label "
                      "FROM TRessource "
                      "INNER JOIN TType ON TRessource.IdType = TType.Id "
                      "INNER JOIN TCompte ON TCompte.IdRessource = TRessource.Id "
                      "WHERE `Id` = :id");
    else
        query.prepare("SELECT TRessource.Id, TRessource.Nom, TRessource.Prenom, TType.Label "
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
            staff = new Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
        else
            staff = new Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString());
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

bool  DBConnect::logUser(QString &user, QString &pass)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM TCompte WHERE Login = :login AND MdP = :mdp");
    query.bindValue(":login", user);
    query.bindValue(":mdp", pass);
    if(!query.exec())
    {
        printf("Error getting login state! %s\n", query.lastError().text().toStdString().c_str());
        return NULL;
    }

    return query.next();
}
