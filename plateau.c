#include "header.h"

//Fonction create_plateau
//Permet de creer un plateau 5*5 de facon aleatoire
void create_plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements1[]) {
  int index;
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < SIZE_PLATEAU; j++) {
      int used = 1;
      while (used) { //On verifie qu'un element n'ai pas deja ete pris pour pouvoir le mettre dans le plateau
        index = rand() % 25;
        if (tab_Elements1[index] != USED) {
          tab_plateau[i][j] = tab_Elements1[index];
          tab_Elements1[index] = USED;
          used = 0;
        }
      }
    }
  }
}

//Fonction create_hiden_plateau
//Permet de creer un plateau 5*5 avec seulement des cases cachees
void create_hiden_plateau(T_Element tab[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements2[]) {
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < SIZE_PLATEAU; j++) {
      tab[i][j] = tab_Elements2[26];
    }
  }
}

//Fonction print_Plateau
//Permet d'afficher un plateau
void print_Plateau(int nb_p, T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11]) {
  printf("\n\n");
  printf("           \U0001F7E9 \n"); 
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < (SIZE_PLATEAU); j++) {
      if (j == 0) {
        if (i == 1) {
          printf("\U0001F7E6"); 
        } else {
          printf("  ");
        }
      }
      printf("%s ", name_elements[tab_plateau[i][j]]); // Le nom_element permet de
                                            // transformer l'enumeration en
                                                // chaine de caractere
      if (j == 4 && i == 3) {
        if(nb_p > 2){
          printf("\U0001F7E5"); 
        }
      }
    }
    printf("\n");
  }
  if(nb_p > 3){
    printf("     \U0001F7E8 \n"); 
  }
  printf("\n\n");
}


//Fonction name
//Permet d'afficher le nom du joueur quand c'est son tour de jouer ainsi que sa couleur avec les emojis unicode
void name(Player * A){

  switch(A->num){

    case 1:
      printf("\t\U0001F7E6: %s's turn\n\n\n",A->name);
      break;

    case 2:
      printf("\t\U0001F7E9: %s's turn\n\n\n",A->name);
      break;

    case 3:
      printf("\t\U0001F7E5: %s's turn\n\n\n",A->name);
      break;

    case 4:
      printf("\t\U0001F7E8: %s's turn\n\n\n",A->name);
      break;
  }
}
