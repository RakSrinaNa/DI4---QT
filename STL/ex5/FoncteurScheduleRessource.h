//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_FONCTEURSCHEDULERESSOURCE_H
#define TP_C_FONCTEURSCHEDULERESSOURCE_H

#include "Ressource.h"
#include "Task.h"

class FoncteurScheduleRessource
{
private :
	Task * task;
public:
	void operator()(Ressource * ressource, int duration);
	
	FoncteurScheduleRessource(Task * task);
};

#endif //TP_C_FONCTEURSCHEDULERESSOURCE_H
