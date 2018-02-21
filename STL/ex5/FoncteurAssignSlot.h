//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_FONCTEURASSIGNSLOT_H
#define TP_C_FONCTEURASSIGNSLOT_H

#include "Task.h"

class FoncteurAssignSlot
{
private:
	Task * task;
	Ressource * ressource;
public:
	FoncteurAssignSlot(Task * task, Ressource * ressource);
	void operator()(Slot * slot);
};

#endif //TP_C_FONCTEURASSIGNSLOT_H
