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
    c1.status();
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
    cout << "=== Test du constructeur normal ===" << endl;

    CCoups* coupTestScenario = new CCoups();
    CArmada* armadaTestScenario  = new CArmada();
    CGui* gui = new CGui(armadaTestScenario, coupTestScenario);

    gui->status();
}

void testSetArmadaCoups() {
    cout << "=== Test de setArmadaCoups() ===" << endl;
    cout << "= Sur un objet vide" << endl;
    
    CGui c1;
    CCoups* coupTestScenario = new CCoups();
    CArmada* armadaTestScenario  = new CArmada(); 
    
    c1.setArmadaCoups(armadaTestScenario, coupTestScenario);

    c1.status();
}

void testPositionnerBateaux() {
    cout << "=== Test de positionnerBateaux() ===" << endl;
    cout << "= Sur un objet vide" << endl;

    CGui c1;
    try {
        c1.positionnerBateaux();
    } catch(range_error &e) {
        cout << e.what() << endl;
    }

    cout << "= Sur un objet rempli" << endl;
    CCoups* coupTestScenario = new CCoups();
    CArmada* armadaTestScenario  = new CArmada();
    CGui* gui = new CGui(armadaTestScenario, coupTestScenario);

    gui->positionnerBateaux();
}

void testChoisirAttaque() {
    cout << "=== Test de choisirAttaque() ===" << endl;
    cout << "= Sur un objet vide" << endl;

    CGui c1;
    pair<int,int> p = c1.choisirAttaque();

    cout << "(" << p.first  << "," << p.second << ")" << endl;

    cout << "= Sur un objet rempli" << endl;
    CCoups* coupTestScenario = new CCoups();
    CArmada* armadaTestScenario  = new CArmada();
    CGui* gui = new CGui(armadaTestScenario, coupTestScenario);

    pair<int,int> p2 = gui->choisirAttaque();
    cout << "(" << p2.first  << "," << p2.second << ")" << endl;

}

void testRemplirDeuxGrilles() {
    cout << "=== Test de remplirDeuxGrilles() ===" << endl;
    cout << "= Sur un objet vide" << endl;

    CGui c1;
    try {
        c1.remplirDeuxGrilles(cout);
    } catch(range_error &e) {
        cout << e.what() << endl;
    }

    cout << "= Sur un objet rempli" << endl;
    CCoups* coupTestScenario = new CCoups();
    CArmada* armadaTestScenario  = new CArmada();
    CGui* gui = new CGui(armadaTestScenario, coupTestScenario);

    gui->remplirDeuxGrilles(cout);

}

void testAfficherLaGrille() {
    cout << "=== Test de afficherLaGrille() ===" << endl;
    cout << "= Sur un objet vide (joueur)" << endl;

    CGui c1;
    try {
        c1.afficherLaGrille(cout, "joueur");
    } catch(range_error &e) {
        cout << e.what() << endl;
    }
    
    cout << "= Sur un objet vide (adversaire)" << endl;
    try {
        c1.afficherLaGrille(cout, "adversaire");
    } catch(range_error &e) {
        cout << e.what() << endl;
    }

    cout << "= Sur un objet rempli (joueur)" << endl;
    CCoups* coupTestScenario = new CCoups();
    CArmada* armadaTestScenario  = new CArmada();
    CGui* gui = new CGui(armadaTestScenario, coupTestScenario);

    gui->afficherLaGrille(cout, "joueur");

    cout << "= Sur un objet rempli (adversaire)" << endl;
    gui->afficherLaGrille(cout, "adversaire");

    cout << "= Après avoir rempli les grilles" << endl;
    gui->remplirDeuxGrilles(cout);

}