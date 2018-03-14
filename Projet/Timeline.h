#ifndef TIMELINE_H
#define TIMELINE_H

#include "Staff.h"
#include "Customer.h"

class TimeLine
{
private :
    Staff * staff;
    QList<QPair<Customer *, int>> hours;

public:
    TimeLine(Staff * staff);
    ~TimeLine();

	int getNextHour();
	int getTypeId();
    Staff * getStaff();
    Customer * getCustomer(int index);
    int getStartHour(int index);
    int getEndHour(int index);
    int size();
    int addCustomer(Customer * customer, int duration);
};

#endif // TIMELINE_H
