#include "CArmada.h"

void testPlacerAleatoirement();
void testGetArmadaFromFile();
void testGetEffectifTotal();
void testGetNbreTotCases();
void testAjouterBateau();
void testGetEffectif();
void testGetBateau();

int main() {
    testPlacerAleatoirement();
    testGetArmadaFromFile();
    testGetEffectifTotal();
    testGetNbreTotCases();
    testAjouterBateau();
    testGetEffectif();
    testGetBateau();

    return 0;
}

void testPlacerAleatoirement() {
    cout << "=== Test de placerAleatoirement() ===" << endl;

    CArmada armada;
    CBateau b1;
    CBateau b2;
    CBateau b3("bateau3", make_pair(1,1), 3);
    CBateau b4;
    CBateau b5("bateau5", make_pair(2,2), 4);
    CBateau b6;

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);
    armada.ajouterBateau(b3);
    armada.ajouterBateau(b4);
    armada.ajouterBateau(b5);
    armada.ajouterBateau(b6);

    bool result = armada.placerAleatoirement();

    if (result) {
        cout << "OK." << endl;
    } else {
        cout << "ERREUR." << endl;
    }
}
    
void testGetArmadaFromFile() {
    cout << "=== Test de getArmadaFromFile() ===" << endl;

    cout << "= On crée le fichier de configuration" << endl;
    ofstream flotille;

    flotille.open ("flotille.txt");
    flotille << "# Ceci est un commentaire\n";
    flotille << "# This is a comment\n";
    flotille << "sous-marin 2 5\n";
    flotille << "torpilleur 2 2\n";
    flotille << "porte-avion 1 4";
    flotille.close();

    CArmada armada;
    armada.getArmadaFromFile();

    if (armada.getEffectifTotal() == 5) {
        cout << "OK : L'armada compte bien 5 bateaux." << endl;
    } else {
        cout << "ERREUR : L'armada ne compte pas 5 bateaux." << endl;
    }
}

void testGetEffectifTotal() {
    cout << "=== Test de getEffectifTotal() ===" << endl;

    cout << "= Création de 2 bateau. On en coule un. Puis on les ajoute à l'armada." << endl;

    CArmada armada;
    CBateau b1("bateau1", make_pair(1, 1), 3);
    CBateau b2("bateau2", make_pair(2, 3), 1);
    b2.tirAdverse(make_pair(2,3));

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);

    if (armada.getEffectifTotal() == 2) {
        cout << "OK : L'armada compte bien 2 bateaux." << endl;
    } else {
        cout << "ERREUR : L'armada ne compte pas 2 bateaux." << endl;
    }
}

void testGetNbreTotCases() {
    cout << "=== Test de getNbreTotCases() ===" << endl;

    cout << "= Bateaux créés :" << endl;

    CArmada armada;
    CBateau b1("bateau1", make_pair(1, 1), 3);
    CBateau b2("bateau2", make_pair(2, 3), 1);
    b2.tirAdverse(make_pair(2,3));
    
    cout << b1 << endl;
    cout << b2 << endl;

    cout << "On les ajoute à la flotte." << endl;

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);

    if (armada.getNbreTotCases() == 4) {
        cout << "OK : Les bateaux de occupent bien 4 cases." << endl;
    } else {
        cout << "ERREUR : Les bateaux de l'armada n'occupent pas 4 cases." << endl;
    }

}

void testAjouterBateau() {
    cout << "=== Test de ajouterBateau() ===" << endl;

    CArmada armada;
    CBateau b1("b1", make_pair(0, 0), 1);
    CBateau b2("b2", make_pair(1, 1), 2);
    CBateau b3("b3", make_pair(5, 4), 4);

    cout << "= Bateaux créés : " << endl;
    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;

    cout << "= On les ajoute à la flotte." << endl;

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);
    armada.ajouterBateau(b3);

    if (armada.getBateau(0)->getNom() == b1.getNom() && 
        armada.getBateau(1)->getNom() == b2.getNom() && 
        armada.getBateau(2)->getNom() == b3.getNom()
    ) {
        cout << "OK : Les 3 bateaux ont bien été ajoutés." << endl;
    } else {
        cout << "ERREUR : Les 3 bateaux n'ont pas pu être ajoutés." << endl;
    }
}

void testGetEffectif() {
    cout << "=== Test de getEffectif() ===" << endl;

    cout << "= Création de 2 bateau. On en coule un. Puis on les ajoute à l'armada." << endl;

    CArmada armada;
    CBateau b1("bateau1", make_pair(1, 1), 3);
    CBateau b2("bateau2", make_pair(2, 3), 1);
    b2.tirAdverse(make_pair(2,3));

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);

    if (armada.getEffectif() == 1) {
        cout << "OK : L'armada compte bien 1 bateau non coulé." << endl;
    } else {
        cout << "ERREUR : L'armada ne compte pas 1 bateau non coulé." << endl;
    }
}

void testGetBateau() {
    cout << "=== Test de getBateau ===" << endl;

    cout << "= Création de 2 bateau. On en coule un. Puis on les ajoute à l'armada." << endl;

    CArmada armada;
    CBateau b1("bateau1", make_pair(1, 1), 3);
    CBateau b2("bateau2", make_pair(2, 3), 1);
    b2.tirAdverse(make_pair(2,3));

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);

    cout << "= On utilise getBateau pour afficher les 2 bateaux." << endl;

    cout << armada.getBateau(0)->getNom() << endl;
    cout << armada.getBateau(1)->getNom() << endl;

    cout << "= Cas d'erreur : on tente de get le bateau 3 inexistant." << endl;
    try {
        armada.getBateau(2);
    } catch (invalid_argument &error) {
        cout << "Erreur : " << error.what() << endl;
    }

}