/*
 * Un bateau est caractérisé par le nombre de cases (m_taille) qu'il occupe
 * sur la grille, par un nom (porte-avion, croiseur, ...) et par le point de
 * départ de sa position HORIZONTALE sur la grille (appelé point d'ancrage du
 * bateau sur la grille) : pair<int,int> m_position, (0, 0) correspondant à
 * la case en haut à gauche sur la grille. Il mémorise également dans un
 * tableau de booléens les dégâts occasionnés sur le bateau (une case est à
 * faux si elle n'est pas touchée par un tir adverse).
 */

#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"

class CBateau {

	private:
        
        // nombre de cases occupées (horizontalement) sur la grille
        int m_taille;

        // nom du bateau
        string m_nom;

        // coord. (int ligneHoriz, int colonneVert) du point d'ancrage
        // m_position.first = le numéro de la ligne horizontale
        // m_position.second = le numéro de la colonne verticale
        pair<int,int> m_position;

        // tableau des dégâts de taille m_taille (case à faux si pas de dégât)
        bool* m_pDegats;


	public:

        // Constructeur par défaut : "neant", (0,0), 0, NULL
		CBateau();

        // Le bateau n'a encore aucune case touchée (m_pDegats à faux partout)
        CBateau ( string n, pair<int,int> p, int t );

        // Copie-constructeur
        CBateau(const CBateau& toCopy);
        
        // Destructeur du bateau, libère la mémoire
        ~CBateau();

        // Renvoie vrai si la case i du bateau est touchée (0 <= i < m_taille)
        bool getDegats ( int i );

        string getNom();                // Accesseur
        int getTaille();                // Accesseur
        pair<int,int> getPosition();    // Ancrage du bateau sur la grille

        // Modifie la position du bateau sur la grille en
        // ième ligne, jème colonne (nouveau point d'ancrage)
        void setPosition ( int i, int j );

        // Renvoie vrai si le bateau est coulé
        bool estCoule();

        // Tir adverse : renvoie vrai si la coordonnée passée en paramètre
        // est un tir victorieux (une case du bateau est touchée). Si le tir
        // est victorieux il doit être marqué dans le tableau m_pDegats.
        // ATTENTION si une case est déjà touchée il ne faut PAS renvoyer vrai
        // (donc renvoyer faux) sinon un tir victorieux est comptabilisé en trop
        bool tirAdverse ( pair<int,int> p );

        // Surcharge de l'opérateur << pour afficher à l'écran les
        // caractéristiques du bateau
        friend ostream& operator<< ( ostream&os, CBateau& theB );

        // Surcharge de l'opérateur =
        CBateau &operator=(const CBateau& theB);

};

#endif
