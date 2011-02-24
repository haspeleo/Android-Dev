#include<iostream>

using namespace std;

static const int INFINITY = 10000;



void IA_jouer(int** jeu,int profondeur);

int Max(int** jeu,int profondeur);

int Min(int** jeu,int profondeur);

int eval(int** jeu);

int gagnant(int** jeu);


void nb_series(int** jeu, int* series_j1, int* series_j2, int n) { //Compte le nombre de séries de n pions alignés de chacun des joueurs

     int compteur1, compteur2, i, j;

     *series_j1 = 0;
     *series_j2 = 0;

     compteur1 = 0;
     compteur2 = 0;

      //Diagonale descendante
     for(i=0;i<3;i++)
     {
          if(jeu[i][i] == 1)
          {
               compteur1++;
               compteur2 = 0;

               if(compteur1 == n)
               {
                    *series_j1++;
               }
          }
          else if(jeu[i][i] == 2)
          {
               compteur2++;
               compteur1 = 0;

               if(compteur2 == n)
               {
                     *series_j2++;
               }
          }
     }

     compteur1 = 0;
     compteur2 = 0;

     //Diagonale montante
     for(i = 0;i < 3; i++)
     {
          if(jeu[i][2-i] == 1)
          {
               compteur1 ++;
               compteur2 = 0;

               if(compteur1 == n)
               {
                    *series_j1 ++;
               }
          }
          else if(jeu[i][2-i] == 2)
          {
               compteur2 ++;
               compteur1 = 0;

               if(compteur2 == n)
               {
                     *series_j2 ++;
               }
          }
     }

     //En ligne
     for(i = 0;i < 3; i++)
     {
          compteur1 = 0;
          compteur2 = 0;

          //Horizontalement
          for(j=0;j<3;j++)
          {
               if(jeu[i][j] == 1)
               {
                    compteur1++;
                    compteur2 = 0;

                    if(compteur1 == n)
                    {
                         *series_j1++;
                    }
               }
               else if(jeu[i][j] == 2)
               {
                    compteur2++;
                    compteur1 = 0;

                    if(compteur2 == n)
                    {
                         *series_j2++;
                    }
               }
          }

          compteur1 = 0;
          compteur2 = 0;

          //Verticalement
          for(j=0;j<3;j++)
          {
               if(jeu[j][i] == 1)
               {
                    compteur1++;
                    compteur2 = 0;

                    if(compteur1 == n)
                    {
                         *series_j1++;
                    }
               }
               else if(jeu[j][i] == 2)
               {
                    compteur2++;
                    compteur1 = 0;

                    if(compteur2 == n)
                    {
                         *series_j2++;
                    }
               }
          }
     }
}

int gagnant(int** jeu) {
     int i,j;
     int j1,j2;

     nb_series(jeu, &j1, &j2, 3);

     if(j1)
     {
          return 1;
     }
     else if(j2)
     {
          return 2;
     }
     else
     {
          //Si le jeu n'est pas fini et que personne n'a gagné, on renvoie 0
          for(i = 0; i < 3; i++)
          {
               for(j = 0; j < 3; j++)
               {
                    if(jeu[i][j] == 0)
                    {
                         return 0;
                    }
               }
          }
     }

     //Si le jeu est fini et que personne n'a gagné, on renvoie 3
     return 3;
}

int Min(int** jeu,int profondeur) {
     if(profondeur == 0 || gagnant(jeu)!=0) {
          return eval(jeu);
     }

     int min = INFINITY;
     int i, j, tmp;

     for(i = 0; i < 3; i++) {
          for(j = 0;j < 3; j++) {
                if(jeu[i][j] == 0) {
                      jeu[i][j] = 1;
                      tmp = Max(jeu, profondeur - 1);

                      if(tmp < min) {
                            min = tmp;
                      }
                      jeu[i][j] = 0;
                }
          }
     }

     return min;
}

int Max(int** jeu,int profondeur) {
     if(profondeur == 0 || gagnant(jeu)!=0) {
          return eval(jeu);
     }

     int max = -INFINITY;
     int i,j,tmp;

     for(i = 0;i < 3; i++) {
          for(j = 0;j < 3; j++) {
                if(jeu[i][j] == 0) {
                      jeu[i][j] = 2;
                      tmp = Min(jeu, profondeur - 1);

                      if(tmp > max) {
                            max = tmp;
                      }
                      jeu[i][j] = 0;
                }
          }
     }

     return max;
}

int eval(int** jeu) {
     int vainqueur,nb_de_pions = 0;
     int i,j;

     //On compte le nombre de pions présents sur le plateau
     for(i=0;i<3;i++) {
          for(j=0;j<3;j++) {
               if(jeu[i][j] != 0) {
                    nb_de_pions++;
               }
          }
     }
     cout <<"NB de pions: "<<nb_de_pions<<endl;

     if( (vainqueur = gagnant(jeu)) != 0) {
          if( vainqueur == 1 ) {
               return 1000 - nb_de_pions;
          }
          else if( vainqueur == 2 ) {
               return -1000 + nb_de_pions;
          }
          else {
               return 0;
          }
     }

     //On compte le nombre de séries de 2 pions alignés de chacun des joueurs
     int series_j1 = 0, series_j2 = 0;

     nb_series(jeu, &series_j1, &series_j2, 2);

     return series_j1 - series_j2;

}

void IA_jouer(int** jeu, int profondeur) {
     int max = -INFINITY;
     int tmp, maxi, maxj;
     int i, j;

     for(i = 0; i < 3; i++)
     {
          for(j = 0; j < 3; j++)
          {
                if(jeu[i][j] == 0) {
                      jeu[i][j] = 1;
                      tmp = Max(jeu, profondeur - 1);

                      if(tmp > max)
                      {
                            max = tmp;
                            maxi = i;
                            maxj = j;
                      }
                      jeu[i][j] = 0;
                }
          }
     }

     jeu[maxi][maxj] = 1;

}


/*
 *
 */
int main(int argc, char** argv) {

    //int *jeu;
    int jeu[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    IA_jouer(jeu, 9);

    return 0;
}

