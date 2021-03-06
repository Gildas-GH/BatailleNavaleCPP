#include "CArmada.h"

void CArmada::ajouterBateau(CBateau &unBat)
{
    this->m_listeBateaux.push_back(unBat);
}

CBateau *CArmada::getBateau(int i)
{
    return &(this->m_listeBateaux.at(i));
}

int CArmada::getEffectifTotal()
{
    return this->m_listeBateaux.size();
}

int CArmada::getNbreTotCases()
{
    int value = 0;
    for (CBateau b : this->m_listeBateaux)
    {
        value += b.getTaille();
    }
    return value;
}

int CArmada::getEffectif()
{
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

void CArmada::getArmadaFromFile()
{
    char nomFich[20] = "flotilles.txt";
    ifstream input;
    string line;
    string delimiter = " ";

    try
    {
        input.open(nomFich, ios::in);
    }
    catch(...)
    {
        cout << "Le fichier n'existe pas" << endl;
        exit(3);
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
            shipSize = stoi(line);

            for (int i = 0; i < numberOfShips; i++)
            {
                pair<int, int> pos;
                pos.first = 0;
                pos.second = 0;

                ajouterBateau(*(new CBateau(shipName, pos, shipSize)));
            }
        }
        catch (...)
        {
            cout << "Le fichier flotille.txt ne respecte pas le bon format" << endl;
            exit(3);
        }
    }

    input.close();

    cout << "Armada chargee" << endl;
}

bool CArmada::placerAleatoirement()
{
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