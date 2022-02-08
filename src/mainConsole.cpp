#include "Binaro.h"

using namespace std;

int main(){

    Binaro bfini,binit,b;
    Grille gfini, ginit;

    gfini.ouvrir("./data/grillebin.txt");
    ginit.ouvrir("./data/grillejeu.txt");

    binit.setGrille(ginit);
    bfini.setGrille(gfini);
    bfini.getGrille().afficheBinaro();

    cout << bfini.getGrille().estPleine()<<"plein ok:1"<<endl;
    cout << bfini.compareLigne(bfini.getGrille())<<"comparez ok: 1"<<endl;
    cout << bfini.verifNombre(bfini.getGrille())<<"nb ok:1"<<endl;
    cout<<bfini.verifTriple(bfini.getGrille())<<"triple ok: 1"<<endl;
    cout << bfini.estGagner()<<"gagner ok: 1"<<endl;

    while(!binit.getGrille().estPleine()){
        binit.tourJeu();
    }
    if(binit.estGagner()){
        cout << "Felicitations!! Vous avez gagné :)" << endl;
    }
    else{
        do{
        cout<< " la grille n'est pas juste, réessayez" << endl;
        binit.tourJeu();
    }
    while(!binit.estGagner());
    cout << "Felicitations!! Vous avez gagné :)" << endl;
    }
    
    
    return 0;
}