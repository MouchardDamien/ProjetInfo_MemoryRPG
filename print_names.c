#include "header.h"


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



void names2(Player * A, Player * B){
  printf("\t\U0001F7E6: %s \t\U0001F7E9: %s\n\n\n",A->name,B->name);
}



void names3(Player * A, Player * B,Player * C){
  printf("\t\U0001F7E6: %s \t\U0001F7E9: %s \t\U0001F7E5: %s\n\n\n",A->name,B->name,C->name);
}



void names4(Player * A, Player * B, Player * C, Player * D){
  printf("\t\U0001F7E6: %s \t\U0001F7E9: %s \t\U0001F7E5: %s \t\U0001F7E8: %s\n\n\n",A->name,B->name,C->name,D->name);
}
