#ifndef Binaro_H
#define Binaro_H

#include "Grille.h"

class Binaro{

    public:

        /** @brief Constructeur par défaut de la classe Binaro
        * 
        * initialise Binaro avec une grille vide 
        * de largeur et hauteur égale à 0
        */
        Binaro();

        /** @brief Constructeur avec paramètre de la classe Binaro
        * @param[g] Grille du Binaro 
        * 
        * initialise Binaro avec la grille passée en paramètre 
        */
        Binaro(Grille g);

        /** @brief Accesseur de la grille de Binaro
        * 
        * la fonction renvoie la grille de Binaro
        */
        Grille getGrille() const;

        /** @brief Mutateur de la grille de Binaro par une grille en paramètre
        * @param[g] Grille du Binaro 
        * 
        * la fonction change la grille de Binaro 
        * par la grille passée en paramètre
        * la grille en paramètre et sauver sur un fichier 
        * la grille de Binaro est ouverte avec ce fichier
        */
        void setGrille(Grille g);

        /** @brief Vérifie qu'il n'y est pas plus de deux éléments identique à la suite
        * @param[g] Grille dont la condition est vérfiée
        * 
        * la fonction parcours la grille et vérifie sur chaque ligne 
        * et sur chaque colone si il y a plus de deux éléments identiques 
        * consécutifs. 
        * Si plus de deux éléments identiques consécutifs sont trouvés la 
        * fontion renvoie faux. Sinon, à la fin de la grille, la fonction renvoie vrai
        */
        bool verifTriple(Grille g) const;

        /** @brief Vérifie qu'il y autant de 0 que de 1 sur chaque ligne
        * @param[g] Grille dont la condition est vérfiée
        * 
        * la fonction parcours la grille et vérifie sur chaque ligne 
        * et sur chaque colone si il y a autant de 0 que de 1
        * Si une ligne n'a pas autant de 0 que de 1 la 
        * fontion renvoie faux. Sinon, à la fin de la grille, la fonction renvoie vrai
        */
        bool verifNombre(Grille g) const;

        /** @brief Compare deux tableaux en paramètres 
        * @param[taille] taille des tableaux à comparer
        * @param[t1] tableau à comparé 
        * @param[t2] tableau à comparé
        * 
        * la fonction compare les deux tableaux passé en paramètre de taille
        * passé en paramètre. Elle renvoie vrai si les deux tableaux sont identiques,
        * elle renvoie faux sinon
        */
        bool tabidentique(int taille, int *t1, int * t2);

        /** @brief Compare deux lignes d'une grille dont les indices sont passé en paramètre 
        * @param[ligne1] indice de la ligne à comparer
        * @param[ligne2] indice de la ligne à comparer
        * 
        * la fonction compare les deux lignes d'une grille dont les indices sont passées
        * en paramètres 
        */
        bool LigneIdentique(int ligne1, int ligne2) const;

        /** @brief Compare deux colone d'une grille dont les indices sont passé en paramètre 
        * @param[colone1] indice de la colone à comparer
        * @param[colone2] indice de la colone à comparer
        * 
        * la fonction compare les deux colones d'une grille dont les indices sont passées
        * en paramètres 
        */
        bool ColoneIdentique(int colone1, int colone2) const;

        /** @brief Vérifie dans la grille qu'il n'y est pas de lignes ou colones identiques 
        * @param[g] Grille dont la condition est vérifier
        * 
        * la fonction parcours la grille pour vérifer qu'il n'y est pas deux colone ou deux 
        * lignes identiques. La fonction renvoie faux si deux lignes ou colones identiques,
        * elle renvoie faux sinon 
        */
        bool compareLigne(Grille g) const;
    
        /** @brief Vérifie si la grille est gagnée 
        * 
        * la fonction vérifie les conditions de vistoires si la grille est pleine. 
        * Si les conditions sont vérifiées, la fonction revoie vrai. 
        * Sinon la partie n'est pas gagnée et la fonction renvoie faux 
        */
        bool estGagner();

        /** @brief permet au joueur de jouer un coup en mode console 
        * 
        * la fonction invite le joueur à jouer en demandant les indices x et y de
        * la case que le joueur souhaites modifier.
        * Puis modifie la valeur de la case d'ince (x,y) avec la valeur choisie 
        * par l'utilisateur 
        */
        void actionJoueur();

        /** @brief effectue un tour de jeu en mode console 
        * 
        * effectue l'actoin du joueur puis affiche la nouvelle grille 
        * avec les modifications affectuer par le joueur 
        */
        void tourJeu();

        /** @brief Effectue une série de tests de vérification
        * 
        * Effectue une série de tests vérifiant que le module fonctionne 
        * et que les données membres de l'objet sont conformes
        * le test vérifie que les différents paramètes sont conformes 
        * afin d'éviter les erreurs de compilation plus tard 
        */
        void testRegression();

        /** @brief Vérifie qu'une ligne est pleine ou non 
        * @param indice de ligne
        * 
        * Si la ligne d'indice i passer en paramètre 
        * est pleine, la fonction renvoie vrai, faux sinon
        */
        bool lignePleine(int i);

        /** @brief Vérifie qu'une colone est pleine ou non 
        * @param indice de colone
        * 
        * Si la colone d'indice i passer en paramètre 
        * est pleine, la fonction renvoie vrai, faux sinon
        */
        bool colonePleine(int i);

        /** @brief Met à jour la grille erreur  
        * 
        * prend une grille vide est indique toutes 
        * les cases de la grille qui comportent une erreur
        */
        void grilleErreur();

        /** @brief dévoile une case juste  
        * @param grille de jeu
        * 
        * dévoile une case actuellement vide
        * de la grille de jeu passer en paramètre 
        */
        void indice(Grille g);

    private:

        Grille grille;
    
};

#endif