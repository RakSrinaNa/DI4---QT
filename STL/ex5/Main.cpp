//
// Created by Thomas Couchoud on 06/02/2018.
//

#include <vector>
#include "Center.h"
#include "Task.h"

using namespace std;

int main(int argc, char ** argv)
{
	Center c = Center();
	
	Ressource r1 = Ressource(10, 15);
	Ressource r2 = Ressource(10, 15);
	
	c.addRessource(&r1);
	c.addRessource(&r2);
	
	Task t1 = Task(1);
	t1.useRessource(&r2, 35);
	
	Task t2 = Task(2);
	t2.useRessource(&r1, 26);
	t2.useRessource(&r2, 23);
	
	Task t3 = Task(3);
	t3.useRessource(&r1, 53);
	t3.useRessource(&r2, 27);
	
	Task t4 = Task(4);
	t4.useRessource(&r2, 24);
	
	c.scheduleTask(&t1);
	c.scheduleTask(&t2);
	c.scheduleTask(&t3);
	c.scheduleTask(&t4);
	
	return 0;
}
