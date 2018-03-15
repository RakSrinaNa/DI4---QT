#include "Schedule.h"

Schedule::Schedule(QList<Staff *> * list)
{
    listTimeLine = QList<TimeLine *>();
    for(int i = 0; i < list->size(); i++)
        listTimeLine.append(new TimeLine(list->at(i)));
}

Schedule::~Schedule()
{
    for(int i = 0; i < listTimeLine.size(); i++)
        delete listTimeLine.at(i);
}

bool Schedule::addCustomer(Customer *customer)
{
    QList<TimeLine *> timeLines = QList<TimeLine *>();
    for(int i = 0; i < customer->getResources()->size(); i++){
        TimeLine * timeLine = getNextTimeLine(customer->getResources()->at(i)->getId());
        if(timeLine == nullptr)
            return false;
        timeLines << timeLine;
    }

    int endHour = 0;
    for(int i = 0; i < timeLines.size(); i++){
        endHour = timeLines.at(i)->addCustomer(customer, std::max(endHour, timeLines.at(i)->getNextHour()));
    }

    return true;
}

TimeLine * Schedule::getNextTimeLine(int idResource)
{
    TimeLine * timeLine = nullptr;

    for(int i = 0; i < listTimeLine.size(); i++){
        if(listTimeLine.at(i)->getTypeId() == idResource){
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

    for(int i = 0; i < listTimeLine.size(); i++){
        TimeLine timeLine = *listTimeLine.at(i);
        if(timeLine.size() == 0)
            continue;
        text += timeLine.getStaff()->getDescription() + "\n";

        for(int j = 0; j < timeLine.size(); j++){
            QString hour = QString("%1h%2 - %3h%4").arg(8 + timeLine.getStartHour(j) / 60).arg(timeLine.getStartHour(j) % 60).arg(8 + timeLine.getEndHour(j) / 60).arg(timeLine.getEndHour(j) % 60);
            text += "\t" + hour + " : " + timeLine.getCustomer(j)->getFirstName() + " " + timeLine.getCustomer(j)->getLastName() + "\n";
        }

    }

    return text;
}
