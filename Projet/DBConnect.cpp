#include "DBConnect.h"

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
			qDebug() << "Erreur à l'ouverture de la base !\n";
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

DBConnect::~DBConnect()
{
	db.close();
	QSqlDatabase::removeDatabase("QSQLITE");
}

QSqlDatabase &DBConnect::getDB()
{
	return db;
}

Customer * DBConnect::getCustomer(int id)
{
	QSqlQuery query;
	Customer * customer = nullptr;
	auto * resources = new QList<Staff *>();
	
	//Get the resources of the customer
	query.prepare("SELECT * "
	              "FROM TClient "
	              "INNER JOIN TRdv ON TClient.Id = TRdv.IdClient "
	              "INNER JOIN TRessource ON TRessource.Id = TRdv.IdRessource "
	              "WHERE TClient.Id = :id;");
	
	query.bindValue(":id", id);
	
	if(!query.exec())
	{
		std::cout << "Error getting customer's ressources " << id << ", " << query.lastError().text().toStdString() << std::endl;
		return nullptr;
	}
	
	while(query.next())
	{
		(*resources) << (getStaff(query.value("IdType").toLongLong()));
	}
	
	//Get the rest of the customer
	query.prepare("SELECT * FROM TClient WHERE `Id` = :id");
	query.bindValue(":id", id);
	if(!query.exec())
	{
		std::cout << "Error getting customer " << id << ", " << query.lastError().text().toStdString() << std::endl;
		return nullptr;
	}
	
	if(query.next())
        customer = new Customer(id, query.value("Nom").toString(), query.value("Prenom").toString(), query.value("Adresse").toString(), query.value("Ville").toString(), query.value("CP").toString(), QDate::fromString(query.value("DateRdv").toString(), "yyyy-MM-dd"), QTime(0, 0).addSecs(query.value("DureeRdv").toInt() * 60), query.value("Priorite").toString(), resources, query.value("Commentaire").toString(), query.value("Tel").toString());

	return customer;
}

Staff * DBConnect::getStaff(int id, bool logPass)
{
	QSqlQuery query;
	Staff * staff = nullptr;
	
	//Get the staff member
	query.prepare("SELECT TRessource.Id, TRessource.Nom, TRessource.Prenom, TType.Id, TType.Label, TCompte.Login, TCompte.Mdp "
	              "FROM TRessource "
	              "INNER JOIN TType ON TRessource.IdType = TType.Id "
	              "LEFT JOIN TCompte ON TCompte.IdRessource = TRessource.Id "
	              "WHERE TRessource.Id = :id;");
	
	query.bindValue(":id", id);
	
	if(!query.exec())
	{
		std::cout << "Error getting staff " << id << ", " << (logPass ? "true" : "false") << "! " << query.lastError().text().toStdString() << std::endl;
		return nullptr;
	}
	
	if(query.next())
	{
		if(logPass)
			staff = new Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString());
		else
			staff = new Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toString());
	}
	
	return staff;
}

QList<ResourceType *> * DBConnect::getTypes()
{
	auto * resourceList = new QList<ResourceType *>();
	QSqlQuery query;
	if(!query.exec("SELECT Id, Label FROM TType ORDER BY Label;"))
	{
		std::cout << "Error getting types! " << query.lastError().text().toStdString().c_str() << std::endl;
		return nullptr;
	}
	
	while(query.next())
	{
		(*resourceList) << new ResourceType(query.value("Id").toInt(), query.value("Label").toString());
	}
	return resourceList;
}

ResourceType * DBConnect::getType(int id)
{
	QSqlQuery query;
	query.prepare("SELECT Id, Label FROM TType WHERE Id = (:id);");
	query.bindValue(":id", id);
	if(!query.exec())
	{
		std::cout << "Error getting types! " << query.lastError().text().toStdString() << std::endl;
		return nullptr;
	}
	
	if(query.next())
	{
		ResourceType * r = new ResourceType(query.value("Id").toInt(), query.value("Label").toString());
		return r;
	}
	
	return nullptr;
}

bool DBConnect::logUser(QString &user, QString &pass)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM TCompte WHERE Login = (:login) AND MdP = (:mdp)");
	query.bindValue(":login", user);
	query.bindValue(":mdp", pass);
	if(!query.exec())
	{
		std::cout << "Error getting login state! " << query.lastError().text().toStdString().c_str() << std::endl;
		return false;
	}
	
	return query.next();
}

bool DBConnect::addCustomer(Customer * customer)
{
	if(customer == nullptr)
		return false;
	
	QSqlQuery query;
	query.prepare("INSERT INTO TClient (Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) "
	              "VALUES ((SELECT max(Id) +1 FROM TClient), :firstName, :lastName, :address, :city, :postal, :comm, :tel, :date, :dura, :prio);");
	query.bindValue(":lastName", customer->getLastName());
	query.bindValue(":firstName", customer->getFirstName());
	query.bindValue(":address", customer->getAddress());
	query.bindValue(":city", customer->getCity());
	query.bindValue(":postal", customer->getPostalCode());
	query.bindValue(":comm", customer->getComment());
	query.bindValue(":tel", customer->getPhone());
	query.bindValue(":date", customer->getDayOfConsultation().toString("yyyy-MM-dd"));
	query.bindValue(":dura", customer->getDurationInMin());
	query.bindValue(":prio", customer->getPriority());
	
	if(!query.exec())
		return false;
	
    int lastId = query.lastInsertId().toInt();

	QList<Staff *> * resources = customer->getResources();
	for(auto resource : *resources)
	{
		QSqlQuery query2;
		query2.prepare("INSERT INTO TRdv (Id, IdClient, IdRessource) "
                       "VALUES ((SELECT max(Id) +1 FROM TRdv), :lastid, :idressource)");
        query2.bindValue(":lastid", lastId);
        query2.bindValue(":idressource", resource->getId());
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
	query.prepare("INSERT INTO TRessource (Id, Nom, Prenom, IdType) "
                  "VALUES ((SELECT max(Id) +1 FROM TRessource), (:lastName), (:firstName), (:type));");
	query.bindValue(":lastName", staff->getLastName());
	query.bindValue(":firstName", staff->getFirstName());
	query.bindValue(":type", staff->getResourceType()->getId());

    if(!query.exec())
        return false;

    if(staff->getResourceType()->getName() == "Informaticien"){
        QSqlQuery query2;
        query2.prepare("INSERT INTO TCompte (Id, IdRessource, Login, MdP) "
                      "VALUES ((SELECT max(Id) +1 FROM TCompte), (SELECT max(Id) FROM TRessource), :log, :mdp)");
        query2.bindValue(":log", staff->getLogin());
        query2.bindValue(":mdp", staff->getPassword());

        if(!query2.exec())
            return false;
    }
	
    return true;
}

QList<Customer *> * DBConnect::getClientsFromDate(QDate date)
{
	auto * listCustomers = new QList<Customer *>();
	
	QSqlQuery query;
	query.prepare("SELECT * FROM TClient WHERE DateRdv = :date ORDER BY Priorite *100 + (SELECT count(*) FROM TRdv WHERE IdClient = TClient.id) *10 + DureeRdv;");
	query.bindValue(":date", date.toString("yyyy-MM-dd"));
	
	if(!query.exec())
		std::cout << "Error" << std::endl;
	else
		while(query.next())
		{
			Customer * customer = getCustomer(query.value("Id").toInt());
			if(customer != nullptr)
				*listCustomers << customer;
		}
	
	return listCustomers;
}

QList<Staff *> * DBConnect::getAllStaff()
{
	auto * listStaff = new QList<Staff *>();
	
	QSqlQuery query;
	query.prepare("SELECT Id FROM TRessource");
	if(query.exec())
	{
		while(query.next())
		{
			Staff * staff = getStaff(query.value("Id").toInt(), false);
			if(staff != nullptr)
				*listStaff << staff;
		}
	}
	
	return listStaff;
}

QList<Staff *> * DBConnect::getStaffByType(int id)
{
	auto * listStaff = new QList<Staff *>();
	
	QSqlQuery query;
	query.prepare("SELECT TRessource.Id, TRessource.IdType "
	              "FROM TRessource "
	              "WHERE TRessource.IdType = :id;");
	query.bindValue(":id", id);
	if(query.exec())
	{
        std::cout << "ID source : " << id << std::endl;
        std::cout << "Query size : " << query.size() << std::endl;

		while(query.next())
        {
            Staff * staff = getStaff(query.value("TRessource.Id").toInt(), false);
            if(staff != nullptr)
                *listStaff << staff;
		}
	}
	
	return listStaff;
}

bool DBConnect::changeResourceName(int ID, QString name)
{
    QSqlQuery query;
    query.prepare("UPDATE TType "
                  "SET Label = :name "
                  "WHERE Id = :id;");
    query.bindValue(":id", ID);
    query.bindValue(":name", name);
    return query.exec();
}

bool DBConnect::changeStaffName(int ID, QString firstName, QString lastName)
{
    QSqlQuery query;
    query.prepare("UPDATE TRessource "
                  "SET Nom = :lastName, Prenom = :firstName "
                  "WHERE Id = :id;");
    query.bindValue(":id", ID);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    return query.exec();
}

bool DBConnect::removeStaff(int ID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TRdv "
                  "WHERE IdRessource = :id;");
    query.bindValue(":id", ID);
    query.exec();

    QSqlQuery query2;
    query2.prepare("DELETE FROM TRessource "
                  "WHERE Id = :id;");
    query2.bindValue(":id", ID);
    return query2.exec();
}

bool DBConnect::removeResourceType(int ID)
{
    bool result = true;
    QList<Staff *> * staffs = this->getStaffByType(ID);

    QSqlDatabase::database().transaction();
    for(int i = 0; i < staffs->count(); i++)
    {
        Staff * staff = staffs->at(i);
        result &= this->removeStaff(staff->getId());
        delete staff;
    }
    delete staffs;

    if(result)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM TRessource "
                      "WHERE Id = :id;");
        query.bindValue(":id", ID);
        result &= query.exec();
    }

    if(!result)
    {
        QSqlDatabase::database().rollback();
    }
    else
    {
        QSqlDatabase::database().commit();
    }

    return result;
}
