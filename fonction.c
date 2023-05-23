#include "header.h"


void ClearScreen(){ 
  printf("\033[H\033[J");
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

void init_player(Player * create, int num_player, T_Role used_roles[NB_ROLE], int coord_x,
                   int coord_y, char yes_roles[NB_ROLE][10]) {
  printf("What is the name of the player n°%d ? \n\n", num_player);
  scanf("%s", create->name);
  printf("\n");
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
    printf("%s, you are the %s and your color is BLUE \n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;
    
  case 2:
    printf("%s, you are the %s and your color is GREEN \n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;
  
  case 3:
    printf("%s, you are the %s and your color is RED \n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;

  case 4:
    printf("%s, you are the %s and your color is YELLOW \n\n", create->name, yes_roles[create->role]);
    sleep(3);
    ClearScreen();
    break;
  }
}

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
  printf("");
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


// Tour de joueur
void player_turn(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_elements[], char name_elements[14][11], char name_roles[NB_ROLE][10]){

  T_Weapon weapon;
  char direction;
  int player_win = 0;
  T_Element one_turn_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  int used[SIZE_PLATEAU][SIZE_PLATEAU];
  
  for(int i=0;i<SIZE_PLATEAU;i++){
  	for(int j=0;j<SIZE_PLATEAU;j++){
  		used[i][j] = 0;
  	}
  }
  
  create_hiden_plateau(one_turn_plateau, tab_elements);
  // Boucle gagnant ou mort
  printf("/////////////////////////\n %s, the %s, it's your turn ! \n/////////////////////////\n\n", player->name,name_roles[player->role]);
  while ((player_win == 0) && (player->dead == 0)) {

    //Saut de ligne pour y voir un peu plus clair
    //for (int k = 0; k < 20; k++) {
    //  printf("\n");
    //}
    
    // Afficher le plateau
    print_Plateau(nb_ppl, one_turn_plateau,name_elements);
    printf("Choose a weapon :\n 0) Torch\n 1) Shield\n 2) Axe\n 3) Bow\n");
    scanf("%d", &weapon);
    // On verfie ce que nous retourne le scanf avec une boucle
    while ((weapon < 0) || (weapon > 3)) {
      printf("Please, choose a number between 0 and 3\n");
      scanf("%*s");  // Ignorer la valeur non valide du flux d'entrée 
                     // (evite une boucle infini a cause de chaine de caractere)
      scanf("%d", &weapon);
      //Attention, bug si on met chaine de caractere --> fait qqch un peu bizarre mais pas dramatique
    }

    printf("\nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");
    int wrong_answer = 0;
    do {
      scanf(" %c", &direction);
      switch (direction) {
      case 'z':
        // On autorise le joueur a monter que s'il est sur le plateau(en x)
        // et qu'il n'est pas sur la ligne du haut
        if ((player->y > 0) && (player->x >= 0) &&
            (player->x <= (SIZE_PLATEAU - 1)) && used[player->y - 1][player->x] == 0){
          player->y--;
          wrong_answer = 0;
          used[player->y][player->x] = 1;
        } 
        else {
          wrong_answer = 1;
          printf("Be careful, stay on the plateau and don't comeback on your steps !\n");
        }
        break;

      case 'q':
        // On autorise le joueur a aller a gauche que s'il est sur le plateau(en
        // y) et qu'il n'est pas sur la ligne de gauche
        if ((player->x > 0) && (player->y >= 0) &&
            (player->y <= (SIZE_PLATEAU - 1)) && used[player->y][player->x - 1] == 0){
          player->x--;
          wrong_answer = 0;
          used[player->y][player->x] = 1;
        } 
        else {
          wrong_answer = 1;
          printf("Be careful, stay on the plateau and don't comeback on your steps !\n");
        }
        break;

      case 's':
        // On autorise le joueur a aller en bas que s'il est sur le plateau(en
        // x) et qu'il n'est pas sur la ligne en bas
        if ((player->y < (SIZE_PLATEAU - 1)) && (player->x >= 0) &&
            (player->x <= (SIZE_PLATEAU - 1)) && used[player->y + 1][player->x] == 0){
          player->y++;
          wrong_answer = 0;
          used[player->y][player->x] = 1;
        } 
        else {
          wrong_answer = 1;
          printf("Be careful, stay on the plateau and don't comeback on your steps !\n");
        }
        break;

      case 'd':
        // On autorise le joueur a aller a droite que s'il est sur le plateau(en
        // y) et qu'il n'est pas sur la ligne de droite
        if ((player->x < (SIZE_PLATEAU - 1)) && (player->y >= 0) &&
            (player->y <= (SIZE_PLATEAU - 1)) && used[player->y][player->x + 1] == 0){
          player->x++;
          wrong_answer = 0;
          used[player->y][player->x] = 1;
        } 
        else {
          wrong_answer = 1;
          printf("Be careful, stay on the plateau and don't comeback on your steps !\n");
        }
        break;

      default:
        printf("Please, choose an element between: z, q, s and d\n");
        break;

      } // fin du switch
      printf("Info Position: (%d, %d)\n\n", player->x, player->y);
      if (wrong_answer == 1) {
        printf("Please, choose an element between: z, q, s and d\n\n");
      }
    } while (wrong_answer == 1);
    
    one_turn_plateau[player->y][player->x] = plateau[player->y][player->x]; //On relie les 2 tableaux

    ClearScreen();

    // Afficher le plateau
    print_Plateau(nb_ppl,one_turn_plateau, name_elements);
    
    switch(one_turn_plateau[player->y][player->x]){

      //Le cas des monstres
      case ZOMBIE:
        if(weapon == TORCH){
          printf("Good job !\nYou kill a Zombie !\n");
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nThe Zombie is better than you...\n");
          player->dead = 1;
        }
      break;

      case TROLL:
        if(weapon == AXE){
          printf("Good job !\nYou kill a Troll !\n");
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nThis Troll is so much strong...\n");
          player->dead = 1;
        }
      break;

      case BASILISK:
        if(weapon == SHIELD){
          printf("Good job !\nYou kill a Basilisk !\n");
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nDon't look a basilisk in the eye...\n");
          player->dead = 1;
        }
      break;

      case HARPY:
        if(weapon == BOW){
          printf("Good job !\nYou kill a Harpy !\n");
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nThe harpy had the advantage of height...\n");
          player->dead = 1;
        }
      break;

      //Le cas des armes secrètes
      case WARRIOR_WEAPON:
        if(player->role == WARRIOR){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj++;
        }
        break;
          
      case RANGER_WEAPON:
        if(player->role == RANGER){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj++;
        }
        break;

      case MAGE_WEAPON:
        if(player->role == MAGE){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj++;
        }
        break;

      case THIEF_WEAPON:
        if(player->role == THIEF){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj++;
        }
        break;

      //Le cas des autres objets
      case CHEST:
        printf("Congratualtion ! You have a legendary chest !\n");
        player->chest++;
        break;

      case PORTAL:
        printf("You find the portal !\nChoose a square in the plateau:\n");
        printf("Your x coordinate: \n");
        scanf("%d", &player->x);
        printf("Your y coordinate: \n");
        scanf("%d", &player->y);
        
        switch(nb_ppl){
  	case 2:
  		while((player->x == 3 && player->y == 0) || (player->x == 0 && player->y == 1)){
  			printf("You aren't allowed to teleport here ! \n");
  			printf("Your new x coordinate: \n");
        		scanf("%d", &player->x);
        		printf("Your new y coordinate: \n");
        		scanf("%d", &player->y);
        	}
  		break;
  	case 3:
  		while((player->x == 3 && player->y == 0) || (player->x == 0 && player->y == 1) || (player->x == 4 && player->y == 3)){
  			printf("You aren't allowed to teleport here ! \n");
  			printf("Your new x coordinate: \n");
        		scanf("%d", &player->x);
        		printf("Your new y coordinate: \n");
        		scanf("%d", &player->y);
        	}
  		break;
  	case 4:
  		while((player->x == 3 && player->y == 0) || (player->x == 0 && player->y == 1) || (player->x == 4 && player->y == 3) || (player->x == 1 && player->y == 4)){
  			printf("You aren't allowed to teleport here ! \n");
  			printf("Your new x coordinate: \n");
        		scanf("%d", &player->x);
        		printf("Your new y coordinate: \n");
        		scanf("%d", &player->y);
        	}
  		break;
  	default:
  		break;
  	}
        
        one_turn_plateau[player->y][player->x] = plateau[player->y][player->x];
        //Attention, il reste a verifier si la case de teleportation est bien face cache, 
        //et qu'il rempli bien des nombres entre 0 et 4
        print_Plateau(nb_ppl,one_turn_plateau, name_elements);
        switch(one_turn_plateau[player->y][player->x]){

      		//Le cas des monstres
      		case ZOMBIE:
        		if(weapon == TORCH){
          		printf("Good job !\nYou kill a Zombie !\n");
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
          		printf("You are dead...\nThe Zombie is better than you...\n");
          		player->dead = 1;
        		}
      		break;
	
      		case TROLL:
        		if(weapon == AXE){
          		printf("Good job !\nYou kill a Troll !\n");
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
         		printf("You are dead...\nThis Troll is so much strong...\n");
          		player->dead = 1;
        		}
      		break;

      		case BASILISK:
        		if(weapon == SHIELD){
          		printf("Good job !\nYou kill a Basilisk !\n");
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
         		printf("You are dead...\nDon't look a basilisk in the eye...\n");
          		player->dead = 1;
        		}
      		break;

      		case HARPY:
        		if(weapon == BOW){
          		printf("Good job !\nYou kill a Harpy !\n");
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
          		printf("You are dead...\nThe harpy had the advantage of height...\n");
          		player->dead = 1;
        		}
      		break;

      		//Le cas des armes secrètes
      		case WARRIOR_WEAPON:
        		if(player->role == WARRIOR){
          		printf("Congratulation ! You have your secret weapon !\n");
          		player->spe_obj++;
        		}
        		break;
      
      		case RANGER_WEAPON:
        		if(player->role == RANGER){
          		printf("Congratulation ! You have your secret weapon !\n");
          		player->spe_obj++;
        		}
        		break;

      		case MAGE_WEAPON:
        		if(player->role == MAGE){
          		printf("Congratulation ! You have your secret weapon !\n");
          		player->spe_obj++;
        		}
        		break;

      		case THIEF_WEAPON:
        		if(player->role == THIEF){
          		printf("Congratulation ! You have your secret weapon !\n");
          		player->spe_obj++;
        		}
        		break;

      		//Le cas des autres objets
      		case CHEST:
        		printf("Congratualtion ! You have a legendary chest !\n");
        		player->chest++;
        		break;

      		case TOTEM:
        		printf("You find the transmution totem, interesting\nChoose a hiden square:\n");
        		printf("Your x coordinate: \n");
        		int temp_x;
        		scanf("%d", &temp_x);
        		printf("Your y coordinate: \n");  
        		int temp_y;
        		scanf("%d", &temp_y );
        		T_Element temp =  plateau[temp_y][temp_x];
        		plateau[temp_y][temp_x] = plateau[player->y][player->x];
        		plateau[player->y][player->x] = temp;
        		print_Plateau(nb_ppl, plateau, name_elements);
        		//Attention, nous ne pouvons pas transposé un objet sur une case 
        		//en face d'une case de sortie de joueur
        		player->dead = 1; //Le joueur n'est pas vraiement mort mais c'est pour mettre fin au tour
        		break;

      		default:
        		break;
    		}
        break;

      case TOTEM:
        printf("You find the transmution totem, interesting\nChoose a hiden square:\n");
        printf("Your x coordinate: \n");
        int temp_x;
        scanf("%d", &temp_x);
        printf("Your y coordinate: \n");  
        int temp_y;
        scanf("%d", &temp_y );
        T_Element temp =  plateau[temp_y][temp_x];
        plateau[temp_y][temp_x] = plateau[player->y][player->x];
        plateau[player->y][player->x] = temp;
        print_Plateau(nb_ppl, plateau, name_elements);
        //Attention, nous ne pouvons pas transposé un objet sur une case 
        //en face d'une case de sortie de joueur
        player->dead = 1; //Le joueur n'est pas vraiement mort mais c'est pour mettre fin au tour
        break;

      default:
        break;
    }
    
    if (plateau[player->x][player->y] == CHEST) {
      player->chest += 1;
    }

    if (((player->role == WARRIOR) &&
         (plateau[player->x][player->y] == WARRIOR_WEAPON)) ||
        ((player->role == RANGER) &&
         (plateau[player->x][player->y] == RANGER_WEAPON)) ||
        ((player->role == MAGE) && (plateau[player->x][player->y] == MAGE_WEAPON))
    ||
        ((player->role == THIEF) && (plateau[player->x][player->y] == THIEF))) {
      player->spe_obj += 1;
    }

    if(player->spe_obj == 1 && player->chest == 1){
      player_win = 1;
      printf("\n %s win ! Congratulation ! \n", player->name);
    }
    
    if (player->dead == 1){
    	player->spe_obj = 0;
    	player->chest = 0;
    }

  } // fin do / while
}


void game2(Player * playerA, Player * playerB, T_Element  plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role1[NB_ROLE][10]){
  int player_not_win = 1;
  while(player_not_win == 1){

    printf("\n");
    player_turn(nb_player, playerA, plateau, tab_elements, name_elements, name_role1);
    if (playerA->chest == 1 && playerA->spe_obj == 1){
      player_not_win = 0;
    }
    
    printf("\n");
    if(player_not_win == 1){
      ClearScreen();
      player_turn(nb_player, playerB, plateau, tab_elements, name_elements, name_role1);
      if (playerB->chest == 1 && playerB->spe_obj == 1){
        player_not_win = 0;
      }
    }
  }
}
  
void game3(Player * playerA, Player * playerB, Player * playerC, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role2[NB_ROLE][10]){
  int player_not_win = 1;
  while(player_not_win){

    printf("\n");
    player_turn(nb_player, playerA, plateau, tab_elements, name_elements, name_role2);
    if (playerA->chest == 1 && playerA->spe_obj == 1){
      player_not_win = 0;
    }
    
    printf("\n");
    if(player_not_win == 1){
      ClearScreen();
      player_turn(nb_player, playerB, plateau, tab_elements, name_elements, name_role2);
      if (playerB->chest == 1 && playerB->spe_obj == 1){
        player_not_win = 0;
      }
    }
    
    printf("\n");
    if(player_not_win == 1){
      ClearScreen();
      player_turn(nb_player, playerC, plateau, tab_elements, name_elements, name_role2);
      if (playerC->chest == 1 && playerC->spe_obj == 1){
        player_not_win = 0;
      }
    }
  }
}
  
void game4(Player * playerA, Player * playerB, Player * playerC, Player * playerD, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role3[NB_ROLE][10]){
  int player_not_win = 1;
  while(player_not_win){

    printf("\n");
    player_turn(nb_player, playerA, plateau, tab_elements, name_elements, name_role3);
    if (playerA->chest == 1 && playerA->spe_obj == 1){
      player_not_win = 0;
    }
    
    printf("\n");
    if(player_not_win == 1){
      ClearScreen();
      player_turn(nb_player, playerB, plateau, tab_elements, name_elements, name_role3);
      if (playerB->chest == 1 && playerB->spe_obj == 1){
        player_not_win = 0;
      }
    }
    
    printf("\n");
    if(player_not_win == 1){
      ClearScreen();
      player_turn(nb_player, playerC, plateau, tab_elements, name_elements, name_role3);
      if (playerC->chest == 1 && playerC->spe_obj == 1){
        player_not_win = 0;
      }
    }
    
    printf("\n");
    if(player_not_win == 1){
      ClearScreen();
      player_turn(nb_player, playerD, plateau, tab_elements, name_elements, name_role3);
      if (playerD->chest == 1 && playerD->spe_obj == 1){
        player_not_win = 0;
      }
    }  
  }  
}

