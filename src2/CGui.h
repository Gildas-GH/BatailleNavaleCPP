#ifndef CGUI_H
#define CGUI_H

#include "BiblioStd.h"
#include "CArmada.h"
#include "CBaseJeu.h"
#include "CCoups.h"

class CGui : public CBaseJeu
{
private:
    char m_grilleJou[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1]; // Grille du joueur
    char m_grilleAdv[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1]; // Grille de l'adversaire
    CArmada *m_pArmada;                                     // Pointeur sur l'unique armada du joueur
    CCoups *m_pCoups;                                       // Pointeur sur l'unique structure d'enregistrement des tirs

public:
    CGui();                                                // Constructeur par défaut : m_pArmada et m_pCoups à NULL
    CGui(CArmada *pArmada, CCoups *pCoups);                // Constructeur qui reçoit un pointeur sur l'armada et un pointeur sur la structure d'enregistrement des tirs
    virtual ~CGui();                                       // Destructeur : destruction des zones pointées par m_pArmada et m_pCoups
    void setArmadaCoups(CArmada *pArmada, CCoups *pCoups); // Modificateur : mise à jour des attributs
    bool positionnerBateaux();                             // Méthode appelée au début du jeu pour positionner tous les bateaux sur la grille en exécutant placerAleatoirement de CArmada. Renvoie faux si le positionnement a échoué.
    pair<int, int> choisirAttaque();                       // Saisie de la coordonnée (ligne, colonne) de l'attaque (vérification obligatoire bon/mauvais après saisie de la coordonnée par l'utilisateur)
    void afficheGagne();                                   // Affiche la partie est gagnée à l'écran
    void affichePerdu();                                   // Affiche la partie est perdue à l'écran
    void remplirDeuxGrilles(ostream &os);                  // Remplie les 2 grilles du joueur
    friend ostream &operator<<(ostream &os, CGui &theG);   // Surcharge de l'opérateur << pour l'affichage des grilles. Cette fonction fait un simple appel à remplirDeuxGrilles(...) de l'objet theG.
    void afficherLaGrille(ostream &os, string jouOuAdv);   // Affichage d'une grille (joueur ou adversaire) à l'écran, c'est-à-dire affichage du contenu de m_grilleJou ou m_grilleAdv + les légendes (0...TAILLE_GRILLE-2).
    void status();
};

#endif