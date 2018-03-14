#ifndef TIMELINE_H
#define TIMELINE_H

#include "staff/Staff.h"
#include "customer/Customer.h"

class TimeLine
{
private :
	Staff * staff;
	QList<Customer *> hours;

public:
	TimeLine(Staff * staff);
	
	int getNextHour();
	
	int getTypeId();
	
	void addCustomer(Customer * customer);
};

#endif // TIMELINE_H
