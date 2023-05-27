#include "header.h"



int init_nb_ppl(){
  int num_players, verif, choice;  
  
  printf("How many people are going to play (2,3 or 4) ? \n\n");

  choice = 1;
    
  while (choice != 0){
    	verif = scanf("%d", &num_players);
    	vide_buffer();
    	switch(num_players){
    		
    		case 2:
    			choice = 0;
    			break;
    		case 3:
    			choice = 0;
    			break;
    		case 4:
    			choice = 0;
    			break;
    		default:
    			ClearScreen();
    			printf("ERROR ! How many people are going to play (2,3 or 4) ? \n\n");	
    			break;
    	}
    }

  ClearScreen();
  
  return num_players;
}



void player_name(char name[30],int num_of_player){
  printf("What is the name of the player n°%d ? (30 letters max !)\n\n", num_of_player);
  scanf("%s",name);
}

void players_names2(char p1[30], char p2[30]){
  player_name(p1,1);
  ClearScreen();
  player_name(p2,2);
  
}

void players_names3(char p1[30], char p2[30], char p3[30]){
  player_name(p1,1);
  ClearScreen();
  player_name(p2,2);
  ClearScreen();
  player_name(p3,3);
}

void players_names4(char p1[30], char p2[30], char p3[30], char p4[30]){
  player_name(p1,1);
  ClearScreen();
  player_name(p2,2);
  ClearScreen();
  player_name(p3,3);
  ClearScreen();
  player_name(p4,4);
}


void init_player(Player * create, int num_player, T_Role used_roles[NB_ROLE], int coord_x,
                   int coord_y, char yes_roles[NB_ROLE][10], char p_name[30]) {

  strcpy(create->name, p_name);
  create->num = num_player;
  create->role = init_role(used_roles);
  create->kill = 0;
  create->dead = 0;
  create->nb_cases = 0;
  create->chest = 0;
  create->spe_obj = 0;
  create->x = coord_x;
  create->y = coord_y;

  ClearScreen();
  
  switch (num_player) {
  default:
    break;
  
  case 1:
    printf("%s, you are the %s and your color is BLUE !\n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;
    
  case 2:
    printf("%s, you are the %s and your color is GREEN !\n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;
  
  case 3:
    printf("%s, you are the %s and your color is RED !\n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;

  case 4:
    printf("%s, you are the %s and your color is YELLOW !\n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;
  }
}



T_Role init_role(T_Role used_roles[NB_ROLE]) {
  /* Fonction init_role
   Indique un des 4 roles qui n'a pas ete utilse
   Entrees : T_Role used_roles[4] : liste les roles deja utilises
   Sortie  : T_Role pas encore utilise :
  */
  int role_found = 1;
  T_Role role;
  while (role_found) {
    role = rand() % (NB_ROLE - 1);
    role_found = 0;
    for (int i = 0; i < NB_ROLE - 1; i++) {
      if (role == used_roles[i]) {
        role_found = 1;
      }
    }
  }
  return role;
}
