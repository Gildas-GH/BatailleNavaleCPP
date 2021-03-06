#ifndef CARMADA_H
#define CARMADA_H

#include "BiblioStd.h"
#include "CBateau.h"

class CArmada
{

private:
    vector<CBateau> m_listeBateaux; // la collection de bateaux qui est VIDE au départ

public:
    CBateau *getBateau(int i);          // Accesseur : renvoie (par pointeur) le bateau qui se trouve à l'index i dans le tableau (0 <= i < taille)
    void ajouterBateau(CBateau &unBat); // Ajoute un bateau dans la structure
    bool placerAleatoirement();         // Place aléatoirement TOUS les bateaux de la flottille à des positions compatibles avec les dimensions de la grille
    void getArmadaFromFile();           // Créer une armada depuis d'un fichier flotille.txt
    int getEffectifTotal();             // Renvoie le nombre total de bateaux de l'armada
    int getNbreTotCases();              // Accesseur : renvoie le nombre total de cases occupées par l'armada
    int getEffectif();                  // Renvoie le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie sur l'eau)
};

#endif
