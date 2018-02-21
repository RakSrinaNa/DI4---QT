//
// Created by Thomas Couchoud on 06/02/2018.
//

#ifndef TP_C_PATIENT_H
#define TP_C_PATIENT_H

#include <string>
#include <vector>

class Patient
{
private:
	std::string nom;
	std::string prenom;
	std::string adresse;
	std::string ville;
	std::string commentaire;
	
	int telephone;
	int codePostal;
	int dureeEstimee;
	int priorite;
	
	std::vector<int> ressources;

public:
	Patient(const std::string &nom, const std::string &prenom, const std::string &adresse, const std::string &ville, const std::string &commentaire, int telephone, int codePostal, int dureeEstimee, int priorite);
	
	int getDureeEstimee() const;
	
	int getPriorite() const;
	
	const std::string &getNom() const;
	
	const std::string &getPrenom() const;
	
	std::vector<int> &getRessources();
	
	Patient & operator=(Patient const& p);
};

#endif //TP_C_PATIENT_H
