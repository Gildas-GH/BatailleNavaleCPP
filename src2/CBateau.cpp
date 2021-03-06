#include "CBateau.h"

CBateau::CBateau()
{
    this->m_nom = "neant";
    this->m_position.first = 0;
    this->m_position.second = 0;
    this->m_taille = 0;
    this->m_pDegats = new bool[0];
}

CBateau::CBateau(string n, pair<int, int> p, int t)
{
    this->m_nom = n;
    this->m_position.first = p.first;
    this->m_position.second = p.second;
    this->m_taille = t;
    this->m_pDegats = new bool[t];

    for (int i = 0; i < t; i++)
    {
        this->m_pDegats[i] = false;
    }
}

CBateau::CBateau(const CBateau &b)
{
    this->m_nom = b.m_nom;
    this->m_position.first = b.m_position.first;
    this->m_position.second = b.m_position.second;
    this->m_taille = b.m_taille;
    this->m_pDegats = new bool[b.m_taille];

    for (int i = 0; i < b.m_taille; i++)
    {
        this->m_pDegats[i] = b.m_pDegats[i];
    }
}

CBateau::~CBateau()
{
    if (this->m_pDegats != NULL)
        delete[] this->m_pDegats;
}

bool CBateau::getDegats(int i)
{
    if (i < this->m_taille && i >= 0)
        return this->m_pDegats[i];
    else
        return false;
}

string CBateau::getNom()
{
    return this->m_nom;
}

pair<int, int> CBateau::getPosition()
{
    return this->m_position;
}

int CBateau::getTaille()
{
    return this->m_taille;
}

void CBateau::setPosition(int x, int y)
{
    if (x >= 0 && x < TAILLE_GRILLE - 1 && y >= 0 && y < TAILLE_GRILLE - 1)
    {
        this->m_position.first = x;
        this->m_position.second = y;
    }
}

bool CBateau::estCoule()
{
    for (int i = 0; i < this->m_taille; i++)
    {
        if (!this->m_pDegats[i])
            return false;
    }
    return true;
}

bool CBateau::tirAdverse(pair<int, int> p)
{
    if (p.second == this->m_position.second)
    {
        if (p.first >= this->m_position.first && p.first <= this->m_position.first + this->m_taille)
        {
            int pos = p.first - this->m_position.first;

            if (!this->getDegats(pos))
            {
                this->m_pDegats[pos] = true;
                return true;
            }
            else
                return false;
        }
        return false;
    }
    else
        return false;
}

ostream &operator<<(ostream &os, CBateau &theB)
{
    os << "Nom du bateau: " << theB.m_nom << endl;
    os << "Taille du bateau: " << theB.m_taille << endl;
    os << "Position du bateau: (" << theB.m_position.first << "," << theB.m_position.second << ")" << endl;

    return os;
}

CBateau &CBateau::operator=(const CBateau &b)
{
    return *(new CBateau(b));
}