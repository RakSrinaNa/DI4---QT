#include "timeline.h"

TimeLine::TimeLine(Staff *staff) : staff(staff)
{
    hours = QList<Customer *>;
}

int TimeLine::getNextHour()
{
    int time = 0;

    for(int i = 0; i < hours.size(); i++)
        time += (hours.at(i)->getDurationInMin() / 15 + (hours.at(i)->getDurationInMin() % 15 == 0 ? 0 : 15));

    return time;
}

int TimeLine::getTypeId()
{
    return staff->getRessourceType().getId();
}

void TimeLine::addCustomer(Customer * customer)
{
    hours << customer;
}
