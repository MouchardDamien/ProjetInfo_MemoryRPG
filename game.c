#include "header.h"

//Fonction game2
//Permet de lancer la partie pour 2 joueurs
void game2(Player * playerA, Player * playerB, T_Element  plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role1[NB_ROLE][10]){
  int player_not_win = 0;
  while(player_not_win != 1){

    printf("\n");
    player_not_win = player_turn(nb_player, playerA, plateau, tab_elements,   name_elements, name_role1);
    
    printf("\n");
    if(player_not_win != 1){ //Verifie si le joueur a gagne
      ClearScreen();
      player_not_win = player_turn(nb_player, playerB, plateau, tab_elements, name_elements, name_role1);
    }
  }
}


//Fonction game3
//Permet de lancer la partie pour 3 joueurs
void game3(Player * playerA, Player * playerB, Player * playerC, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role2[NB_ROLE][10]){
  int player_not_win = 0;
  while(player_not_win != 1){

    printf("\n");
    player_not_win = player_turn(nb_player, playerA, plateau, tab_elements, name_elements, name_role2);
    
    printf("\n");
    if(player_not_win != 1){ //Verifie si le joueur a gagne
      ClearScreen();
      player_not_win = player_turn(nb_player, playerB, plateau, tab_elements, name_elements, name_role2);
    }
    
    
    printf("\n");
    if(player_not_win != 1){ //Verifie si le joueur a gagne
      ClearScreen();
      player_not_win = player_turn(nb_player, playerC, plateau, tab_elements, name_elements, name_role2);
    }
  }
}

//Fonction game4
//Permet de lancer la partie pour 4 joueurs
void game4(Player * playerA, Player * playerB, Player * playerC, Player * playerD, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role3[NB_ROLE][10]){
  int player_not_win = 0;
  while(player_not_win != 1){

    printf("\n");
    player_not_win = player_turn(nb_player, playerA, plateau, tab_elements, name_elements, name_role3);
    
    
    printf("\n");
    if(player_not_win != 1){ //Verifie si le joueur a gagne
      ClearScreen();
      player_not_win = player_turn(nb_player, playerB, plateau, tab_elements, name_elements, name_role3);
    }
    
    
    printf("\n");
    if(player_not_win != 1){ //Verifie si le joueur a gagne
      ClearScreen();
      player_not_win = player_turn(nb_player, playerC, plateau, tab_elements, name_elements, name_role3);
    }
    
    printf("\n");
    if(player_not_win != 1){ //Verifie si le joueur a gagne
      ClearScreen();
      player_not_win = player_turn(nb_player, playerD, plateau, tab_elements, name_elements, name_role3);
    }
  }  
}
