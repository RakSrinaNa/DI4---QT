//
// Created by Thomas Couchoud on 06/02/2018.
//

#ifndef TP_C_PATIENTFONCTEUR_H
#define TP_C_PATIENTFONCTEUR_H

#include <iostream>
#include "Patient.h"

class PatientFoncteur
{
private:
	int sumD;
	int sumP;
	int countP;
	std::ostream & stream;
public:
	explicit PatientFoncteur(std::ostream & str);
	int getDuree();
	double getPriorityAverage();
	void operator()(Patient p);
};

#endif //TP_C_PATIENTFONCTEUR_H
