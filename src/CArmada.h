/**
 * Une armada se compose d'une collection de bateaux (vector). La méthode bool placerAleatoirement()
 * place aléatoirement TOUS les bateaux de la flottille à des positions compatibles avec les
 * dimensions de la grille. On lira d'abord la liste des bateaux depuis un fichier texte, frâce
 * à la méthode getArmadaFromFile().
 */

#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"
#include "CBateau.h"

class CArmada {

    private:
        vector<CBateau> m_listeBateaux;     // Collection de bateaux, vide au départ
    
    public:
        void ajouterBateau(CBateau& unBat); // Ajoute un bateau dans m_listeBateaux avec la méthode push_back 
        
        CBateau* getBateau(int i);  // Accesseur : renvoie (par pointeur) le bateau à l'index i (0 <= i < taille)
        int getEffectifTotal();     // Renvoie le nombre total de bateaux de l'armada
        int getNbreTotCases();      // Accesseur : renvoie le nombre total de cases occupées par l'armada
        int getEffectif();          // Renvoie le nombre de bateaux qui ne sont pas encore coulés
        void getArmadaFromFile();   // Lecture du fichier flotille.txt (contient la liste de tous les bateaux)
        bool placerAleatoirement(); // Placement automatique aléatoire des bateaux. faux si le positionnement a échoué.
        
        friend ostream& operator<< (ostream& os, CArmada& theA); // affiche à l'écran toutes les positions des sous-marins

};

#endif
