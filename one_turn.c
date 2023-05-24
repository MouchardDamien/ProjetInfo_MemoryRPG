#include "header.h"


// Tour de joueur
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
  
  create_hiden_plateau(one_turn_plateau, tab_elements);
  // Boucle gagnant ou mort
  printf("------------------------------------\n %s, the %s, it's your turn ! \n------------------------------------\n\n", player->name,name_roles[player->role]);
  while ((player_win == 0) && (player->dead == 0)) {

    player->spe_obj = 0;
    player->chest = 0;
    
    // Afficher le plateau
    print_Plateau(nb_ppl, one_turn_plateau,name_elements);
    name(player);
    
    printf("Choose a weapon :\n 1) Torch \U0001F525\n 2) Mirror \U0001FA9E\n 3) Axe \U0001FA93\n 4) Bow \U0001F3F9\n");
    
    choice = 1;
    
    while (choice){ // On verfie ce que nous retourne le scanf avec une boucle
    	verif = scanf("%d",&weapon);
    	vide_buffer();
    	switch(weapon){
    		
    		case 1:
    			weapon --;
    			choice = 0;
    			break;
    		case 2:
    			weapon --;
    			choice = 0;
    			break;
    		case 3:
    			weapon --;
    			choice = 0;
    			break;
    		case 4:
    			weapon --;
    			choice = 0;
    			break;
    		default:
    			ClearScreen();
    			print_Plateau(nb_ppl, one_turn_plateau,name_elements);
          name(player);
    			printf("ERROR ! \nChoose a weapon :\n 1) Torch \U0001F525\n 2) Mirror \U0001FA9E\n 3) Axe \U0001FA93\n 4) Bow \U0001F3F9\n");	
    			break;
    	}
    }
    
    printf("\nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");
    
    int wrong_answer = 0;
    do {
      choice = 1;
      while (choice){
      	verif2 = scanf(" %c", &direction);
      	vide_buffer();
      	switch(direction){
    		
    		case 'z':
    			if ((player->y > 0) && (player->x >= 0) && (player->x <= (SIZE_PLATEAU - 1)) 				&& used[player->y - 1][player->x] == 0){
          			player->y--;
          			wrong_answer = 0;
          			used[player->y][player->x] = 1;
        		} 
        		else {
          			wrong_answer = 1;
          			printf("Be careful, stay on the plateau and don't comeback on your steps !\nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");
        		}
    			choice = 0;
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
          			printf("Be careful, stay on the plateau and don't comeback on your steps !\nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");
        		}
    			choice = 0;
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
          			printf("Be careful, stay on the plateau and don't comeback on your steps !\nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");
        		}
    			choice = 0;
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
          			printf("\nBe careful, stay on the plateau and don't comeback on your steps !\nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");
        		}
    			choice = 0;
    			break;
    		
    		default:
    			ClearScreen();
    			print_Plateau(nb_ppl, one_turn_plateau,name_elements);
          name(player);
    			printf("ERROR ! \nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");	
    			break;
    	}
      }
    } while (wrong_answer == 1);
    
    player->nb_cases++;
    
    one_turn_plateau[player->y][player->x] = plateau[player->y][player->x]; //On relie les 2 tableaux
    
    ClearScreen();

    // Afficher le plateau
    print_Plateau(nb_ppl,one_turn_plateau, name_elements);
    name(player);
    
    //if() tester quand il est bloqué !
    
    switch(one_turn_plateau[player->y][player->x]){

      //Le cas des monstres
      case ZOMBIE:
        if(weapon == TORCH){
          printf("Good job !\nYou kill a Zombie !\n");
          player->kill++;
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nThe Zombie is better than you...\n");
          sleep(2);
          player->dead = 1;
        }
      break;

      case TROLL:
        if(weapon == AXE){
          printf("Good job !\nYou kill a Troll !\n");
          player->kill++;
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nThis Troll is so much strong...\n");
          sleep(2);
          player->dead = 1;
        }
      break;

      case BASILISK:
        if(weapon == MIRROR){
          printf("Good job !\nYou kill a Basilisk !\n");
          player->kill++;
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nDon't look a basilisk in the eye...\n");
          sleep(2);
          player->dead = 1;
        }
      break;

      case HARPY:
        if(weapon == BOW){
          printf("Good job !\nYou kill a Harpy !\n");
          player->kill++;
          one_turn_plateau[player->y][player->x] = EMPTY;
        }
        else{
          printf("You are dead...\nThe harpy had the advantage of height...\n");
          sleep(2);
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
        player->x --;
        printf("Your y coordinate: \n");
        scanf("%d", &player->y);
        player->y --;
        
        while(player->x<1 || player->x>5){
          printf("Error for the x ! Choose a number beetween 1 and 5 :");
          scanf("%d",&player->x);
          player->x --;
        }

        while(player->y<1 || player->y>5){
          printf("Error for the y ! Choose a number beetween 1 and 5 :");
          scanf("%d",&player->y);
          player->y --;
        }
        
        one_turn_plateau[player->y][player->x] = plateau[player->y][player->x];
        //Attention, il reste a verifier si la case de teleportation est bien face cache, 
        //et qu'il rempli bien des nombres entre 0 et 4
        print_Plateau(nb_ppl,one_turn_plateau, name_elements);
        name(player);
        switch(one_turn_plateau[player->y][player->x]){

      		//Le cas des monstres
      		case ZOMBIE:
        		if(weapon == TORCH){
          		printf("Good job !\nYou kill a Zombie !\n");
              player->kill++;
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
          		printf("You are dead...\nThe Zombie is better than you...\n");
          		sleep(2);
          		player->dead = 1;
        		}
      		break;
	
      		case TROLL:
        		if(weapon == AXE){
          		printf("Good job !\nYou kill a Troll !\n");
              player->kill++;
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
         		printf("You are dead...\nThis Troll is so much strong...\n");
         		sleep(2);
          		player->dead = 1;
        		}
      		break;

      		case BASILISK:
        		if(weapon == MIRROR){
          		printf("Good job !\nYou kill a Basilisk !\n");
              player->kill++;
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
         		printf("You are dead...\nDon't look a basilisk in the eye...\n");
         		sleep(2);
          		player->dead = 1;
        		}
      		break;

      		case HARPY:
        		if(weapon == BOW){
          		printf("Good job !\nYou kill a Harpy !\n");
              player->kill++;
          		one_turn_plateau[player->y][player->x] = EMPTY;
        		}
        		else{
          		printf("You are dead...\nThe harpy had the advantage of height...\n");
          		sleep(2);
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
        		temp_x--;
        		printf("Your y coordinate: \n");  
        		int temp_y;
        		scanf("%d", &temp_y );
        		temp_y--;
            
            switch(nb_ppl){
  	           case 2:
  		            while((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x<1 || temp_x>5) || (temp_y<1 || temp_y>5)){
  			             printf("You aren't allowed to change this box or the coordonate are wrong ! \nPlease enter coordonate beetween 1 and 5. \n\n");
  			             printf("Your new x coordinate: \n");
        		         scanf("%d", &temp_x);
        		         temp_x--;
        		         printf("Your new y coordinate: \n");
        		         scanf("%d", &temp_y);
        		         temp_y--;
        	         }
  		            
                 break;
  	           case 3:
  		            while((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x == 4 && temp_y == 3) || (temp_x<1 || temp_x>5) || (temp_y<1 || temp_y>5)){
  			              printf("You aren't allowed to change this box or the coordonate are wrong ! \nPlease enter coordonate beetween 1 and 5. \n\n");
  			              printf("Your new x coordinate: \n");
        		          scanf("%d", &temp_x);
        		          temp_x--;
        		          printf("Your new y coordinate: \n");
        		          scanf("%d", &temp_y);
        		          temp_y--;
        	        }
  		            break;
  	           case 4:
  		            while((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x == 4 && temp_y == 3) || (temp_x == 1 && temp_y == 4) || (temp_x<1 || temp_x>5) || (temp_y<1 || temp_y>5)){
  			              printf("You aren't allowed to change this box or the coordonate are wrong ! \nPlease enter coordonate beetween 1 and 5. \n\n");
  			              printf("Your new x coordinate: \n");
        		          scanf("%d", &temp_x);
        		          temp_x--;
        		          printf("Your new y coordinate: \n");
        		          scanf("%d", &temp_y);
        		          temp_y--;
        	         }
  		            break;
  	           default:
  		            break;
  	               }
            
            T_Element temp =  plateau[temp_y -1][temp_x -1];
            plateau[temp_y -1][temp_x -1] = plateau[player->y][player->x];
        		plateau[player->y][player->x] = temp;
        		print_Plateau(nb_ppl, plateau, name_elements);
            name(player);
        		//Attention, nous ne pouvons pas transposé un objet sur une case 
        		//en face d'une case de sortie de joueur
        		player->dead = 1; //Le joueur n'est pas vraiement mort mais c'est pour mettre fin au tour
        		break;

      		default:
        		break;
    		}
        break;

      case TOTEM:
        printf("You find the transmution totem, interesting, choose an hidden square to change your actual box with another one:\n");
        printf("Your x coordinate: \n");
        int temp_x;
        scanf("%d", &temp_x);
        temp_x--;
        printf("Your y coordinate: \n");  
        int temp_y;
        scanf("%d", &temp_y );
        temp_y--;
        
            switch(nb_ppl){
  	           case 2:
  		            while((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x<1 || temp_x>5) || (temp_y<1 || temp_y>5)){
  			             printf("You aren't allowed to change this box or the coordonate are wrong ! \nPlease enter coordonate beetween 1 and 5. \n\n");
  			             printf("Your new x coordinate: \n");
        		         scanf("%d", &temp_x);
        		         temp_x--;
        		         printf("Your new y coordinate: \n");
        		         scanf("%d", &temp_y);
        		         temp_y--;
        	         }
  		            
                 break;
  	           case 3:
  		            while((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x == 4 && temp_y == 3) || (temp_x<1 || temp_x>5) || (temp_y<1 || temp_y>5)){
  			              printf("You aren't allowed to change this box or the coordonate are wrong ! \nPlease enter coordonate beetween 1 and 5. \n\n");
  			              printf("Your new x coordinate: \n");
        		          scanf("%d", &temp_x);
        		          temp_x--;
        		          printf("Your new y coordinate: \n");
        		          scanf("%d", &temp_y);
        		          temp_y--;
        	        }
  		            break;
  	           case 4:
  		            while((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x == 4 && temp_y == 3) || (temp_x == 1 && temp_y == 4) || (temp_x<1 || temp_x>5) || (temp_y<1 || temp_y>5)){
  			              printf("You aren't allowed to change this box or the coordonate are wrong ! \nPlease enter coordonate beetween 1 and 5. \n\n");
  			              printf("Your new x coordinate: \n");
        		          scanf("%d", &temp_x);
        		          temp_x--;
        		          printf("Your new y coordinate: \n");
        		          scanf("%d", &temp_y);
        		          temp_y--;
        	         }
  		            break;
  	           default:
  		            break;
  	               }
        
        T_Element temp =  plateau[temp_y -1][temp_x -1];
        plateau[temp_y -1][temp_x -1] = plateau[player->y][player->x];
        plateau[player->y][player->x] = temp;
        print_Plateau(nb_ppl, plateau, name_elements);
        name(player);
        //Attention, nous ne pouvons pas transposé un objet sur une case 
        //en face d'une case de sortie de joueur
        player->dead = 1; //Le joueur n'est pas vraiement mort mais c'est pour mettre fin au tour
        break;

      default:
        break;
    }
    
    if ((plateau[player->x][player->y] == CHEST) && (player->chest == 0)) {
      player->chest += 1;
    }

    if (((player->role == WARRIOR) && (plateau[player->x][player->y] == WARRIOR_WEAPON)) || ((player->role == RANGER) && (plateau[player->x][player->y] == RANGER_WEAPON)) || ((player->role == MAGE) && (plateau[player->x][player->y] == MAGE_WEAPON)) || ((player->role == THIEF) && (plateau[player->x][player->y] == THIEF))) {
      player->spe_obj += 1;
    }

    if(player->spe_obj == 1 && player->chest == 1){
      player_win = 1;
      sleep(2);
      ClearScreen();
      printf("\n %s win ! Congratulation ! \n\n You have done %d kills and move on a box %d times !", player->name,player->kill,player->nb_cases);
      printf("Here is the tray completely visible : \n\n");
      print_Plateau(nb_ppl, plateau, name_elements);
      return 1;
    }
    
    if (player->dead == 1){
    	player->spe_obj = 0;
    	player->chest = 0;
      return 0;
    }

  } // fin do / while
}
