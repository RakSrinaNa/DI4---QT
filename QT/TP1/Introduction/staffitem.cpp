#include "staffitem.h"

StaffItem::StaffItem(QString text, Staff *staff, QListWidget *parent) : QListWidgetItem(text, parent), staff(staff)
{

}

StaffItem::StaffItem(Staff *staff, QListWidget *parent) : QListWidgetItem(parent), staff(staff)
{
    setText(staff->getDescription());
}

Staff * StaffItem::getStaff()
{
    return staff;
}
