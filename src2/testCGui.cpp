#include "CGui.h"
#include "CCoups.h"

void testConstructeurVide();
void testConstructeurNormal();
void testSetArmadaCoups();
void testPositionnerBateaux();
void testChoisirAttaque();
void testAfficheGagne();
void testAffichePerdu();
void testRemplirDeuxGrilles();
void testAfficherLaGrille();

int main() {
    testConstructeurVide();
    testConstructeurNormal();
    testSetArmadaCoups();
    testPositionnerBateaux();
    testChoisirAttaque();
    testAfficheGagne();
    testAffichePerdu();
    testRemplirDeuxGrilles();
    testAfficherLaGrille();

    return 0;
}

void testConstructeurVide() {
    cout << "=== Test du constructeur vide ===" << endl;

    CGui c1;
    cout << c1 << endl;
}

void testAfficheGagne() {
    cout << "=== Test de afficheGagne() ===" << endl;

    CGui c1;
    c1.afficheGagne();
}

void testAffichePerdu() {
    cout << "=== Test de afficheGagne() ===" << endl;

    CGui c1;
    c1.affichePerdu();
}

void testConstructeurNormal() {
    
}

void testSetArmadaCoups() {
    cout << "=== Test de setArmadaCoups() ===" << endl;
    cout << "= Sur un objet vide" << endl;
    
    CGui c1;
    CArmada armada;
    CCoups coups;   
    
    c1.setArmadaCoups(&armada, &coups);

    cout << c1 << endl;

    delete& c1;
}

void testPositionnerBateaux() {
    cout << "=== Test de positionnerBateaux() ===" << endl;
    cout << "= Sur un objet vide" << endl;

    CGui c1;
    c1.positionnerBateaux();

}

void testChoisirAttaque() {
    cout << "=== Test de choisirAttaque() ===" << endl;
    cout << "= Sur un objet vide" << endl;

    CGui c1;
    pair<int,int> p = c1.choisirAttaque();

    cout << p.first << p.second << endl;

}

void testRemplirDeuxGrilles() {
    cout << "=== Test de remplirDeuxGrilles() ===" << endl;
    cout << "= Sur un objet vide" << endl;

    CGui c1;
    c1.remplirDeuxGrilles(cout);

}

void testAfficherLaGrille() {
    cout << "=== Test de afficherLaGrille() ===" << endl;
    cout << "= Sur un objet vide (joueur)" << endl;

    CGui c1;
    c1.afficherLaGrille(cout, "joueur");
    
    cout << "= Sur un objet vide (adversaire)" << endl;
    c1.afficherLaGrille(cout, "adversaire");

}