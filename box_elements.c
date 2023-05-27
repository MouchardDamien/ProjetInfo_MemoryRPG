#include "header.h"

//Fonction interaction_box
//Permet au jeu de reagir en fonction de la case sur laquelle se trouve le joueur
void interaction_box(int nb_ppl, Player * player,T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element one_turn_plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11], T_Weapon weapon, int used[SIZE_PLATEAU][SIZE_PLATEAU]){

  int choice,verif,test_coord = 1,temp_x,temp_y;
  
  switch(one_turn_plateau[player->y][player->x]){

      //Le cas des monstres
      case ZOMBIE:
        if(weapon == TORCH){
          printf("Good job !\nYou kill a Zombie !\n");
          sleep(2);
          ClearScreen();
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
          sleep(2);
          ClearScreen();
          player->kill++;
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
          sleep(2);
          ClearScreen();
          player->kill++;
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
          sleep(2);
          ClearScreen();
          player->kill++;
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
          player->spe_obj=1;
        }
        else{
              printf("You found a secret weapon ! But it's not your...\n");
        }
        break;
          
      case RANGER_WEAPON:
        if(player->role == RANGER){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj=1;
        }
        else{
              printf("You found a secret weapon ! But it's not your...\n");
        }  
        break;

      case MAGE_WEAPON:
        if(player->role == MAGE){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj=1;
        }
        else{
              printf("You found a secret weapon ! But it's not your...\n");
        }

        break;

      case THIEF_WEAPON:
        if(player->role == THIEF){
          printf("Congratulation ! You have your secret weapon !\n");
          player->spe_obj=1;
        }
        else{
              printf("You found a secret weapon ! But it's not your...\n");
        }    
        break;

      //Le cas des autres objets
      case CHEST:
        if(player->chest ==0){
          printf("Congratualtion ! You have a legendary chest !\n");
          player->chest=1;
        }
        else{
          printf("You found a chest ! But you already have one...\n");
        }
        break;

      case TOTEM:
        printf("You find the transmution totem, interesting, choose an hidden square to change your actual box with another one:\n");

          test_coord = 0;
        
        do{
        
          printf("Your x coordinate: \n");

          //Verification du scanf
     	    while(scanf("%d",&temp_x) != 1 || (temp_x != 1 && temp_x != 2 && temp_x != 3 && temp_x != 4 && temp_x != 5)){
     		
     		   printf("\nError for the x ! Choose a number beetween 1 and 5 :\n\n");
     		   vide_buffer();
     	    }
        
          printf("\nYour y coordinate: \n");

          //Verification du scanf
     	    while(scanf("%d",&temp_y) != 1 || (temp_y != 1 && temp_y != 2 && temp_y != 3 && temp_y != 4 && temp_y != 5)){
     			
     		   printf("\nError for the y ! Choose a number beetween 1 and 5 :\n\n");
     		   vide_buffer();
     	    }
        
          if(used[temp_y][temp_x] == 1){
        	    test_coord = 1;
              printf("Error ! You can't change a box already discover !\n\n");
          }
                     
          switch(nb_ppl){
  	          
              case 2:
  		          if((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1)){
  			          printf("You aren't allowed to change this box  !\n\n");
        	        test_coord = 1; 
                }
  		            
                 break;
  	           
              case 3:
  		            if((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x == 4 && temp_y == 3)){
  			            printf("You aren't allowed to change this box  !\n\n");
        	          test_coord = 1; 
        	        }
  		            break;
  	           
              case 4:
  		            if((temp_x == 3 && temp_y == 0) || (temp_x == 0 && temp_y == 1) || (temp_x == 4 && temp_y == 3) || (temp_x == 1 && temp_y == 4)){
  			            printf("You aren't allowed to change this box  !\n\n");
        	          test_coord = 1; 
        	         }
  		            break;
  	           
               default:
  		            printf("ERROR IN nb_ppl OF box_elements FUNCTION !!!\n\n");
                  break;
  	               }

        }while(test_coord != 0);

        vide_buffer();
        
        printf("The transmutation is done !");
        sleep(2);
        
        T_Element temp =  plateau[temp_y][temp_x];
        plateau[temp_y][temp_x] = plateau[player->y][player->x];
        plateau[player->y][player->x] = temp;
        
        print_Plateau(nb_ppl, plateau, name_elements);
        name(player);
        player->dead = 1; //Le joueur n'est pas vraiment mort mais c'est pour mettre fin au tour
        break;
    
      case PORTAL:
        printf("You find the portal !\nChoose a square in the plateau:\n\n");
        
        
        do{
        
        printf("Your x coordinate: \n");

          //Verification du scanf
     	while(scanf("%d",&player->x) != 1 || (player->x != 1 && player->x != 2 && player->x != 3 && player->x != 4 && player->x != 5)){
     		
     		printf("\nError for the x ! Choose a number beetween 1 and 5 :\n\n");
     		vide_buffer();
     	}
        
        printf("\nYour y coordinate: \n");

          //Verification du scanf
     	while(scanf("%d",&player->y) != 1 || (player->y != 1 && player->y != 2 && player->y != 3 && player->y != 4 && player->y != 5)){
     			
     		printf("\nError for the y ! Choose a number beetween 1 and 5 :\n\n");
     		vide_buffer();
     	}
        
        if(used[player->y][player->x] == 0){
        	test_coord = 0;
        }
        else{
        	printf("Error ! You can't on a box already discover !\n\n");
        }
        
        }while(test_coord != 0);

        vide_buffer();
        
        one_turn_plateau[player->y][player->x] = plateau[player->y][player->x];
        print_Plateau(nb_ppl,one_turn_plateau, name_elements);
        name(player);
        
        interaction_box(nb_ppl, player, plateau, one_turn_plateau, name_elements, weapon, used);
        
        break;
      
      default:
        break;
    }
}
