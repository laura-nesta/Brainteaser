#include "Affichage.h"

const int DIMX = 640;
const int DIMY = 640;

int main(/*int argc, char ** argv*/){

  srand(time(NULL));

  Grille g;
  g.ouvrir("./data/grille/grillejeu2.txt");
  Grille gf;
  gf.ouvrir("./data/grille/grillejeu2fini.txt");

  Binaro b;
  b.setGrille(g);

  Affichage A(DIMX, DIMY, b, gf);

  A.renderCurrentScreen();

  SDL_Delay(10);

	return 0;
}
