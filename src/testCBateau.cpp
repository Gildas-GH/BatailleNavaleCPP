#include "CBateau.h"

int main() {

    // Test du constructeur vide
    CBateau b1 = CBateau();
    cout << b1 << endl;

    // Test du copy-constructeur sur un bateau vide
    CBateau b2 = CBateau(b1);
    cout << b2 << endl;

    // Test du constructeur standard
    pair<int,int> p;
    p.first = 2;
    p.second = 3;
    CBateau b3 = CBateau("Nom", p, 4);

    cout << b3 << endl;

    // Test du copy-constructeur sur un bateau rempli
    CBateau b4 = CBateau(b3);
    cout << b4 << endl;

    // Test des getters
    cout << b4.estCoule() << endl; // on attend 0 (false)
    cout << b4.getDegats(0) << endl; // on attend 0
    cout << b4.getNom() << endl; // on attend "Nom"
    cout << b4.getPosition().first << endl; // on attend 2
    cout << b4.getTaille() << endl; // on attend 4

    // Test du changement de position
    b4.setPosition(5,6);
    cout << b4.getPosition().first << endl; // on attend 5
    cout << b4.getPosition().second << endl; // on attend 6

    // Test de tir : tir réussi
    b4.tirAdverse(make_pair(5,6));
    cout << b4.getDegats(0) << endl; // on attend 1
    // On retire au même endroit : on attend 0 (false)
    cout << b4.tirAdverse(make_pair(5,6)) << endl;

    // On tire hors du bateau : on attend false
    cout << b4.tirAdverse(make_pair(6,6)) << endl;

    return 0;
}