s/*
 * 	Cette classe représentante le joueur qui prendra le réle de client (au sens réseau) dans le jeu.
 *  Le client joue contre le serveur.
 *	C'est le client qui reéoit la flotille de départ du serveur.
 */

#ifndef CJOUEURCLI_H
#define CJOUEURCLI_H

#include "BiblioStd.h"
#include "CArmada.h"
#include "CJoueur.h"
#include "CBaseJeu.h"

class CJoueurCli : public CJoueur {

	public:
		CJoueurCli ( CBaseJeu* g );								// Constructeur
		~CJoueurCli();											// Destructeur
		void connectServer ( const string& host, int port );	// Connexion au serveur en passant les paramétres host et port en dur

		CArmada* getArmadaCli();								// Cette méthode récupére la flotille du client é travers le réseau.
																// En effet, c'est le serveur qui décide de la composition de la flotte et qui envoie cette composition au joueur client en début de partie.
};

#endif // CJOUEURCLI_H
