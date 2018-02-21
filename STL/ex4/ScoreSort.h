//
// Created by Thomas Couchoud on 06/02/2018.
//

#ifndef TP_C_SCORESORT_H
#define TP_C_SCORESORT_H

#include "Patient.h"

class ScoreSort
{
public:
	ScoreSort();
	bool operator()(Patient & p1, Patient & p2);
};

#endif //TP_C_SCORESORT_H
