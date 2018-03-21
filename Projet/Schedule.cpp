#include "Schedule.h"

Schedule::Schedule(QList<Staff *> * list)
{
    qInfo() << "Creating schedule";
	listTimeLine = QList<TimeLine *>();
	for(int i = 0; i < list->size(); i++)
		listTimeLine.append(new TimeLine(list->at(i)));
}

Schedule::~Schedule()
{
    qInfo() << "Destroying schedule";
	for(int i = 0; i < listTimeLine.size(); i++)
		delete listTimeLine.at(i);
}

bool Schedule::addCustomer(Customer * customer)
{
    if(customer == nullptr)
        return false;

    QList<TimeLine *> * appropriatedTimeLines = getAppropriatedTimeLines(customer);

    int endHour = 0;

    for(int i = 0; i < appropriatedTimeLines->size(); i++){
        endHour = appropriatedTimeLines->at(i)->addCustomer(customer, std::max(endHour, appropriatedTimeLines->at(i)->getNextHour()));
    }

    delete appropriatedTimeLines;

	return true;
}

QList<TimeLine *> * Schedule::getAppropriatedTimeLines(Customer * customer)
{
    QList<TimeLine *> * appropriatedTimeLines = new QList<TimeLine *>();
    auto resources = customer->getResources();

    for(int i = 0; i < listTimeLine.size(); i++)
        for(int j = 0; j < resources->size(); j++)
            if(listTimeLine.at(i)->getStaff()->getId() == resources->at(j)->getId())
                appropriatedTimeLines->append(listTimeLine.at(i));

    return appropriatedTimeLines;
}


TimeLine * Schedule::getNextTimeLine(int idResource)
{
	TimeLine * timeLine = nullptr;
	
	for(int i = 0; i < listTimeLine.size(); i++)
	{
        if(listTimeLine.at(i)->getStaff()->getId() == idResource)
		{
			if(timeLine == nullptr)
				timeLine = listTimeLine.at(i);
			else if(listTimeLine.at(i)->getNextHour() < timeLine->getNextHour())
				timeLine = listTimeLine.at(i);
		}
	}
	
	return timeLine;
}

QString Schedule::toHtmlString()
{
	QString text("");
	
	for(int i = 0; i < listTimeLine.size(); i++)
	{
		TimeLine timeLine = *listTimeLine.at(i);
		if(timeLine.size() == 0)
			continue;
        text += timeLine.getStaff()->getDescription() + "\n";
		
		for(int j = 0; j < timeLine.size(); j++)
		{
            QString hour = QString("%1h%2 - %3h%4").arg(8 + timeLine.getStartHour(j) / 60, 2, 10, QChar('0')).arg(timeLine.getStartHour(j) % 60, 2, 10, QChar('0')).arg(8 + timeLine.getEndHour(j) / 60, 2, 10, QChar('0')).arg(timeLine.getEndHour(j) % 60, 2, 10, QChar('0'));
			text += "\t" + hour + " : " + timeLine.getCustomer(j)->getFirstName() + " " + timeLine.getCustomer(j)->getLastName() + "\n";
		}
	}
	
	return text;
}
