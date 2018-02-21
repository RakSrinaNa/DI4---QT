//
// Created by Thomas Couchoud on 06/02/2018.
//

#include "PatientFoncteur.h"

using namespace std;

PatientFoncteur::PatientFoncteur(ostream &str) : sumD(0), sumP(0), countP(0), stream(str)
{
}

int PatientFoncteur::getDuree()
{
	return sumD;
}

double PatientFoncteur::getPriorityAverage()
{
	return ((double) sumP) / countP;
}

void PatientFoncteur::operator()(Patient p)
{
	sumD += p.getDureeEstimee();
	sumP += p.getPriorite();
	countP++;
	cout << p.getNom() << " " << p.getPrenom() << endl;
}
