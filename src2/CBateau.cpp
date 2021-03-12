#include "CBateau.h"

/**
 * Constructeur par défaut : "neant", (0,0), 0, NULL
 */
CBateau::CBateau()
{
    this->m_nom = "neant";
    this->m_position.first = 0;
    this->m_position.second = 0;
    this->m_taille = 0;
    this->m_pDegats = new bool[0];
}

/**
 * Le bateau n'a encore aucune case touchée (m_pDegats à faux partout)
 * @param n le nom du bateau
 * @param p point d'ancrage du bateau
 * @param t taille du bateau
 */
CBateau::CBateau(string n, pair<int, int> p, int t)
{
    if (t >= TAILLE_GRILLE || t < 1) {
        throw invalid_argument("La taille du bateau est invalide.");
    } else {
        this->m_taille = t;
    }

    if (p.first < 0 || p.second < 0 || p.first >= TAILLE_GRILLE || p.second >= TAILLE_GRILLE) {
        throw invalid_argument("Le placement est invalide.");
    } else {
        this->m_position.first = p.first;
        this->m_position.second = p.second;
    }

    if (p.first + t >= TAILLE_GRILLE) {
        throw invalid_argument("Le bateau sort de la grille.");
    }

    this->m_nom = n;
    this->m_pDegats = new bool[t];

    for (int i = 0; i < t; i++) {
        this->m_pDegats[i] = false;
    }
}

/**
 * Copie-constructeur
 * @param b le bateau à copier
 */
CBateau::CBateau(const CBateau &b)
{
    this->m_nom = b.m_nom;
    this->m_position.first = b.m_position.first;
    this->m_position.second = b.m_position.second;
    this->m_taille = b.m_taille;
    this->m_pDegats = new bool[b.m_taille];

    if (b.m_pDegats != NULL) {
        this->m_pDegats = new bool[b.m_taille];
		for (int i = 0; i < b.m_taille; i++) {
            this->m_pDegats[i] = b.m_pDegats[i];
        }
	} else this->m_pDegats = NULL;
}

/**
 * Destructeur du bateau, libère la mémoire
 */
CBateau::~CBateau()
{
    if (this->m_pDegats != NULL)
        delete[] this->m_pDegats;
}

/**
 * Renvoie vrai si la case i du bateau est touchée (0 <= i < m_taille)
 * @param i case recherchée
 * @returns vrai si la case est touchée
 */
bool CBateau::getDegats(int i)
{
    if (this->m_pDegats == NULL) throw range_error("Tableau des dégats non initialisé.");
    if (this->m_taille <= 0) throw range_error("Taille du bateau <= 0.");

    if (i <= this->m_taille && i >= 0)
        return this->m_pDegats[i];
    else
        throw invalid_argument("i est trop grand ou inférieur à 0.");
}

/**
 * Accesseur : renvoie le nom
 * @returns nom du bateau
 */
string CBateau::getNom()
{
    return this->m_nom;
}

/**
 * Accesseur : renvoie le point d'ancrage
 * @returns point d'ancrage du bateau
 */
pair<int, int> CBateau::getPosition()
{
    return this->m_position;
}

/**
 * Accesseur : renvoie la taille
 * @returns taille du bateau
 */
int CBateau::getTaille()
{
    return this->m_taille;
}

/**
 * Modifie la position du bateau sur la grille en
 * ième ligne, jème colonne (nouveau point d'ancrage)
 * @param x X position
 * @param y Y position
 */
void CBateau::setPosition(int x, int y)
{
    if (this->m_taille + x > TAILLE_GRILLE - 1) {
        throw invalid_argument("Le placement dépasse la grille.");
    }

    if (x >= 0 && x < TAILLE_GRILLE - 1 && y >= 0 && y < TAILLE_GRILLE - 1) {
        this->m_position.first = x;
        this->m_position.second = y;
    } else {
        throw invalid_argument("Placement en dehors de la grille.");
    }
}

/**
 * Renvoie vrai si le bateau est coulé
 * @returns true if ship is sunk
 */
bool CBateau::estCoule()
{
    if (this->m_taille <= 0) throw range_error("La taille du bateau est <= 0.");

    bool estCoule = true;
    int i = 0;

    while (i < this->m_taille && estCoule) {
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
 * 
 * @returns true ssi case touchée pour la 1e fois
 * @param p les coordonnées
 */
bool CBateau::tirAdverse(pair<int, int> p)
{
    bool victoire = false;

    if (this->m_taille <= 0) throw range_error("La taille du bateau est <= 0.");
        
    if (p.first < 0 || p.second < 0 || p.first > TAILLE_GRILLE - 1 || p.second > TAILLE_GRILLE - 1) {
        throw invalid_argument("Coordonnées du tir hors de la grille");
    }

    // Les bateaux sont horizontaux : on doit être sur la bonne ligne.
    if (p.second == this->m_position.second)
    {

        // On vérifie qu'il est parmi les bonnes colonnes
        if (p.first >= this->m_position.first &&
            p.first <= this->m_position.first + this->m_taille)
        {

            // Emplacement du tir sur le bateau
            // [0, m_taille]
            int pos = p.first - this->m_position.first;

            // On vérifie que la case n'est pas déjà touchée
            if (!this->m_pDegats[pos]) {
                victoire = true;
                this->m_pDegats[pos] = true;
            }
        }
    }

    return victoire;
}

/**
 * Surcharge de l'opérateur << pour afficher à l'écran
 * les caractéristiques du bateau
 * @param os flux de sortie
 * @param theB le bateau à afficher
 * @returns flux de sortie avec le bateau
 */
ostream &operator<<(ostream &os, CBateau &theB)
{
    os << "Nom du bateau: " << theB.m_nom << endl;
    os << "Taille du bateau: " << theB.m_taille << endl;
    os << "Position du bateau: (" << theB.m_position.first << "," << theB.m_position.second << ")" << endl;

    return os;
}

/**
 * Surcharge de l'opérateur égal
 * @returns le nouveau bateau
 * @param b le bateau à copier
 */
CBateau &CBateau::operator=(const CBateau &b)
{
    return *(new CBateau(b));
}