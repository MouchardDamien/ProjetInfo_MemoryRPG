#include "header.h"


void create_plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements1[]) {
  int index;
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < SIZE_PLATEAU; j++) {
      int used = 1;
      while (used) {
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


void create_hiden_plateau(T_Element tab[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements2[]) {
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < SIZE_PLATEAU; j++) {
      tab[i][j] = tab_Elements2[26];
    }
  }
}


void print_Plateau(int nb_p, T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11]) {
  printf("\n\n");
  printf("           \U0001F7E9 \n"); //carre vert
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < (SIZE_PLATEAU); j++) {
      if (j == 0) {
        if (i == 1) {
          printf("\U0001F7E6"); //carre bleu
        } else {
          printf("  ");
        }
      }
      printf("%s ", name_elements[tab_plateau[i][j]]); // Le nom_element permet de
                                            // transformer l'enumeration en
                                                // chaine de caractere
      if (j == 4 && i == 3) {
        if(nb_p > 2){
          printf("\U0001F7E5"); //carre rouge
        }
      }
    }
    printf("\n");
  }
  if(nb_p > 3){
    printf("     \U0001F7E8 \n"); //carre jaune
  }
  printf("\n\n");
}



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
