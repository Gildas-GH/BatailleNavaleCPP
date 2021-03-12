#include "CArmada.h"

/**
 * Ajoute un bateau dans m_listeBateaux avec la méthode push_back
 * @param unBat le bateau
 */
void CArmada::ajouterBateau(CBateau &unBat)
{
    if (&this->m_listeBateaux == NULL)
        throw range_error("L'armada est NULL.");

    this->m_listeBateaux.push_back(unBat);
}

/**
 * Accesseur : renvoie (par pointeur) le bateau à l'index i 
 * (0 <= i < taille)
 * @param i l'index du bateau
 * @returns le bateau
 */
CBateau *CArmada::getBateau(int i)
{
    if (i < 0 || i >= (int)this->m_listeBateaux.size())
        throw invalid_argument("Index invalide.");

    return &(this->m_listeBateaux.at(i));
}

/**
 * Renvoie le nombre total de bateaux de l'armada
 * @returns le nombre total de bateaux
 */
int CArmada::getEffectifTotal()
{
    if (&this->m_listeBateaux == NULL)
        throw range_error("L'armada est NULL.");

    return this->m_listeBateaux.size();
}

/**
 * Accesseur : renvoie le nombre total de cases occupées par l'armada
 * @returns nombre de cases occupées
 */
int CArmada::getNbreTotCases()
{
    if (&this->m_listeBateaux == NULL)
        throw range_error("L'armada est NULL.");
    
    int value = 0;
    for (CBateau b : this->m_listeBateaux)
    {
        value += b.getTaille();
    }
    return value;
}

/**
 * Renvoie le nombre de bateaux qui ne sont pas encore coulés
 * @returns nombre de bateaux pas coulés
 */
int CArmada::getEffectif()
{
    if (&this->m_listeBateaux == NULL)
        throw range_error("L'armada est NULL.");
    
    int ret = 0;

    for (CBateau b : this->m_listeBateaux)
    {
        if (!b.estCoule())
        {
            ret++;
        }
    }
    return ret;
}

/**
 * Lecture du fichier flotille.txt (contient la liste de tous les bateaux)
 */
void CArmada::getArmadaFromFile()
{
    char nomFich[20] = "flotille.txt";
    ifstream input;
    string line;
    string delimiter = " ";

    try {
        input.open(nomFich, ios::in);
    } catch(...) {
        throw invalid_argument("Le fichier n'existe pas.");
    }

    // Récupération des bateaux 1 par 1
    while (!input.eof())
    {
        size_t pos = 0;
        string token;
        int word = 0;

        string shipName;
        int numberOfShips;
        int shipSize;

        try
        {
            getline(input, line, '\n');

            if (line.at(0) != '#') {

                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                    token = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());

                    if (word == 0)
                        shipName = token;
                    else if (word == 1)
                        numberOfShips = stoi(token);

                    word++;
                }
            }
            shipSize = stoi(line);

            for (int i = 0; i < numberOfShips; i++)
            {
                pair<int, int> pos;
                pos.first = 0;
                pos.second = 0;

                ajouterBateau(*(new CBateau(shipName, pos, shipSize)));
            }
        } catch (...) {
            invalid_argument("Le formattage est invalide.");
        }
    }

    input.close();

    cout << "Armada chargee" << endl;
}

/**
 * Placement automatique aléatoire des bateaux. 
 * @returns faux si le positionnement a échoué.
 */
bool CArmada::placerAleatoirement()
{
    if (&this->m_listeBateaux == NULL)
        throw range_error("L'armada est NULL.");

    int nbBateaux = this->m_listeBateaux.size();
    bool correct = true;
    int i = 0;

    while (correct && i < nbBateaux)
    {
        CBateau *b = this->getBateau(i);

        int essais = 0;
        correct = false;
        int xRand;
        int yRand;

        while (essais < MAXESSAIS && !correct)
        {
            xRand = rand() % (10 - b->getTaille() - 1);
            yRand = rand() % 10;

            correct = true;
            int j = 0;

            while (correct && j < nbBateaux)
            {
                CBateau b2 = this->m_listeBateaux.at(j);
                int x2 = b2.getPosition().first;
                int y2 = b2.getPosition().second;

                if (yRand == y2 && x2 >= xRand && x2 <= xRand + b->getTaille())
                {
                    correct = false;
                    essais++;
                }
                j++;
            }
        }
        i++;

        if (correct)
        {
            b->setPosition(xRand, yRand);
        }
    }

    return correct;
}

/**
 * Affiche à l'écran toutes les positions des sous-marins
 * @param os flux de sortie
 * @param theA l'armada à afficher
 * @returns flux de sortie avec l'armada
 */
ostream& operator<< (ostream& os, CArmada& theA) {
	os << "Armada : " << endl;
    os << "- Effectif : " << theA.getEffectif() << endl;
    os << "- Effectif Total : " << theA.getEffectifTotal() << endl;
    os << "- Nombre de cases : " << theA.getNbreTotCases() << endl;
	
	return os;
}