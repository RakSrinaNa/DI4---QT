#include "StaffItem.h"

StaffItem::StaffItem(QString text, Staff * staff, QListWidget * parent) : QListWidgetItem(text, parent), staff(staff)
{
     qDebug() << "Creating staff item";
}

StaffItem::StaffItem(Staff * staff, QListWidget * parent) : QListWidgetItem(parent), staff(staff)
{
    qDebug() << "Creating staff item";
	setText(staff->getDescription());
}

StaffItem::~StaffItem()
{
    qDebug() << "Destroying staff item";
}

Staff * StaffItem::getStaff()
{
	return staff;
}
