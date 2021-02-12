#include "CBateau.h"

/**
 * Constructeur par défaut : "neant", (0,0), 0, NULL
 */
CBateau::CBateau() {
    this->m_taille = 0;
    this->m_nom = "neant";
    this->m_position.first = 0;
    this->m_position.second = 0;
    this->m_pDegats = new bool[0];
}

/**
 * Le bateau n'a encore aucune case touchée (m_pDegats à faux partout)
 */
CBateau::CBateau(string n, pair<int,int> p, int t) {
    this->m_taille = t;
    this->m_nom = n;
    this->m_position = p;

    this->m_pDegats = new bool[t];
    for ( int i=0; i<m_taille; i++ ) {
		this->m_pDegats[i] = false;
	}
}

/**
 * Copie-constructeur
 */
CBateau::CBateau(const CBateau& toCopy) {
    this->m_taille = toCopy.m_taille;
    this->m_nom = toCopy.m_nom;
    this->m_position = toCopy.m_position;

    if ( toCopy.m_pDegats != NULL ) {
		this->m_pDegats = new bool[m_taille];
		for ( int i=0; i<m_taille; i++ ) {
			this->m_pDegats[i] = toCopy.m_pDegats[i];
		}
	}
	else this->m_pDegats = NULL;
}

/**
 * Destructeur du bateau, libère la mémoire
 */
CBateau::~CBateau() {
    if ( m_pDegats != NULL ) {
		cout << "Destruction du tableau des dégats" << endl;
		delete[] m_pDegats;
	}
}

/**
 * Renvoie vrai si la case i du bateau est touchée (0 <= i < m_taille)
 */
bool CBateau::getDegats(int i) {
    if (i > 0 && i <= this->m_taille) {
        return this->m_pDegats[i];
    } else {
        // TODO Exception
        return this->m_pDegats[i];
    }

}

/**
 * Accesseur : renvoie le nom
 */
string CBateau::getNom() {
    return this->m_nom;
}

/**
 * Accesseur : renvoie la taille
 */
int CBateau::getTaille() {
    return this->m_taille;
}

/**
 * Accesseur : renvoie le point d'ancrage
 */
pair<int,int> CBateau::getPosition() {
    return this->m_position;
}

/**
 * Modifie la position du bateau sur la grille en
 * ième ligne, jème colonne (nouveau point d'ancrage)
 */
void CBateau::setPosition(int i, int j) {
    if (i > 0 && i <= TAILLE_GRILLE &&
        j > 0 && j <= TAILLE_GRILLE ) {
            this->m_position.first = i;
            this->m_position.second = j;
    } else {
        // TODO Exception
    }
}

/**
 * Renvoie vrai si le bateau est coulé
 */
bool CBateau::estCoule() {
    bool estCoule = true;
    int i = 0;

    while (estCoule) {
        if (this->m_pDegats[i] == false) estCoule = false;
        i++;
    }

    return estCoule;
}

/**
 * Tir adverse : renvoie vrai si la coordonnée passée en paramètre
 * est un tir victorieux (une case du bateau est touchée). Si le tir
 * est victorieux il doit être marqué dans le tableau m_pDegats.
 * ATTENTION si une case est déjà touchée il ne faut PAS renvoyer vrai
 * (donc renvoyer faux) sinon un tir victorieux est comptabilisé en trop
 */
bool CBateau::tirAdverse(pair<int,int> p) {
    bool victoire = false;
    
    // Les bateaux sont horizontaux : on doit être sur la bonne ligne.
    if (p.first == this->m_position.first) {
        
        // On vérifie qu'il est parmi les bonnes colonnes
        if (p.second >= this->m_position.second &&
            p.second <= this->m_position.second + this->m_taille) {

                // Emplacement du tir sur le bateau
                // [0, m_taille]
                int i = p.second - m_position.second;

                // On vérifie que la case n'est pas déjà touchée
                if (!this->m_pDegats[i]) {
                    victoire = true;
                    this->m_pDegats[i] = true;
                }
        }
    }

    return victoire;
}

/**
 * Surcharge de l'opérateur << pour afficher à l'écran
 * les caractéristiques du bateau
 */
ostream& operator<< (ostream& os, CBateau& theB) {
    os << "Nom : " << theB.m_nom << endl;
    os << "Taille : " << theB.m_taille << endl;
    
    os << "Position : (" << theB.m_position.first << ",";
    os << theB.m_position.second << ")" << endl;

    for (int i = 0; i < theB.m_taille; i++) {
        os << "Touché en " << i << ": " << theB.m_pDegats[i] << " " << endl;
    }

    return os << endl;
}

/**
 * Surcharge de l'opérateur égal
 */
CBateau &CBateau::operator=(const CBateau& theB) {
    this->m_taille = theB.m_taille;
    this->m_nom = theB.m_nom;
    this->m_position = theB.m_position;

    if ( theB.m_pDegats != NULL ) {
		this->m_pDegats = new bool[m_taille];
		for ( int i=0; i<m_taille; i++ ) {
			this->m_pDegats[i] = theB.m_pDegats[i];
		}
	} else this->m_pDegats = NULL;

    return *this;
}