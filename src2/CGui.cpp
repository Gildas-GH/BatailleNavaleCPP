#include "CGui.h"

/**
 * Constructeur vide
 */
CGui::CGui()
{
    this->m_pArmada = NULL;
    this->m_pCoups = NULL;
}

/**
 * Constructeur qui reçoit un pointeur sur l'armada et un 
 * pointeur sur la structure d'enregistrement des tirs
 * @param pArmada pointeur sur l'armada
 * @param pCoups pointeur sur la structure d'enregistrement des coups
 */
CGui::CGui(CArmada *pArmada, CCoups *pCoups)
{
    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

/**
 * Destructeur
 * Destruction des zones pointées par m_pArmada et m_pCoups
 */
CGui::~CGui()
{
    if (this->m_pArmada != NULL)
        delete this->m_pArmada;

    if (this->m_pCoups != NULL)
        delete this->m_pCoups;
}

/**
 * Modificateur : mise à jour des attributs
 * @param pArmada pointeur sur l'armada
 * @param pCoups pointeur sur la structure d'enregistrement des coups
 */
void CGui::setArmadaCoups(CArmada *pArmada, CCoups *pCoups)
{
    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

/**
 * Ordonne à l'armada de positionner ses bateaux
 * @returns false si l'armada échoue
 */
bool CGui::positionnerBateaux()
{

    if (&this->m_pArmada == NULL)
        throw range_error("L'armada n'a pas été initialisée.");

    return this->m_pArmada->placerAleatoirement();
}

/**
 * Saisie de la coordonnée (ligne, colonne) de l'attaque 
 * (vérification obligatoire bon/mauvais après saisie de
 * la coordonnée par l'utilisateur)
 * @return pair of coordinates
 */
pair<int, int> CGui::choisirAttaque()
{
    string xC;
    string yC;
    int x, y;

    bool correct = false;

    //X
    cout << "Entrez la coordonée X: ";
    do
    {
        try
        {
            getline(cin, xC, '\n');
            x = stoi(xC);

            if (x >= 0 && x <= 9)
                correct = true;
            else
                cout << "Entrez des coordonées valide (x): ";
        }
        catch (...)
        {
            cout << "Entrez des coordonées valide (x): ";
        }
    } while (!correct);

    correct = false;

    //Y
    cout << "Entrez la coordonée Y: ";
    do
    {
        try
        {
            getline(cin, yC, '\n');
            y = stoi(yC);

            if (y >= 0 && y <= 9)
                correct = true;
            else
                cout << "Entrez des coordonées valide (y): ";
        }
        catch (...)
        {
            cout << "Entrez des coordonées valide (y): ";
        }
    } while (!correct);

    return *(new pair<int, int>(x, y));
}

/**
 * Affiche la partie est gagnée à l'écran
 */
void CGui::afficheGagne()
{
    cout << "La partie est gagnée" << endl;
}

/**
 * Affiche la partie est perdue à l'écran
 */
void CGui::affichePerdu()
{
    cout << "La partie est perdue" << endl;
}

/**
 * Méthode utilisée pour tester CGui
 */
void CGui::status()
{
    if (this->m_grilleJou == NULL) cout << "m_grilleJou : NULL" << endl;
    else cout << "m_grilleJou : INIT" << endl;

    if (this->m_grilleAdv == NULL) cout << "m_grilleAdv : NULL" << endl;
    else cout << "m_grilleAdv : INIT" << endl;

    if (this->m_pArmada == NULL) cout << "m_pArmada : NULL" << endl;
    else cout << "m_pArmada : INIT" << endl;

    if (this->m_pCoups == NULL) cout << "m_pCoups : NULL" << endl;
    else cout << "m_pCoups : INIT" << endl;
}

/**
 * Surcharge de l'opérateur << pour l'affichage des grilles. 
 * Cette fonction fait un simple appel à remplirDeuxGrilles()
 * de l'objet theG.
 * @param os flux de sortie
 * @param theG l'objet CGui à afficher
 * @returns flux de sortie
 */
ostream &operator<<(ostream &os, CGui &theG)
{
    theG.remplirDeuxGrilles(os);
    return os;
}

/**
 * Remplit les 2 grilles du joueur
 * @param os flux de sortie
 */
void CGui::remplirDeuxGrilles(ostream &os)
{

    if (this->m_pArmada == NULL || this->m_pCoups == NULL)
        throw range_error("L'armada n'a pas été initialisée.");

    // Pré-remplit les grilles de manière à ce qu'elles soient vides (-)
    for (int i = 0; i < TAILLE_GRILLE - 1; i++)
    {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++)
        {
            this->m_grilleJou[i][j] = '-';
            this->m_grilleAdv[i][j] = '-';
        }
    }

    // Placement des bateaux du joueur sur sa grille
    for (int i = 0; i < this->m_pArmada->getEffectifTotal(); i++)
    {
        CBateau *b = this->m_pArmada->getBateau(i);
        pair<int, int> pos = b->getPosition();

        for (int x = pos.first; x < b->getTaille() + pos.first; x++)
        {
            if (b->getDegats(x - pos.first))
                this->m_grilleJou[x][pos.second] = 'X';
            else
                this->m_grilleJou[x][pos.second] = 'B';
        }
    }

    for (int i = 0; i < this->m_pCoups->getTaille("ploufAdverse"); i++)
    {
        pair<int, int> pos = this->m_pCoups->getPair("ploufAdverse", i);
        this->m_grilleJou[pos.first][pos.second] = 'O';
    }

    for (int i = 0; i < this->m_pCoups->getTaille("dansLEau"); i++)
    {
        pair<int, int> pos = this->m_pCoups->getPair("dansLEau", i);
        this->m_grilleAdv[pos.first][pos.second] = 'O';
    }

    for (int i = 0; i < this->m_pCoups->getTaille("touche"); i++)
    {
        pair<int, int> pos = this->m_pCoups->getPair("touche", i);
        this->m_grilleAdv[pos.first][pos.second] = 'X';
    }

    afficherLaGrille(os, "joueur");
    afficherLaGrille(os, "adversaire");
}

/**
 * Affichage d'une grille (joueur ou adversaire) à l'écran, 
 * c'est-à-dire affichage du contenu de m_grilleJou ou m_grilleAdv + 
 * les légendes (0...TAILLE_GRILLE-2).
 * @param os flux de sortie
 * @param jouOuAdv "joueur" | "adversaire"
 */
void CGui::afficherLaGrille(ostream &os, string jouOuAdv)
{
    if (&this->m_grilleJou == NULL || &this->m_grilleAdv == NULL)
        throw range_error("Les grilles n'ont pas été initialisées.");

    if (this->m_pArmada == NULL || this->m_pCoups == NULL)
        throw range_error("L'armada n'a pas été initialisée.");

    os << "\t";
    for (size_t i = 0; i < TAILLE_GRILLE - 1; i++)
    {
        os << i << "\t";
    }
    os << "\n\n";

    for (size_t y = 0; y < TAILLE_GRILLE - 1; y++)
    {
        os << y << "\t";
        for (size_t x = 0; x < TAILLE_GRILLE - 1; x++)
        {
            if (jouOuAdv == "joueur")
                os << this->m_grilleJou[x][y] << "\t";
            else if (jouOuAdv == "adversaire")
                os << this->m_grilleAdv[x][y] << "\t";
        }
        os << "\n\n";
    }

    os << "\n\n\n\n";
}