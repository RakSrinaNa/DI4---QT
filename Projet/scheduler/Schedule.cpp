#include "Schedule.h"

Schedule::Schedule(QList<Staff *> * list)
{
    listTimeLine = QList<QPair<TimeLine *, int>>();
    for(int i = 0; i < list->size(); i++)
        listTimeLine.append(QPair<new TimeLine(list->at(i)), 0>);
}

Schedule::~Schedule()
{
    for(int i = 0; i < listTimeLine->size(); i++)
        delete listTimeLine.at(i).first;
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




    return true;
}

TimeLine * Schedule::getNextTimeLine(int id)
{
    TimeLine * timeLine = nullptr;

    for(int i = 0; i < listTimeLine.size(); i++){
        if(listTimeLine.at(i)->getTypeId() == id){
            if(timeLine == nullptr)
                timeLine = listTimeLine.at(i);
            else if(listTimeLine.at(i)->getNextHour() < timeLine->getNextHour())
                timeLine = listTimeLine.at(i);
        }
    }

    return timeLine;
}
