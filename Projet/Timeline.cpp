#include "Timeline.h"

TimeLine::TimeLine(Staff * staff) : staff(staff)
{
	hours = QList<QPair<Customer *, int>>();
}

TimeLine::~TimeLine()
{
}

int TimeLine::getNextHour()
{
	int time = 0;
	
	if(hours.size() > 0)
	{
		QPair<Customer *, int> lastCustomer = (hours.at(hours.size() - 1));
        time += lastCustomer.second + (lastCustomer.first->getDurationInMin() / 15)*15 + (lastCustomer.first->getDurationInMin() % 15 == 0 ? 0 : 15);
	}
	
	return time;
}

int TimeLine::getTypeId()
{
	return getStaff()->getResourceType()->getId();
}

Staff * TimeLine::getStaff()
{
	return staff;
}

Customer * TimeLine::getCustomer(int index)
{
	return hours.at(index).first;
}

int TimeLine::getStartHour(int index)
{
	return hours.at(index).second;
}

int TimeLine::getEndHour(int index)
{
	return hours.at(index).second + getCustomer(index)->getDurationInMin();
}

int TimeLine::size()
{
	return hours.size();
}

int TimeLine::addCustomer(Customer * customer, int duration)
{
	hours << QPair<Customer *, int>(customer, duration);
	return getNextHour();
}
