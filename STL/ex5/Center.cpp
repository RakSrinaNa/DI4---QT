//
// Created by Thomas Couchoud on 09/02/2018.
//

#include "Center.h"
#include "FoncteurScheduleRessource.h"

using namespace std;

Center::Center()
{
	ressources = vector<Ressource *>();
}

void Center::addRessource(Ressource * ressource)
{
	ressources.push_back(ressource);
}

void Center::scheduleTask(Task * task)
{
	for_each(task->ressources.begin(), task->ressources.end(), FoncteurScheduleRessource(task));
}
