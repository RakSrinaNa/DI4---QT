//
// Created by Thomas Couchoud on 09/02/2018.
//

#include "FoncteurFindSlot.h"
#include "FoncteurAssignSlot.h"

using namespace std;

void FoncteurFindSlot::operator()(Slot * slot)
{
	if(found)
		return;
	if(slot->isAsigned())
	{
		slots.clear();
	}
	else
	{
		slots.push_back(slot);
		if(slots.size() * slot->getLength() >= duration)
		{
			found = true;
		}
	}
}

FoncteurFindSlot::FoncteurFindSlot(int i, Task * task, Ressource * ressource) : task(task), duration(i), found(false), ressource(ressource)
{
	slots = vector<Slot *>();
}

void FoncteurFindSlot::asignSlots()
{
	if(found)
	{
		for_each(slots.begin(), slots.end(), FoncteurAssignSlot(task, ressource));
	}
}
