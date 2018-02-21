//
// Created by Thomas Couchoud on 06/02/2018.
//

#include "Patient.h"

using namespace std;

Patient::Patient(const string &nom, const string &prenom, const string &adresse, const string &ville, const string &commentaire, int telephone, int codePostal, int dureeEstimee, int priorite) : nom(nom), prenom(prenom), adresse(adresse), ville(ville), commentaire(commentaire), telephone(telephone), codePostal(codePostal), dureeEstimee(dureeEstimee), priorite(priorite)
{
	ressources = vector<int>();
}


int Patient::getDureeEstimee() const
{
	return dureeEstimee;
}

int Patient::getPriorite() const
{
	return priorite;
}

const std::string &Patient::getNom() const
{
	return nom;
}

const std::string &Patient::getPrenom() const
{
	return prenom;
}

vector<int> & Patient::getRessources()
{
	return ressources;
}

Patient &Patient::operator=(Patient const& p)
{
	nom = p.nom;
	prenom = p.prenom;
	adresse = p.adresse;
	ville = p.ville;
	commentaire = p.commentaire;
	telephone = p.telephone;
	codePostal = p.codePostal;
	dureeEstimee = p.dureeEstimee;
	ressources = p.ressources;
	return *this;
}


