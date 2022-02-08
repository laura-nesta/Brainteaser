#ifndef Image_H
#define Image_H

#include "Binaro.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image{

    public:
		/** @brief Constructeur avec paramètre de la classe Image 
        * 
        * initialise la position et la taille de l'image à 0 
        */
    	Image();

		/** @brief copie une image sur un renderer (SDL)
        * @param[rend] renderer sur lequel on copie l'image
        * 
        * appel la fonction RenderCopie de SDL, 
		* avec le rend passé en paramètre
        */
    	void render(SDL_Renderer *rend);

		/** @brief Vérifie la position de la souris
        * 
		* la fonction vérifie si la position de la souris de 
		* l'utilisateur est à l'interieur de l'image ou non.
		* Si la souris est dans l'image, la fonction renvoie vrai 
		* elle retourne faux sinon
        */
    	bool checkMouse();

		/** @brief charge l'image avec une texture, une taille et des coordonnées
        * @param[x] position x de l'image 
		* @param[y] position y de l'image 
        * @param[w] largeur de l'image 
		* @param[h] hauteur de l'image 
		* @param[t] texture de l'image
        * 
		* attribue la texture passée en paramètre à l'image 
		* innitialise la largeur et la hauteur avec les valeurs passées en paramètre 
		* innitialise la position de l'image avec les valeurs en paramètres 
		* les coordonnées représentent le centre de l'image
        */
    	void load(int x, int y, int w, int h, SDL_Texture *t);

		/** @brief Destructeur de la classe Image
        * 
        * Detruit la texture contenue dans l'image 
        */
    	~Image();

	private:
		SDL_Texture * tex;
  		SDL_Surface * sur;
  		SDL_Rect rect;

};

#endif
