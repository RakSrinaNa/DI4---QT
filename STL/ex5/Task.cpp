//
// Created by Thomas Couchoud on 09/02/2018.
//

#include "Task.h"

using namespace std;

Task::Task(int ID) : ID(ID)
{
	ressources = map<Ressource *, int>();
	asigned = map<Slot *, Ressource *>();
}

void Task::useRessource(Ressource * ressource, int duration)
{
	ressources.insert(make_pair(ressource, duration));
}
