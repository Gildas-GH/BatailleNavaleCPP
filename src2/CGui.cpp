#include "CGui.h"

CGui::CGui()
{
    this->m_pArmada = NULL;
    this->m_pCoups = NULL;
}

CGui::CGui(CArmada *pArmada, CCoups *pCoups)
{
    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

CGui::~CGui()
{
    if (this->m_pArmada != NULL)
        delete this->m_pArmada;

    if (this->m_pCoups != NULL)
        delete this->m_pCoups;
}

void CGui::setArmadaCoups(CArmada *pArmada, CCoups *pCoups)
{
    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

bool CGui::positionnerBateaux()
{
    return this->m_pArmada->placerAleatoirement();
}

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

void CGui::afficheGagne()
{
    cout << "La partie est gagnée à l'écran" << endl;
}

void CGui::affichePerdu()
{
    cout << "La partie est perdue à l'écran" << endl;
}

ostream &operator<<(ostream &os, CGui &theG)
{
    theG.remplirDeuxGrilles(os);
    return os;
}

void CGui::remplirDeuxGrilles(ostream &os)
{

    for (int i = 0; i < TAILLE_GRILLE - 1; i++)
    {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++)
        {
            this->m_grilleJou[i][j] = '-';
            this->m_grilleAdv[i][j] = '-';
        }
    }

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

void CGui::afficherLaGrille(ostream &os, string jouOuAdv)
{
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