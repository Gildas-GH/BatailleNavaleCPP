#include "CArmada.h"

// Ajoute un bateau dans m_listeBateaux avec la méthode push_back
void CArmada::ajouterBateau(CBateau& unBat) {
	// TODO tests
	this->m_listeBateaux.push_back(unBat);
}

// Accesseur : renvoie (par pointeur) le bateau à l'index i (0 <= i < taille)
CBateau* CArmada::getBateau(int i) {
	if (i >= 0 && i < TAILLE_GRILLE) {
		return this->m_listeBateaux[i];
	} else {
		// TODO Exception
	}
}

// Renvoie le nombre total de bateaux de l'armada
int CArmada::getEffectifTotal() {
	return this->m_listeBateaux.size();
}

// Accesseur : renvoie le nombre total de cases occupées par l'armada
int CArmada::getNbreTotCases() {
	int total = 0;
	
	/*for (vector<CBateau>::iterator it = m_listeBateaux.begin(); it != m_listeBateaux.end(); ++it) {
        total += *it.getTaille();
    }*/

	for(auto & elem : m_listeBateaux) {
		total += elem.getTaille();
	}

	return total;
}

// Renvoie le nombre de bateaux qui ne sont pas encore coulés
int CArmada::getEffectif() {
	int total = this->m_listeBateaux.size();;

	for(auto & elem : m_listeBateaux) {
		if (elem.estCoule()) total -= 1;
	}

	return total;
}

// Lecture du fichier flotille.txt (contient la liste de tous les bateaux)
void CArmada::getArmadaFromFile() {
	// TODO
}

// Placement automatique aléatoire des bateaux. faux si le positionnement a échoué.
bool CArmada::placerAleatoirement() {
	// TODO
}

// affiche à l'écran toutes les positions des sous-marins
ostream& operator<< (ostream& os, CArmada& theA) {
	cout << "Affichage des sous marins : " << endl;
	
	for(auto & elem : theA.m_listeBateaux) {
		cout << theA << endl;
	}

	cout << "====" << endl;
}