#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QList>

#include "staff/Staff.h"
#include "customer/Customer.h"
#include "Timeline.h"

class Schedule
{
private:
	QList<QPair<TimeLine *, int>> listTimeLine;

public:
	Schedule(QList<Staff *> * list);
	
	~Schedule();
	
	bool addCustomer(Customer * customer);
	
	TimeLine * getNextTimeLine(int id);
};

#endif // SCHEDULE_H
