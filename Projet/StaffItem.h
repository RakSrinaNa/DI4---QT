#ifndef STAFFITEM_H
#define STAFFITEM_H

#include <QListWidgetItem>

#include "Staff.h"

/**
 * Representation of a staff in a widget.
 */
class StaffItem : public QListWidgetItem
{
public:
	StaffItem(QString text, Staff * staff, QListWidget * parent = 0);
	
	StaffItem(Staff * staff, QListWidget * parent = 0);

    ~StaffItem();
	
	/**
	 * Get the staff memeber.
	 * @return The staff memeber.
	 */
	virtual Staff * getStaff();

private:
	Staff * staff;
};

#endif // STAFFITEM_H
