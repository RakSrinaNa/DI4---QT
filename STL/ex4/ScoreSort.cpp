//
// Created by Thomas Couchoud on 06/02/2018.
//

#include "ScoreSort.h"
#include "vector"

using namespace std;

ScoreSort::ScoreSort() = default;

bool ScoreSort::operator()(Patient & p1, Patient & p2)
{
	long s1 = p1.getPriorite() * 100 + p1.getRessources().size() * 10 + p1.getDureeEstimee();
	long s2 = p2.getPriorite() * 100 + p2.getRessources().size() * 10 + p2.getDureeEstimee();
	return s1 > s2;
}
