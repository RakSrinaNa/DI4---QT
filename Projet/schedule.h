#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QList>

#include "staff.h"
#include "patient.h"
#include "timeline.h"

class Schedule
{
private:
    QList<Staff *> * listStaff;
    QList<TimeLine *> * listTimeLine;

public:
    Schedule();
};

#endif // SCHEDULE_H
