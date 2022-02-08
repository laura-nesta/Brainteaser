#include "Binaro.h"

using namespace std;

Binaro :: Binaro(){
    grille.ouvrir("./data/grille/grilleInit.txt");
}


Binaro :: Binaro(Grille g){
    g.sauver("./data/grille/grilleconst.txt");
    grille.ouvrir("./data/grille/grilleconst.txt");
}

Grille Binaro :: getGrille() const{
    return grille;
}

void Binaro :: setGrille(Grille g){
    g.sauver("./data/grille/grillecopie.txt");
    grille.ouvrir("./data/grille/grillecopie.txt");
}

bool Binaro :: verifTriple(Grille g) const{
    int dimx = g.getDimx();
    int dimy = g.getDimy();

    for (int i = 0; i<dimx; i++){
      for (int j = 0; j<dimy; j++){
        if(0<i && i<dimx && 0<j && j<dimy){
          if (g.getCase(i, j)==g.getCase(i-1, j) && g.getCase(i, j)==g.getCase(i+1, j)) return false;
          if (g.getCase(i, j)==g.getCase(i, j-1) && g.getCase(i, j)==g.getCase(i, j+1)) return false;
        }
      }
    }
    return true;
}

bool Binaro :: verifNombre(Grille g) const{
    int dimx = g.getDimx();
    int dimy = g.getDimy();
    int cmp0, cmp1;
    for(int i = 0; i < dimx; i++){  
        cmp1 = 0;
        cmp0 = 0;
        for(int j = 0; j < dimy; j++){
            if(g.getCase(i,j) == 1)
                cmp0++;
            if(g.getCase(i,j) == 2)
                cmp1++;   
        }
        if(cmp1 != cmp0)
            return false;
    }
    for(int x = 0; x < dimx; x++){
        cmp1 = 0;
        cmp0 = 0;
        for(int y = 0; y < dimy; y++){
            if(g.getCase(y,x) == 1)
                cmp0++;
            if(g.getCase(y,x) == 2)
                cmp1++;
        }
        if(cmp1 != cmp0)
            return false;
    }
    return true;
}

bool Binaro :: tabidentique(int taille, int *t1, int * t2){
    for(int i = 0; i < taille; i++){
        if(t1[i] != t2[i]){return false;}
    }
    return true;
}

bool Binaro :: LigneIdentique(int ligne1, int ligne2) const{
    int dimx = grille.getDimx();
    for (int i = 0; i<dimx; i++){
        if (grille.getCase(i, ligne1) != grille.getCase(i, ligne2)) return false;
    }
    return true;
}
bool Binaro :: ColoneIdentique(int colone1, int colone2) const{
    int dimy = grille.getDimy();
    for (int i = 0; i<dimy; i++){
        if (grille.getCase(colone1, i) != grille.getCase(colone2, i)) return false;
    }
    return true;
}
bool Binaro :: compareLigne(Grille g) const{
    int dimx = g.getDimx();
    int dimy = g.getDimy();
    for (int i = 0; i<dimx; i++){
        for (int j = 0; j<dimx; j++){
            if(i != j){
                if (LigneIdentique(i, j)) return false;
            }
            
        }
    }

    for (int i = 0; i<dimy; i++){
        for (int j = 0; j<dimy; j++){
            if(i != j){
            if (ColoneIdentique(i, j)) return false;
            }
        }
    }
    return true;
}


bool Binaro :: estGagner(){
    Grille gcopie;
    grille.sauver("./data/grille/grillecopie.txt");
    gcopie.ouvrir("./data/grille/grillecopie.txt");
    gcopie.remplaceElement(4,2);
    gcopie.remplaceElement(3,1);
    if(gcopie.estPleine()){
        return (verifTriple(gcopie) && verifNombre(gcopie) && compareLigne(gcopie));
    }
    return false;
}

void Binaro :: actionJoueur(){
    int x, y, val;
    int c;
    cout<<"quelle case souhaitez-vous modifier ?" <<endl;
    do{
        cout << "x: ligne (0-5)" << endl;
        cin >> x;
    }while(x<0 || x>5);
    do{
        cout << "y: colone (0-5)" << endl;
        cin >> y;
    }while(y<0 || y>5);
    do{
        cout << "quelle valeur souhaitez-vous mettre ? (0,1)" << endl;
        cin >> val;
    }while(!(val==0 || val==1));
    c = val + 1;
    grille.setCase(c, x, y);
}

void Binaro :: tourJeu(){
    actionJoueur();
    grille.afficheBinaro();
}

void Binaro :: testRegression(){
    Binaro b;
    assert(b.getGrille().getDimx()==6);
    assert(b.getGrille().getDimy()==6);
    b.grille.ouvrir("./data/grille/grilletestregression.txt");
    assert(!b.verifNombre(b.grille));
    assert(!b.compareLigne(b.grille));
}

bool Binaro :: lignePleine(int i){
    int dimy = grille.getDimy();
    for(int j=0; j< dimy ; j++){
        if(grille.getCase(i,j) == 0)
            return false;
    }
    return true;
}

bool Binaro :: colonePleine(int i){
    int dimx = grille.getDimx();
    for(int j=0; j< dimx ; j++){
        if(grille.getCase(j, i) == 0)
            return false;
    }
    return true;
}


void Binaro :: grilleErreur(){
    Grille gcopie;
    grille.sauver("./data/grille/grillecopie.txt");
    gcopie.ouvrir("./data/grille/grillecopie.txt");
    gcopie.remplaceElement(4,2);
    gcopie.remplaceElement(3,1);
    
    Grille g;

    g.ouvrir("./data/grille/grilleInit.txt");
    
    int dimx = g.getDimx();
    int dimy = g.getDimy();

   int cmp0, cmp1;
    for(int i = 0; i < dimx; i++){  
        cmp1 = 0;
        cmp0 = 0;
        if(lignePleine(i)){
            for(int j = 0; j < dimy; j++){
                if(gcopie.getCase(i,j) == 1)
                    cmp0++;
                if(gcopie.getCase(i,j) == 2)
                    cmp1++;   
            }
            if(cmp1 != cmp0){
                for(int j = 0; j < dimy; j++){
                    g.setCase(5,j,i);
                }
            }
        }
    }


    int cmp2, cmp3;
    for(int j = 0; j < dimy; j++){  
        cmp2 = 0;
        cmp3 = 0;
        if(colonePleine(j)){
            for(int i = 0; i < dimx; i++){
                if(gcopie.getCase(i,j) == 1)
                    cmp2++;
                if(gcopie.getCase(i,j) == 2)
                    cmp3++;   
            }
            if(cmp2 != cmp3){
                for(int i = 0; i < dimy; i++){
                    g.setCase(5,j,i);
                }
            }
        }
    }

    for (int i = 1; i<dimx-1; i++){
      for (int j = 1; j<dimy-1; j++){
          if (gcopie.getCase(i, j)==gcopie.getCase(i-1, j) && gcopie.getCase(i, j)==gcopie.getCase(i+1, j)){
             g.setCase(5,j,i);
             g.setCase(5,j,i-1);
             g.setCase(5,j,i+1); 
          } 
          if (gcopie.getCase(i, j)==gcopie.getCase(i, j-1) && gcopie.getCase(i, j)==gcopie.getCase(i, j+1)){
            g.setCase(5,j,i);
             g.setCase(5,j-1,i);
             g.setCase(5,j+1,i); 
          }
        }
      }

      for (int i = 0; i<dimx; i++){
        for (int j = 0; j<dimx; j++){
            if(i != j){
                if (LigneIdentique(i, j)) g.setCase(5,j,i);
            }
            
        }
    }


    g.sauver("./data/grille/grillerreur.txt");
    
}

void Binaro :: indice(Grille g){
    srand(time(NULL));
    int dimx = grille.getDimx();
    int dimy = grille.getDimy();
    int x;
    int y;
    if(!grille.estPleine()){
         do{
        x = rand()%dimx;
        y = rand()%dimy; 
    }while(grille.getCase(x,y) != 0);
    int v = g.getCase(x,y);   
    grille.setCase(v,y,x);
    }
}
