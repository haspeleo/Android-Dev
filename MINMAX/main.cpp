
#include<iostream>
#define N 3
using namespace std;

int nbCoupsJoues(int jeu[N][N]) {

    int nbCoupsJoues = 0;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (jeu[i][j] != 0) {
                nbCoupsJoues ++;
            }
        }
    }
    return nbCoupsJoues;
}

void coupsPossibles(int** jeu) {
    
}
void IA_jouer(int** jeu, int profondeur) {
    int MAX_VAL = -10000;



}
int Max(int** jeu, int profondeur) {
    int MAX_VAL = -1;

    return MAX_VAL;
}
int Min(int** jeu, int profondeur) {
    int MAX_VAL = -1;


    return MAX_VAL;
}
int eval(int** jeu) {
    
}
int gagnant(int** jeu) {
    return 0;
}


void afficherJeu(int jeu[N][N]) {
    
    for (int i = 0; i < 3; i++) {
        cout <<" "<<endl;
        for(int j = 0; j < 3; j++) {
            cout <<jeu[i][j]<<" ";
        }
    }
    cout <<" "<<endl;
}


/*** PROGRAMME PRINCIPAL ***/
int main() {
  
    int jeu [N][N] = {{0,0,1}, {1,2,0}, {2,0,0}};
    afficherJeu(jeu);

    int casesOccupees = nbCoupsJoues(jeu);
    int casesLibres   = 3 * 3 - casesOccupees;
    cout <<"Cases occupées: "<<casesOccupees<<endl;
    cout <<"Cases Libres: "<<casesLibres<<endl;

    
    
    return 0;
}