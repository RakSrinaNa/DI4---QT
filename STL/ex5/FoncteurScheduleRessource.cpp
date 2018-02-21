//
// Created by Thomas Couchoud on 09/02/2018.
//

#include "FoncteurScheduleRessource.h"
#include "FoncteurFindSlot.h"
#include <vector>

using namespace std;

void FoncteurScheduleRessource::operator()(Ressource * ressource, int duration)
{
	FoncteurFindSlot ffs = for_each(ressource->slots.begin(), ressource->slots.end(), FoncteurFindSlot(duration, task, ressource));
}

FoncteurScheduleRessource::FoncteurScheduleRessource(Task * task) : task(task)
{
}
