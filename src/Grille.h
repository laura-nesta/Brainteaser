#ifndef Grille_H
#define Grille_H

#include <string>
#include <cmath> 
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

class Grille{
   
    public:
 
        /** @brief Constructeur par défaut de la classe Grille
        * 
        * initialise dimx et dimy à 0, ce constructeur n'alloue aucun élment au tableau
        */
        Grille();

        /** @brief Constructeur avec paramètre de la classe Grille
        * @param[dimensionx] largeur de la grille, nb de colone 
        * @param[dimensiony] hauteur de la grille, nb de ligne  
        * 
        * initialise dimx et dimy à 0, ce constructeur n'alloue aucun élment au tableau
        */
        Grille(int dimensionx, int dimensiony);

        /** @brief Déstructeur par défaut de la classe Grille
        *  
        * initialise les dimensions de la grille à 0 et vide le tableau 
        */
        ~Grille();

        /** @brief Vérifie si la grille est pleine
        * 
        * parcours la grille, si une case vide est trouvée, ma fonction renvoie faux, 
        * si aucune case vide n'est trouver à la fin du tableau, la fonction renvoie vrai
        */
        bool estPleine() const;

        /** @brief Accesseur à une case de la grille en fonction des paramètres
        * @param[x] coordonnée x de la case dans la grille (colone) 
        * @param[y] coordonnée y de la case dans le grille (ligne)  
        * 
        * la fonction renvoie l'élément de la grille dans la case de coordonnée (x,y)
        */
        int getCase(int x, int y) const;

        /** @brief Mutateur d'une case de la grille en fonction des paramètres
        * @param[x] coordonnée x de la case dans la grille (colone) 
        * @param[y] coordonnée y de la case dans le grille (ligne)  
        * @param[c] valeur à mettre dans la grille 
        * 
        * le fonction met la valeur c dans la grille à la case de coordonnée (x,y)
        */
        void setCase(int c, int x, int y);

        /** @brief Accesseur de la valeur dimx, la largeur de la grille 
        * 
        * la fonction renvoie la valeur de dimx qui correspond à la largeur de la grille
        */
        unsigned int getDimx() const;

        /** @brief Accesseur de la valeur dimy, la hauteur de la grille 
        * 
        * la fonction renvoie la valeur de dimy qui correspond à la hauteur de la grille
        */
        unsigned int getDimy() const;

        /** @brief Accesseur à une ligne de la grille en fonction du paramètre
        * @param[indice] valeur entière qui correspond à l'indice d'une ligne  
        * 
        * la fonction renvoie la ligne de la grille dont l'indice est passé en paramètre
        */
        Grille getLigne(int indice) const;
        
        /** @brief Effectue une série de tests de vérification
        * 
        * Effectue une série de tests vérifiant que le module fonctionne 
        * et que les données membres de l'objet sont conformes
        * le test vérifie que les différents paramètes sont conformes 
        * afin d'éviter les erreurs de compilation plus tard 
        */
        void testRegression ();

        /** @brief sauvegarde la grille dans le fichier filename
        * @param[filename] nom (chemin d'accès) du fichier à sauvegarder
        * 
        * les dimensions de la grille ainsi que les donnée contennues dans 
        * les cases sont stockées dans un fichier texte 
        */
        void sauver(const std::string & filename) const;

        /** @brief ouvre la grille contenue dans le fichier filename
        * @param[filename] nom (chemin d'accès) du fichier à sauvegarder
        * 
        * une grille est construit avec les dimensions de la grille 
        * ainsi que les donnée contennues dans le fichier 
        */
        void ouvrir(const std::string & filename);

        /** @brief Affiche la grille en mode texte dans la console
        * 
        * la fonction permet d'afficher la grille dans la console 
        * en mode texte. Les cases vides sont représentées par de "-"
        */
        void afficheConsole() const;

        /** @brief Affiche la grille en mode texte dans la console
        * 
        * la fonction permet d'afficher la grille dans la console 
        * en mode texte. 
        * Pour le binaro l'affichage ne correspond pas aux valeurs de la grille
        * "2" dans la grille devient "1" dans la console
        * "1" dans la grille devient "0" dans la console
        * "0" dans la grille devient "-" dans la console
        * "-" représente les cases vides 
        */
        void afficheBinaro() const;

        /** @brief remplace tout les élements en paramètres par une nouvelle valeur
        * @param[val] valeur à remplacer dans la grille 
        * @param[valn] valeur par laquelle les éléments seront remplacer
        * 
        * dans la grille, remplace tout les éléments dont la valeur est passé en paramètre
        * par la valeur du deuxième paramètre
        * ex: remplaceElement(2,3): tous les 2 dans la grille seront remplacer par des 3
        */
        void remplaceElement(int val, int valn);

    private:

        int dimx;
        int dimy;
        int *tab;

};

#endif