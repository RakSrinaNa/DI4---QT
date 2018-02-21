//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_FONCTEURFINDSLOT_H
#define TP_C_FONCTEURFINDSLOT_H

#include "Slot.h"
#include "Task.h"

class FoncteurFindSlot
{
private:
	std::vector<Slot *> slots;
	bool found;
	int duration;
	Task * task;
	Ressource * ressource;
public:
	FoncteurFindSlot(int i, Task * task, Ressource * ressource);
	void asignSlots();
	void operator()(Slot * slot);
	
};

#endif //TP_C_FONCTEURFINDSLOT_H
