#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QList>

#include "Staff.h"
#include "Customer.h"
#include "timeline.h"

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
