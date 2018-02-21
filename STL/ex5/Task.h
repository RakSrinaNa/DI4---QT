//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_TASK_H
#define TP_C_TASK_H

#include <vector>
#include <map>
#include "Ressource.h"

class Task
{
private:
	int ID;
public:
	explicit Task(int ID);
	void useRessource(Ressource * ressource, int duration);
	std::map<Ressource *, int> ressources;
	std::map<Slot *, Ressource *> asigned;
};

#endif //TP_C_TASK_H
