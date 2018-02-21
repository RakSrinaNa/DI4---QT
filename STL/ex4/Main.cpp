//
// Created by Thomas Couchoud on 06/02/2018.
//

#include <vector>
#include "Patient.h"
#include "PatientFoncteur.h"
#include "SortPat.h"
#include "SortPat.h"
#include "ScoreSort.h"

using namespace std;

int main(int argc, char ** argv)
{
	vector<Patient> patients = vector<Patient>();
	patients.emplace_back("N1", "P1", "A1", "V1", "C1", 1, 1, 1, 1);
	patients.emplace_back("N2", "P2", "A2", "V2", "C2", 2, 2, 2, 2);
	
	transform(patients.begin(), patients.end(), patients.begin(), SortPat());
	
	sort(patients.begin(), patients.end(), ScoreSort());
	
	PatientFoncteur pf = for_each(patients.begin(), patients.end(), PatientFoncteur(cout));
	cout << "Durees: " << pf.getDuree() << endl;
	cout << "Moy pr: " << pf.getPriorityAverage() << endl;
	
	return 0;
}
