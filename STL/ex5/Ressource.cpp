//
// Created by Thomas Couchoud on 09/02/2018.
//

#include <string>
#include "Ressource.h"
#include "Slot.h"

using namespace std;

Ressource::Ressource(int slotCount, int duration)
{
	slots = vector<Slot *>(slotCount, new Slot(duration));
}
