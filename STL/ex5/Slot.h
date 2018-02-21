//
// Created by Thomas Couchoud on 09/02/2018.
//

#ifndef TP_C_SLOT_H
#define TP_C_SLOT_H

#include "Task.h"

class Slot
{
private:
	int length;
	Task * assigned;
public:
	Slot(int length);
	
	bool isAsigned();
	
	int getLength();
	void asign(Task * task);
};

#endif //TP_C_SLOT_H
