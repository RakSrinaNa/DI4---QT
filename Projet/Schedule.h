#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QList>

#include "iostream"

#include "Staff.h"
#include "Customer.h"
#include "Timeline.h"

class Schedule
{
private:
	QList<TimeLine *> listTimeLine;

public:
	Schedule(QList<Staff *> * list);
	
	~Schedule();
	
	bool addCustomer(Customer * customer);
	
	TimeLine * getNextTimeLine(int idResource);
	
	QString toHtmlString();
};

#endif // SCHEDULE_H
