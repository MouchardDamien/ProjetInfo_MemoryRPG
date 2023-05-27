#include "header.h"


//Fonction player_turn
//Permet de facon globale de faire le tour entier d'un joueur
int player_turn(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_elements[], char name_elements[14][11], char name_roles[NB_ROLE][10]){

  T_Weapon weapon = -1;
  char direction;
  int player_win = 0, verif,choice;
  T_Element one_turn_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  int used[SIZE_PLATEAU][SIZE_PLATEAU];
  char verif2;
  
  for(int i=0;i<SIZE_PLATEAU;i++){
  	for(int j=0;j<SIZE_PLATEAU;j++){
  		used[i][j] = 0;
  	}
  }
  
  create_hiden_plateau(one_turn_plateau, tab_elements);//On cree le plateau avec toutes les cases masquees

  printf("---------------------------------------\n %s, the %s, it's your turn ! \n---------------------------------------\n\n", player->name,name_roles[player->role]);

   switch(player->num){
  	
  	case 1:
  		player->x = -1;
  		player->y = 1;
  		break;
  	case 2:
  		player->x = 3;
  		player->y = -1;
  		break;
  	case 3:
  		player->x = 5;
  		player->y = 3;
  		break;
  	case 4:
  		player->x = 1;
  		player->y = 5;
  		break;
  	default:
  		printf("ERROR IN one_turn FUNCTION !!! \n\n");
  		break;
  }
  player->spe_obj = 0;
  player->chest = 0;
  player->dead = 0;

  // Boucle pour le tour du joueur
  // Boucle qui continu tant qu'il n'y a pas de gagnant ou de mort
  while ((player_win != 1) && (player->dead != 1)) {
    
    // Afficher le plateau
    print_Plateau(nb_ppl, one_turn_plateau,name_elements);
    name(player);

    //Choisi une arme
    weapon = choose_weapon(nb_ppl,player,one_turn_plateau, name_elements);

    //Choisi une direction
    direction = choose_direction(nb_ppl,player,one_turn_plateau,name_elements,used);
    
    one_turn_plateau[player->y][player->x] = plateau[player->y][player->x]; //On relie les 2 tableaux
    
    ClearScreen();

    // Afficher le plateau
    print_Plateau(nb_ppl,one_turn_plateau, name_elements);
    name(player);
    
    if(player->dead != 1){
    	interaction_box(nb_ppl, player,plateau,one_turn_plateau,name_elements,weapon,used);
    }
    
    if(player->spe_obj == 1 && player->chest == 1){ //On regarde s'il a gagne ou non
      player_win = 1;
      sleep(1);
      ClearScreen();
      printf("\n %s win ! Congratulation ! \n\n You have done %d kills and move on a box %d times !\n\n", player->name,player->kill,player->nb_cases);
      printf("Here is the tray completely visible : \n\n");
      print_Plateau(nb_ppl, plateau, name_elements);
      return 1;
    }

    
    if (player->dead == 1){
    	player->spe_obj = 0;
    	player->chest = 0;
      return 0;
    }

  } // fin do-while (de la boule du tour de joueur)
  printf("ERROR IN one_turn FUNCTION !!!");
  return -1;
}
