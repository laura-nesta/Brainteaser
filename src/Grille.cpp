#include "Grille.h"

using namespace std;

Grille::Grille(){
    dimx = 0;
    dimy = 0;
    tab = NULL;
}

Grille::Grille(int dimensionx, int dimensiony){
    dimx = dimensionx;
    dimy = dimensiony;
}

Grille::~Grille(){
    if (tab == NULL) delete [] tab;
    dimx = 0;
    dimy = 0;
}

bool Grille :: estPleine() const{
    int taille = dimx * dimy;
    for(int i=0; i < taille; i++){
        if(tab[i] == 0){
            return false;  
        }
    }
    return true;
}

void Grille :: setCase(int c, int x, int y){ 
    tab[x*dimx+y] = c;
}

int Grille :: getCase(int x, int y) const{
    return tab[y*dimx+x];
}

unsigned int Grille :: getDimx() const{
    return dimx;
}

unsigned int Grille :: getDimy() const{
    return dimy;
}


void Grille::testRegression (){
    Grille g(6,6);
    assert(dimx >= 0);
    assert(dimy >= 0);
    assert(g.dimx == 6);
    assert(g.dimy == 6);
    assert(g.tab != NULL);
    for(int i=0; i < dimx*dimy; i++){
      assert(g.tab[i] == 0 );
    }
  }


void Grille::sauver(const std::string & filename) const{
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    for(int y=0; y<dimy; ++y)
      for(int x=0; x<dimx; ++x) {
        int c = tab[y*dimx+x];
        fichier << +c <<  " ";
        }
    fichier.close();
}

void Grille :: ouvrir(const std::string & filename){
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	int e;
	string mot, ligne;
    ligne = "\n";
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy;
	tab = new int[dimx*dimy];
    for(int y=0; y<dimy; ++y){
        for(int x=0; x<dimx; ++x){
            fichier >> e;
            tab[y*dimx+x] = e;
        }
    }
    fichier.close();
}

void Grille::afficheConsole() const{
    if(tab == NULL){
    cout << dimx << " " << dimy << endl;
    }
    for(int y=0; y<dimy; ++y) {
      for(int x=0; x<dimx; ++x) {
        int c = tab[y*dimx+x];
        if(c == 0){
            cout << "-" << " ";
        }
        else{
            cout << +c << " " ;
        }
      }
      cout << endl;
    }
    cout<<endl;
}

void Grille::afficheBinaro() const{
    if(tab == NULL){
    cout << dimx << " " << dimy << endl;
    }
    for(int y=0; y<dimy; ++y) {
      for(int x=0; x<dimx; ++x) {
        int c = tab[y*dimx+x];
        int val = c -1;
        if(c == 0){
            cout << "-" << " ";
        }
        else{
            cout << +val << " " ;
        }
      }
      cout << endl;
    }
    cout<<endl;
}

void Grille ::remplaceElement(int val, int valn) {
    for(int y=0; y<dimy; y++){
        for(int x=0; x<dimx; x++){
            if(tab[y*dimx+x] == val){
                tab[y*dimx+x] = valn;
            }
        }
    }
}