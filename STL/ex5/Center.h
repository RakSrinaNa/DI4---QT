//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_CENTER_H
#define TP_C_CENTER_H

#include "Ressource.h"
#include "Task.h"

class Center
{
private:
	std::vector<Ressource *> ressources;
public:
	Center();
	void addRessource(Ressource * ressource);
	void scheduleTask(Task * task);
};

#endif //TP_C_CENTER_H
