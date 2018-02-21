#ifndef STAFFITEM_H
#define STAFFITEM_H

#include <QListWidgetItem>

#include <staff.h>

class StaffItem : public QListWidgetItem
{
public:
    StaffItem(QString text, Staff * staff, QListWidget * parent = 0);
    StaffItem(Staff * staff, QListWidget * parent = 0);

    virtual Staff * getStaff();

private:
    Staff * staff;
};

#endif // STAFFITEM_H
