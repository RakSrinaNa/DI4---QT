//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_RESSOURCE_H
#define TP_C_RESSOURCE_H

#include <string>
#include <vector>
#include "Slot.h"

class Ressource
{
private:
	std::string name;
	int ID;
public:
	Ressource(int slotCount, int duration);
	std::vector<Slot *> slots;
};


#endif //TP_C_RESSOURCE_H
