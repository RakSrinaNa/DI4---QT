#include "DBConnect.h"

DBConnect::DBConnect()
{
	qInfo() << "Creating DBConnect";
	db = QSqlDatabase::database();

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
			qDebug() << "Error opening DB!\n";
			throw std::exception();
		}
	}
	else
	{
		qDebug() << db.lastError().text();
		qDebug() << "Error getting DB!\n";
		throw std::exception();
	}
}

DBConnect::~DBConnect()
{
	qInfo() << "Destroying DBConnect";
	db.close();
	QSqlDatabase::removeDatabase("QSQLITE");
}

QSqlDatabase &DBConnect::getDB()
{
	return db;
}

Customer * DBConnect::getCustomer(int id)
{
	qInfo() << "Getting customer with ID " << id;
	QSqlQuery query;
	Customer * customer = nullptr;
	auto * resources = new QList<Staff *>();

	//Get the resources of the customer
	query.prepare("SELECT TRessource.Id "
				  "FROM TClient "
				  "INNER JOIN TRdv ON TClient.Id = TRdv.IdClient "
				  "INNER JOIN TRessource ON TRessource.Id = TRdv.IdRessource "
				  "WHERE TClient.Id = :id;");

	query.bindValue(":id", id);

	if(!query.exec())
	{
		delete resources;
		qWarning() << "Error getting customer's resources " << id << ", " << query.lastError().text();
		return nullptr;
	}

	while(query.next())
	{
		(*resources) << (getStaff(query.value(0).toInt()));
	}

	//Get the rest of the customer
	query.prepare("SELECT * FROM TClient WHERE `Id` = :id");
	query.bindValue(":id", id);
	if(!query.exec())
	{
		for(int i = 0; i < resources->size(); i++)
			delete resources->at(i);
		delete resources;
		qWarning() << "Error getting customer " << id << ", " << query.lastError().text();
		return nullptr;
	}

	if(query.next())
		customer = new Customer(id, query.value("Nom").toString(), query.value("Prenom").toString(), query.value("Adresse").toString(), query.value("Ville").toString(), query.value("CP").toString(), QDate::fromString(query.value("DateRdv").toString(), "yyyy-MM-dd"), QTime(0, 0).addSecs(query.value("DureeRdv").toInt() * 60), query.value("Priorite").toString(), resources, query.value("Commentaire").toString(), query.value("Tel").toString());

	return customer;
}

Staff * DBConnect::getStaff(int id, bool logPass)
{
	qInfo() << "Getting staff with ID " << id;
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
		qWarning() << "Error getting staff " << id << ", " << (logPass ? "true" : "false") << "! " << query.lastError().text();
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
	qInfo() << "Getting resources types";
	auto * resourceList = new QList<ResourceType *>();
	QSqlQuery query;
	if(!query.exec("SELECT Id, Label FROM TType ORDER BY Label;"))
	{
		delete resourceList;
		qWarning() << "Error getting types! " << query.lastError().text();
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
	qInfo() << "Getting resource type with ID " << id;
	QSqlQuery query;
	query.prepare("SELECT Id, Label FROM TType WHERE Id = (:id);");
	query.bindValue(":id", id);
	if(!query.exec())
	{
		qWarning() << "Error getting types! " << query.lastError().text();
		return nullptr;
	}

	if(query.next())
	{
		ResourceType * r = new ResourceType(query.value("Id").toInt(), query.value("Label").toString());
		return r;
	}

	return nullptr;
}

ResourceType * DBConnect::getType(QString name)
{
	qInfo() << "Getting resource type with name " << name;
	QSqlQuery query;
	query.prepare("SELECT Id, Label FROM TType WHERE Label = (:name);");
	query.bindValue(":name", name);
	if(!query.exec())
	{
		qWarning() << "Error getting types! " << query.lastError().text();
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
	qInfo() << "Trying to log user " << user;
	QSqlQuery query;
	query.prepare("SELECT * FROM TCompte WHERE Login = (:login) AND MdP = (:mdp)");
	query.bindValue(":login", user);
	query.bindValue(":mdp", pass);
	if(!query.exec())
	{
		qWarning() << "Error getting login state! " << query.lastError().text();
		return false;
	}

	return query.next();
}

bool DBConnect::addCustomer(Customer * customer)
{
	qInfo() << "Adding customer";
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
	qInfo() << "Adding staff";
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
	qInfo() << "Getting customers for date " << date.toString();
	auto * listCustomers = new QList<Customer *>();

	QSqlQuery query;
	query.prepare("SELECT * FROM TClient WHERE DateRdv = :date ORDER BY (Priorite *100 + (SELECT count(*) FROM TRdv WHERE IdClient = TClient.Id) *10 + DureeRdv);");
	query.bindValue(":date", date.toString("yyyy-MM-dd"));

	if(!query.exec())
		qWarning() << "Error getting client from date";
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
	qInfo() << "Getting all staff";
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
	qInfo() << "Getting all staff of type " << id;
	auto * listStaff = new QList<Staff *>();

	QSqlQuery query;
	query.prepare("SELECT TRessource.Id, TRessource.IdType "
				  "FROM TRessource "
				  "WHERE TRessource.IdType = :id;");
	query.bindValue(":id", id);
	if(query.exec())
	{
		while(query.next())
		{
			Staff * staff = getStaff(query.value(0).toLongLong(), false);
			if(staff != nullptr)
				*listStaff << staff;
		}
	}

	return listStaff;
}

bool DBConnect::changeResourceName(int ID, QString name)
{
	qInfo() << "Changing name to '" << name << "' for resource " << ID;
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

bool DBConnect::changeStaffResource(int ID, int rID)
{
	ResourceType * type = getType(rID);
	if(type == nullptr)
		return false;
	delete type;
	QSqlQuery query;
	query.prepare("UPDATE TRessource "
				  "SET IdType = :rid "
				  "WHERE Id = :id;");
	query.bindValue(":id", ID);
	query.bindValue(":rid", rID);
	return query.exec();
}

bool DBConnect::removeStaff(int ID)
{
	qInfo() << "Removing staff " << ID;
	QSqlQuery query;
	query.prepare("DELETE FROM TRdv "
				  "WHERE IdRessource = :id;");
	query.bindValue(":id", ID);
	query.exec();

	QSqlQuery query3;
	query3.prepare("DELETE FROM TCompte "
				  "WHERE IdRessource = :id;");
	query3.bindValue(":id", ID);
	query3.exec();

	QSqlQuery query2;
	query2.prepare("DELETE FROM TRessource "
				  "WHERE Id = :id;");
	query2.bindValue(":id", ID);
	return query2.exec();
}

bool DBConnect::removeResourceType(int ID)
{
	bool result = true;

	if(removeAllStaffOfType(ID))
	{
		QSqlQuery query;
		query.prepare("DELETE FROM TType "
					  "WHERE Id = :id;");
		query.bindValue(":id", ID);
		result &= query.exec();
	}

	return result;
}

bool DBConnect::removeAllStaffOfType(int ID)
{
	qInfo() << "Removing resource type " << ID;
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
