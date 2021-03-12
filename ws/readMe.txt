Bataille Navale en C++

Gildas Garin-Hameline
Février-Mars 2021
IUT de Vannes


Décrire l'état d'avancement du projet

Le projet est terminé. Toutes les classes demandées sont fonctionnelles
et testées. Le jeu fonctionne lui aussi. 


Compilation du projet (makefile)

Pour compiler le projet entier, utilisez `make lanceurFinal`

Liste des routes disponibles :

- deleteAll : Supprimer tous les fichiers exécutables ou compilés
- testCBateau : deleteAll compilCBateau compilTestCBateau
- compilCBateau : Compilation de CBateau
- compilTestCBateau : Compilation des tests de CBateau
- testCArmada : deleteAll compilCBateau compilCArmada compilTestCArmada
- compilCArmada : Compilation de Carmada
- compilTestCArmada : Compilation des tests de CArmada
- testCGui : deleteAll compilCBateau compilCArmada compilCCoups compilCGui compilTestCGui
- compilCGui : Compilation de CGui
- compilTestCGui : Compilation des tests de CGui
- compilCCoups : Compilation de CCoups
- compilCSocket : Compilation de CSocket
- compilCClientSocket : Compilation de CCLientSocket
- compilCServerSocket : Compilation de CServerSocket
- compilCJoueur : Compilation de CJoueur
- compilCJoueurCli : Compilation de CJoueurCli
- compilCJoueurServ : Compilation de CJoueurServ