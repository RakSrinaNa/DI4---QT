//
// Created by Thomas Couchoud on 09/02/2018.
//

#include "Slot.h"

using namespace std;

Slot::Slot(int length) : length(length)
{
	assigned = nullptr;
}

bool Slot::isAsigned()
{
	return assigned != nullptr;
}

int Slot::getLength()
{
	return length;
}

void Slot::asign(Task * task)
{
	assigned = task;
}
