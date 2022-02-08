#ifndef Affichage_H
#define Affichage_H

#include "Image.h"

class Affichage{

	public:

		/** @brief Constructeur de la classe Affichage
        * @param[dimx] largeur de la grille de jeu
		* @param[dimy] hauteur de la grille de jeu
		* @param[b] Binaro contenant la grille de jeu
        *
        * innitialise Affichage avec les dimensions de la fenêtres
		* l'écran courant correspondant au menu (screen) à 0
		* quit à faux, le Binaro, le tableau d'image et
		* les textures
        */
    	Affichage(int dimx, int dimy, Binaro b, Grille gf);

		/** @brief créer l'affichage de la grille
        *
        * creer l'affichage de la grille
		* En fonction de la valeur de la case met à jour le
		* tableau d'image qui constitue la grille
        */
		void renderGrille();

		/** @brief créer l'écran principal
        *
        * créer l'écran principal, le menu du jeu
		* affiche trois boutons, "jouer" qui affiche l'écran de jeu
		* "option" qui affiche l'écran des options
		* et "quitter" qui quitte l'application
        */
		void renderMenu();

		/** @brief créer l'écran du jeu de Binaro
        *
        * créer l'écran de jeu, affiche la grille de jeu,
		* un bouton "règles" pour accéder aux règles du jeu
		* et un bouton "retour" pour revenir au menu principale
        */
		void renderJeu();

		/** @brief créer l'écran des options du jeu
        *
        * permet à l'utilisateur d'afficher ou non ses erreurs 
		* et choisir la difficulté
        */
		void renderOption();

		/** @brief créer l'écran des règles du jeu du Binaro
        *
        * créer l'écran des règles, affiche les regles du jeu
		* et un bouton "retour" ppour revenir au jeu
        */
		void renderRegles();

		/** @brief indique quel écran afficher
        *
        * si quit est faux, selectionne quel écran afficher dans la fenêtre
		* pour chaque valeur que peu prendre la donnée membre screen,
		* lance le rendu de l'écran associer
        */
		void renderCurrentScreen();

		/** @brief Renvoie la valeur de quit
        *
        * retourne la valeur de quit
		* (si quit est égale à true, la fenetre sdl est fermée)
        */
		bool getQuit();

		/** @brief Destructeur de la classe Affichage
        *
        * Detruit toutes les textures contenues dans Affichage
		* Détruiit la fenêtre, le tableau d'image et le rendu
        */
		~Affichage();

    private:
    	SDL_Window * app;
		SDL_Renderer * rend;
		int w, h;
		int screen;
		int difficulte; //0:facile, 1:moyen, 2:difficile
		bool quit;
		bool aide;

		Image jouerBouton;
    	Image optionBouton;
    	Image quitterBouton;
    	Image retourBouton;
		Image rejouerBouton;
		Image indiceBouton;
      	Image gagner;
		Image regleBouton;
		Image regles;
		Image fondBinaro;
		Image erreur;
		Image indice;
		Image cases;
		Image facile;
		Image moyen;
		Image difficile;
		Image optionsJeu;
		Image suivantBouton;
		Image cadre;

      	SDL_Texture *tex0;
     	SDL_Texture *tex1;
	  	SDL_Texture *tex2;
	  	SDL_Texture *tex3;
      	SDL_Texture *texnull;
		SDL_Texture *texerreur;
		SDL_Texture *texcasevide;
		SDL_Texture *texcasecoche;
		SDL_Texture *texsuivant;

      	SDL_Texture *texjouer;
      	SDL_Texture *texoption;
      	SDL_Texture *texquitter;
      	SDL_Texture *texretour;
		SDL_Texture *texrejouer;
	  	SDL_Texture *texregle;
		SDL_Texture *texindice;
		SDL_Texture *texfacile;
		SDL_Texture *texmoyen;
		SDL_Texture *texdifficile;

      	SDL_Texture *texwin;
	  	SDL_Texture *texregles;
	  	SDL_Texture *texfondBinaro;
		SDL_Texture *texoptionJeu;
		SDL_Texture *texcadre;

      	SDL_Surface *sur;

    	const int wB = 128;
    	const int hB = 64;

    	Grille grille;
		Grille grillef;

    	Binaro binaro;

    	Image * tab;

};

#endif
