#include "header.h"

//Fonction choose_weapon
//Permet au joueur de choisir une arme entre Torch, Mirror, Axe et Bow
T_Weapon choose_weapon(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11]){

  int choice, verif;
  T_Weapon weapon;
  
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
    			print_Plateau(nb_ppl,plateau,name_elements);
          name(player);
    			printf("ERROR ! \nChoose a weapon :\n 1) Torch \U0001F525\n 2) Mirror \U0001FA9E\n 3) Axe \U0001FA93\n 4) Bow \U0001F3F9\n");	
    			break;
    	}
  }
  return weapon;
}


//Fonction stucked
//Permet de declarer au jeu si un joueur et coince pour finir le tour du joueur
int stucked(Player * player, int used[SIZE_PLATEAU][SIZE_PLATEAU]){
    
    int blocked = 0;
    ClearScreen();
    if(player->x >0 && player->x <4 && player->y >0 && player->y <4){
    	if(used[player->y][player->x+1] == 1 && used[player->y+1][player->x] == 1 && used[player->y-1][player->x] == 1 && used[player->y][player->x-1] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->x == 0 && player->y >0 && player->y <4){
    	if(used[player->y][player->x+1] == 1 && used[player->y+1][player->x] == 1 && used[player->y-1][player->x] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->y == 0 && player->x >0 && player->x <4){
    	if(used[player->y][player->x+1] == 1 && used[player->y+1][player->x] == 1 && used[player->y][player->x-1] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->y == 4 && player->x >0 && player->x <4){
    	if(used[player->y][player->x+1] == 1 && used[player->y-1][player->x] == 1 && used[player->y][player->x-1] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->x == 4 && player->y >0 && player->y <4){
    	if(used[player->y+1][player->x] == 1 && used[player->y-1][player->x] == 1 && used[player->y][player->x-1] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->x == 0 && player->y == 0){
    	if(used[player->y][player->x+1] == 1 && used[player->y+1][player->x] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->x == 0 && player->y == 4){
    	if(used[player->y][player->x+1] == 1 && used[player->y-1][player->x] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->x == 4 && player->y == 0){
    	if(used[player->y][player->x+1] == 1 && used[player->y+1][player->x] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
    
    if(player->x == 4 && player->y == 4){
    	if(used[player->y][player->x-1] == 1 && used[player->y+1][player->x] == 1){
    		ClearScreen();
    		printf("You are surrounded by boxes already discovered, it's lost ! \n\n");
    		blocked = 1;
    		sleep(2);
    	}
    }
  return blocked;
}


//Fonction choose_direction
//Permet au joueur de choisir une direction pour se deplacer dans le plateau
char choose_direction(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11], int used[SIZE_PLATEAU][SIZE_PLATEAU]){

  int choice,test;
  char verif2, direction;
  
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
    			print_Plateau(nb_ppl,plateau,name_elements);
          name(player);
    			printf("ERROR ! \nChoose a direction :\n\n          z) UP\n q) LEFT         d) "
           "RIGHT\n         s) DOWN\n\n");	
    			break;
    	}
      }
    } while (wrong_answer == 1);  
    
    ClearScreen();
    test = stucked(player,used);
    sleep(1);
    if(player->chest != 1 || player->spe_obj != 1){
    	if(test == 1){
    		player->dead = 1;
    	}
    }
    
    player->nb_cases++;
}
