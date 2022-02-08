#include "Affichage.h"

using namespace std;

Affichage::Affichage(int dimx, int dimy, Binaro b, Grille gf){
	SDL_Init(SDL_INIT_VIDEO);
	w = dimx;
	h = dimy;
	app = SDL_CreateWindow("BrainTeaser", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dimx, dimy, SDL_WINDOW_OPENGL);
    rend = SDL_CreateRenderer(app, -1, SDL_RENDERER_ACCELERATED);

  	screen = 0;
    quit = false;
	aide = true;

	difficulte = 1;

    binaro = b;
	grille = binaro.getGrille();
	grillef = gf;

	sur = IMG_Load("./data/images/tex0.png");
	tex0 = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/tex1.png");
	tex1 = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/tex2.png");
	tex2 = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/tex3.png");
	tex3 = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/null.png");
	texnull = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/erreur.png");
	texerreur = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/jouer.png");
	texjouer = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/options.png");
	texoption = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/quitter.png");
	texquitter = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/retour.png");
	texretour = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/rejouer.png");
	texrejouer = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/win.png");
	texwin = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/reglesBinaro.png");
	texregle = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/fond.png");
	texfondBinaro = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/regles.png");
	texregles = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/indice.png");
	texindice = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/case.png");
	texcasevide = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/casecoche.png");
	texcasecoche = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/facile.png");
	texfacile = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/moyen.png");
	texmoyen = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/difficile.png");
	texdifficile = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/optionsJeu.png");
	texoptionJeu = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/suivant.png");
	texsuivant = SDL_CreateTextureFromSurface(rend, sur);
	sur = IMG_Load("./data/images/cadre.png");
	texcadre = SDL_CreateTextureFromSurface(rend, sur);

	jouerBouton.load(w/2, (h/2)-(2*hB), wB, hB, texjouer);
	optionBouton.load(w/2, h/2, wB, hB, texoption);
	quitterBouton.load(w/2, (h/2)+(2*hB), wB, hB, texquitter);
	retourBouton.load(wB/2, h-hB/2, wB, hB, texretour);
	rejouerBouton.load(w/2, h-hB/2, wB, hB, texrejouer);
	regleBouton.load(w-wB/2, h-hB/2, wB, hB, texregles);
	indiceBouton.load(w-wB/2, 0+(hB/2), wB, hB, texindice);
	suivantBouton.load(w/2, h-hB/2-90, wB, hB, texsuivant);

	facile.load(wB/2+40,h/2+50, wB, hB, texfacile);
	moyen.load(w/2, h/2+50, wB, hB, texmoyen);
	difficile.load(w-wB/2-40, h/2+50, wB, hB, texdifficile);

	cases.load(w-wB/2-80, 200, 50, 50, texcasecoche);

	cadre.load(wB/2+40, h/2+50, wB, hB, texcadre);

	gagner.load(w/2, h/2, h, w, texwin);
	regles.load(w/2, h/2, h, w, texregle);
	optionsJeu.load(w/2, h/2, h, w, texoptionJeu);
	fondBinaro.load(w/2, h/2, h, w, texfondBinaro);

	SDL_FreeSurface(sur);

    tab = new Image[binaro.getGrille().getDimx()*binaro.getGrille().getDimy()];
}

void Affichage::renderGrille(){
	for (unsigned int x = 0; x<binaro.getGrille().getDimx(); x++){
		for (unsigned int y = 0; y<binaro.getGrille().getDimy(); y++){
			switch (binaro.getGrille().getCase(x, y)){
				case 0:
					tab[x*binaro.getGrille().getDimx()+y].load((x*64)+(w/4)-16, (y*64)+(h/4)-32, 64, 64, texnull);
					break;
				case 1:
					tab[x*binaro.getGrille().getDimx()+y].load((x*64)+(w/4)-16, (y*64)+(h/4)-32, 64, 64, tex0);
					break;
				case 2:
					tab[x*binaro.getGrille().getDimx()+y].load((x*64)+(w/4)-16, (y*64)+(h/4)-32, 64, 64, tex1);
					break;
				case 3:
					tab[x*binaro.getGrille().getDimx()+y].load((x*64)+(w/4)-16, (y*64)+(h/4)-32, 64, 64, tex2);
					break;
				case 4:
					tab[x*binaro.getGrille().getDimx()+y].load((x*64)+(w/4)-16, (y*64)+(h/4)-32, 64, 64, tex3);
					break;
			}
			tab[x*binaro.getGrille().getDimx()+y].render(rend);
		}
	}
}

void Affichage::renderMenu(){
	SDL_Event event;

    SDL_WaitEvent(&event);
    switch (event.type) {
      	case SDL_QUIT:
        	quit = true;
          	break;
    	case SDL_MOUSEBUTTONDOWN:
       		if (jouerBouton.checkMouse()) screen = 2;
       		if (optionBouton.checkMouse()) screen = 1;
       		if (quitterBouton.checkMouse()) quit = true;
       		break;
    }

    SDL_RenderClear(rend);
    SDL_SetRenderDrawColor(rend, 51, 51, 51, 255);
    jouerBouton.render(rend);
    optionBouton.render(rend);
    quitterBouton.render(rend);
    SDL_RenderPresent(rend);
}

void Affichage::renderOption(){
	SDL_Event event;
  	SDL_WaitEvent(&event);

	Grille gjeu;

    switch (event.type) {
      	case SDL_QUIT:
        	quit = true;
          	break;
    	case SDL_MOUSEBUTTONDOWN:
       		if (retourBouton.checkMouse()) screen = 0;
			if (cases.checkMouse()){
				if (aide) {
					aide=false;
					cases.load(w-wB/2-80, 200, 50, 50, texcasevide);
				}
				else{
					aide = true;
					cases.load(w-wB/2-80, 200, 50, 50, texcasecoche);
				}
			}
			if (facile.checkMouse()) {
				difficulte = 0;
				cadre.load(wB/2+40, h/2+50, wB, hB, texcadre);
				gjeu.ouvrir("./data/grille/facile/grille1.txt");
				binaro.setGrille(gjeu);
				grillef.ouvrir("./data/grille/facile/grille1fini.txt");
			}
			if (moyen.checkMouse()) {
				difficulte = 1;
				cadre.load(w/2, h/2+50, wB, hB, texcadre);
				gjeu.ouvrir("./data/grille/moyen/grille1.txt");
				binaro.setGrille(gjeu);
				grillef.ouvrir("./data/grille/moyen/grille1fini.txt");
			}
			if (difficile.checkMouse()) {
				difficulte = 2;
				cadre.load(w-wB/2-40, h/2+50, wB, hB, texcadre);
				gjeu.ouvrir("./data/grille/difficile/grille1.txt");
				binaro.setGrille(gjeu);
				grillef.ouvrir("./data/grille/difficile/grille1fini.txt");
			}
    }
    SDL_RenderClear(rend);
	optionsJeu.render(rend);
	facile.render(rend);
	moyen.render(rend);
	difficile.render(rend);
	cases.render(rend);
	cadre.render(rend);
	retourBouton.render(rend);
	SDL_RenderPresent(rend);
}

void Affichage::renderJeu(){
	SDL_Event event;
  SDL_WaitEvent(&event);

  	switch (event.type) {
      	case SDL_QUIT:
        	quit = true;
        	break;
    	case SDL_MOUSEBUTTONDOWN:
       		if (retourBouton.checkMouse()) screen = 0;
			if (regleBouton.checkMouse()) screen = 3;
			if (indiceBouton.checkMouse()) binaro.indice(grillef);
			if (rejouerBouton.checkMouse()){
				Grille g1;
				g1.ouvrir("./data/grille/grillejeu2.txt");
				binaro.setGrille(g1);
				grillef.ouvrir("./data/grille/grillejeu2fini.txt");
			}
			if(suivantBouton.checkMouse()){
				Grille gjeu;
				switch(difficulte){
					case 0:
						gjeu.ouvrir("./data/grille/facile/grille2.txt");
						binaro.setGrille(gjeu);
						grillef.ouvrir("./data/grille/facile/grille2fini.txt");
					break;
					case 1:
						gjeu.ouvrir("./data/grille/moyen/grille2.txt");
						binaro.setGrille(gjeu);
						grillef.ouvrir("./data/grille/moyen/grille2fini.txt");
					break;
					case 2:
						gjeu.ouvrir("./data/grille/difficile/grille2.txt");
						binaro.setGrille(gjeu);
						grillef.ouvrir("./data/grille/difficile/grille2fini.txt");
					break;
				}
			}
       		for (unsigned int x = 0; x<binaro.getGrille().getDimx(); x++){
				for (unsigned int y = 0; y<binaro.getGrille().getDimy(); y++){
					if (tab[y*binaro.getGrille().getDimx()+x].checkMouse() && !binaro.estGagner())
						switch (binaro.getGrille().getCase(y, x)){
							case 0:
								binaro.getGrille().setCase(1, x, y);
							break;

							case 1:
								binaro.getGrille().setCase(2, x, y);
							break;

							case 2:
								binaro.getGrille().setCase(0, x, y);
							break;
						}
				}
			}
			break;
	}

    SDL_RenderClear(rend);
	fondBinaro.render(rend);

	regleBouton.render(rend);
	indiceBouton.render(rend);
	retourBouton.render(rend);
	rejouerBouton.render(rend);

	renderGrille();

	if(aide){
		binaro.grilleErreur();
		Grille gerr;
		gerr.ouvrir("./data/grille/grillerreur.txt");
		for (unsigned int x = 0; x<gerr.getDimx(); x++){
			for (unsigned int y = 0; y<gerr.getDimy(); y++){
				if (gerr.getCase(x,y) == 5){
					tab[x*gerr.getDimx()+y].load((x*64)+(w/4)-16, (y*64)+(h/4)-32, 64, 64, texerreur);
					tab[x*gerr.getDimx()+y].render(rend);
				}
			}
		}
	}



	if (binaro.getGrille().estPleine()){
		if (binaro.estGagner()){
			gagner.render(rend);
			retourBouton.render(rend);
			rejouerBouton.render(rend);
			suivantBouton.render(rend);
		}
	}
	SDL_RenderPresent(rend);
}

void Affichage::renderRegles(){
	SDL_Event event;

    SDL_WaitEvent(&event);
    switch (event.type) {
      	case SDL_QUIT:
        	quit = true;
          	break;
    	case SDL_MOUSEBUTTONDOWN:
       		if (retourBouton.checkMouse()) screen = 2;
       		if (quitterBouton.checkMouse()) quit = true;
       		break;
    }

    SDL_RenderClear(rend);
	regles.render(rend);
	retourBouton.render(rend);
    SDL_RenderPresent(rend);
}

void Affichage::renderCurrentScreen(){
	while (!quit){
		switch (screen) {
			case 0:
				renderMenu();
				break;
			case 1:
				renderOption();
				break;
			case 2:
				renderJeu();
				break;
			case 3:
				renderRegles();
				break;
		}
	}
}

bool Affichage::getQuit(){
	return quit;
}

Affichage::~Affichage(){
	if (tab!=NULL) delete [] tab;
	SDL_DestroyTexture(texnull);
	SDL_DestroyTexture(tex0);
	SDL_DestroyTexture(tex1);
	SDL_DestroyTexture(texjouer);
	SDL_DestroyTexture(texoption);
	SDL_DestroyTexture(texquitter);
	SDL_DestroyTexture(texretour);
	SDL_DestroyTexture(texregle);
	SDL_DestroyTexture(texwin);
	SDL_DestroyTexture(texregles);
	SDL_DestroyTexture(texfondBinaro);
	SDL_DestroyTexture(texindice);
	SDL_DestroyTexture(texfacile);
	SDL_DestroyTexture(texmoyen);
	SDL_DestroyTexture(texdifficile);
	SDL_DestroyTexture(texoptionJeu);
	SDL_DestroyTexture(texcasevide);
	SDL_DestroyTexture(texcasecoche);
	SDL_DestroyTexture(texcadre);

	SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(app);
    IMG_Quit();
    SDL_Quit();
}
