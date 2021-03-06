#include "CBateau.h"

void testConstructeurVide();
void testConstructeur();
void testTirAdverse();
void testEstCoule();
void testSetPosition();
void testGetDegats();
void testCopyConstructor();
void testEqualOperator();

int main() {
    testConstructeurVide();
    testConstructeur();
    testTirAdverse();
    testEstCoule();
    testSetPosition();
    testGetDegats();
    testCopyConstructor();
    testEqualOperator();

    return 0;
}

void testConstructeurVide() {
    cout << "=== Test du constructeur vide ===" << endl;

    CBateau b1 = CBateau();
    cout << b1 << endl;
}

void testConstructeur() {
    cout << "=== Test du constructeur normal ===" << endl;

    pair<int,int> p;
    p.first = 2;
    p.second = 3;
    CBateau b2 = CBateau("Nom", p, 4);

    cout << b2 << endl;

    cout << "= Cas d'erreur (coord. invalides)" << endl;

    pair<int,int> p2;
    p2.first = -2;
    p2.second = 18;

    try {
        CBateau b3 = CBateau("Nom", p2, 1);
    } catch (invalid_argument &error) {
        cout << "Erreur : " << error.what() << endl;
    }

}

void testCopyConstructor() {
    cout << "=== Test du copy-constructeur ===" << endl;
    cout << "= Sur un bateau vide" << endl;
    
    CBateau b4 = CBateau();
    cout << b4 << endl;

    cout << "\nCopie du bateau : \n" << endl;
    CBateau b5(b4);
    cout << b5 << endl;

    cout << "= Sur un bateau rempli" << endl;
    pair<int,int> p;
    p.first = 2;
    p.second = 3;
    CBateau b6 = CBateau("Nom", p, 4);
    cout << b6 << endl;

    cout << "\nCopie du bateau : \n" << endl;
    CBateau b7(b6);
    cout << b7 << endl;

}

void testTirAdverse() {
    cout << "=== Test de tirAdverse() ===" << endl;

    cout << "= Sur un bateau vide" << endl;

    CBateau b8 = CBateau();
    //cout << b8 << endl;
    try {
        b8.tirAdverse(make_pair(5,5));
    } catch (range_error &error) {
        cout << "Erreur : " << error.what() << endl;
    }

    cout << "= Sur un bateau rempli" << endl;
    pair<int,int> p;
    p.first = 2;
    p.second = 3;
    CBateau b9 = CBateau("Nom", p, 1);
    //cout << b9 << endl;

    cout << "Tir (qui touche) : " << b9.tirAdverse(make_pair(2,3)) << endl;
    cout << "Tir (qui ne touche pas) : " << b9.tirAdverse(make_pair(3,3)) << endl;

    cout << "= Tir invalide" << endl;
    try {
        b9.tirAdverse(make_pair(-1, 3));
    } catch (invalid_argument &error) {
        cout << "Error : " << error.what() << endl;
    }


}

void testEstCoule() {
    cout << "=== Test de estCoule() ===" << endl;
    cout << "= Sur un bateau vide" << endl;

    CBateau b10;
    try {
        b10.estCoule();
    } catch (range_error &error) {
        cout << "Error : " << error.what() << endl;
    }

    cout << "= Sur un bateau rempli" << endl;

    pair<int,int> p;
    p.first = 2;
    p.second = 3;
    CBateau b11 = CBateau("Nom", p, 1);

    cout << "= Sans tir dessus -> ne doit pas être coulé : " << b11.estCoule() << endl;

    b11.tirAdverse(make_pair(2, 3));
    cout << "= On coule le bateau : estCoulé() :" << b11.estCoule() << endl;

}

void testSetPosition() {
    cout << "=== Test de setPosition() ===" << endl;
    cout << "= Sur un bateau vide" << endl;

    CBateau b12;
    cout << b12 << endl;
    cout << "= Set position à 2, 3." << endl;
    b12.setPosition(2, 3);
    cout << b12 << endl;


    cout << "= Set positions -1, 3 (invalide)" << endl;
    CBateau b13;
    cout << b13 << endl;
    cout << "= Set position à -1, 3." << endl;
    try {
        b13.setPosition(-1, 3);
    } catch (invalid_argument &error) {
        cout << "Error : " << error.what() << endl;
    }
    cout << b13 << endl;


    cout << "= Sur un bateau rempli" << endl;
    CBateau b14("Name", make_pair(1, 1), 2);
    cout << b14 << endl;
    b14.setPosition(5, 3);
    cout << b14 << endl;

    cout << "= Set position à -1, 3." << endl;
    try {
        b13.setPosition(-1, 3);
    } catch (invalid_argument &error) {
        cout << "Error : " << error.what() << endl;
    }
    cout << b13 << endl;

    // TODO : Sur le bord de la grille

}

void testGetDegats() {
    cout << "=== Test de getDegats() ===" << endl;
    cout << "= Sur un bateau vide" << endl;

    CBateau b14;
    try {
        cout << "Get degats (erreur) : " << endl;
        cout << b14.getDegats(0) << endl;
    } catch (range_error &error) {
        cout << "Erreur : " << error.what() << endl;
    }


    cout << "= Sur un bateau rempli" << endl;

    CBateau b15("Name", make_pair(1, 1), 2);
    cout << "Get degats (renvoie false) : " << b15.getDegats(0) << endl;
    b15.tirAdverse(make_pair(1, 1));
    cout << "Get degats (renvoie true) : " << b15.getDegats(0) << endl;


    cout << "= Cas d'erreur : en dehors du bateau" << endl;
    try {
        cout << "Get degats (erreur) : " << b15.getDegats(6) << endl;
    } catch (invalid_argument &error) {
        cout << "\nError : " << error.what() << endl;
    }

}

void testEqualOperator() {
    cout << "=== Test surcharge de l'op égal ===" << endl;
    cout << "= Sur un bateau vide" << endl;

    CBateau b16;
    cout << b16;
    cout << "Copie du bateau :" << endl;
    CBateau b17 = b16;
    cout << b17;

    cout << "= Sur un bateau rempli" << endl;

    CBateau b18("Nom", make_pair(1, 2), 3);
    cout << b18;
    cout << "Copie du bateau :" << endl;
    CBateau b19 = b18;
    cout << b19;
}