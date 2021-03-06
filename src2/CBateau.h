#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"

class CBateau
{
private:
    int m_taille; // Taille du bateau
    string m_nom; // Nom du bateau
    pair<int, int> m_position;
    bool *m_pDegats; // tableau des dégâts de taille m_taille (case à faux si pas de dégât)

public:
    CBateau();                                              // Constructeur par défaut : "neant", (0,0), 0, NULL
    CBateau(string n, pair<int, int> p, int t);             // Constructeur, le bateau n'a encore aucune case touchée (m_pDegats à faux partout)
    CBateau(const CBateau &b);                              // Copie constructeur
    ~CBateau();                                             // Destructeur
    bool getDegats(int i);                                  // Renvoie vrai si la case numéro i du bateau est touchée ( 0 <= i < m_taille )
    string getNom();                                        // Accesseur
    int getTaille();                                        // Accesseur
    pair<int, int> getPosition();                           // Accesseur
    void setPosition(int i, int j);                         // Modifie la position du bateau sur la grille en ième ligne, jème colonne (nouveau point d'ancrage)
    bool estCoule();                                        // Renvoie vrai si le bateau est coulé
    bool tirAdverse(pair<int, int> p);                      // Tir adverse : renvoie vrai si la coordonnée passée // en paramètre est un tir victorieux (une case du bateau est touchée). Si le tir est victorieux il doit // être marqué dans le tableau m_pDegats.
    friend ostream &operator<<(ostream &os, CBateau &theB); // Surcharge de l'opérateur << pour afficher à l'écran les caractéristiques du bateau
    CBateau &operator=(const CBateau &other);               // Surcharge de l'opérateur = pour copier un CBateau
};

#endif