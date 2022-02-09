# Brainteaser
Création d'un jeu de réflexion. 
L'objectif de se projet était de réalisé un jeu avec un affichage graphique via la bibliothèque d'affichage sdl.
J'était en collaboration avec deux autres étudiants pour réaliser ce projet.

Nous avons choist de réaliser un jeu de réflexion qui se joue seul. Visuellement semblable à un sudoku, nous avons réaliser un binaro. 
Il s'agit d'un jeu qui se présente sur une grille de taille nxn avec n un nombre pair. L'objectif est de remplir l'intégralité de la grille. 
Chaque case de la grille comporte soit un 1 soit un 0. A l'innitialisation du jeu, quelques cases sont remplies. 
Pour compléter la grille, le joueur doit respecté 3 règles: 
  - Il doit y avoir autant de 1 que de 0 sur chaque lignes et colones. 
  - Il ne peut y avoir plus deux symboles identiques consécutifs.
  - deux lignes ou deux colones ne peuvent être identiques.


------------------------------------------------------------------------------------------------------------------------------------------------------

## Organisation des dossiers/ fichiers ##

readme.txt	: fichier texte contenant les informations relatives au module.

Mkaefile	: permet la compilation et la création des trois executables.

bin		: contient les executable créé par le make: exemple, test et affichage.

src		: contient tout les fichiers sources (.h et .cpp).

data	: grille 	: contient les grilles (en .txt) créées lors de l'execution des executables ainsi que les grilles jouables.
		  image		: contient les images du jeu 

doc		: contient la documentation du module, créée avec Doxygen.

obj		: contient tous les fichiers .o créers lors l'execution du makefile.

## Compilation et execution ##

Compilation	: Pour compiler le module, il faut utiliser la commande make.
		  Elle fait appel au makefile qui assemble et compile les trois executables.
		  Les trois executables créés sont jeu, console et test

Execution	: Pour executer le programme, il faut faire appel aux executables
		  Pour executer mainTest.cpp, utiliser la commande bin/test
		  Pour executer mainConsole.cpp, utiliser la commande bin/console
		  Pour executer mainJeu.cpp, utiliser la commande bin/jeu

## Le Module BrainTeaser ##

Classe Grille		: La classe Grille permet la création de Grille de dimension variable contenant des entiers
			  La classe Grille permet la création, la manipulation et la destruction de Grille.

Classe Binaro		: La classe Binaro contient une grille.
			  La grille est enregistrée sur une fichier texte. 
			  La classe Binaro permet de crée, modifier, ouvrir, sauvegarder, afficher et detruire un une grille de jeu.
              Les grilles sont stockées dans data. On peut selectioner une grille jouable en l'affectant a un Binaro
              Binaro possède des fonctions permettant de jouer dans la console

Classe Image	 	: La classe Image contient une texture, une surface et un rectangle
			  La classe image est contruite à l'aide de la bibliothèque SDL.
			  Elle permet la création d'image pour l'affichage graphique

Classe Affichage	: La classe Affichage contient un binaro, des grilles et l'ensemble de images et textures 
			  La classe Affichage permet de charger les differentes textures 
			  Elle permet l'affichage graphique de l'application.
			  Elle permet également à l'utilisateur d'intéragir avec l'application


## Les executables ##

test		: L'executable est appelé avec la commande bin/test. Il execute le programme mainTest.cpp
		  test crée une grille et lance la fonction test regression sur cette grille.
		  La foction test de regression sert à faire série de test pour vérifier la validité de la grille.

Console	: L'executable est appelé avec la commande bin/console. Il execute le programme mainConsole.cpp
		  console crée un binaro avec une grille jouable à complétée,
		  console permet de joueur dans la console en mode texte 

jeu	: L'executable est appelé avec la commande bin/jeu. Il execute le programme mainJeu.cpp
		  jeu créer un binaro et permet l'affichage du jeu dans une fenetre sdl2.
		  jeu permet à l'utilisateur de jouer à binaro en mode affichage graphique
