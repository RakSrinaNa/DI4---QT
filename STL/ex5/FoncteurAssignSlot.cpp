//
// Created by Thomas Couchoud on 09/02/2018.
//

#include "FoncteurAssignSlot.h"

using namespace std;

FoncteurAssignSlot::FoncteurAssignSlot(Task * task, Ressource * ressource) : task(task), ressource(ressource)
{
}

void FoncteurAssignSlot::operator()(Slot * slot)
{
	slot->asign(task);
	task->asigned.insert(make_pair(slot, ressource));
}
