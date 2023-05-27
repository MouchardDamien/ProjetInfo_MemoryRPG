#include "header.h"



int welcome(){
  int verif, choice, menu;
  
  printf("\tHELLO GAMERS !!! WELCOME IN THE BEST GAME OF THE WORLD : THE MEMORY RPG !!! \n\n\n\n");

  sleep(1);
  
  printf("1. Start a new game    |\n2. Read the rules      |\n3. View previous score |\n4. Quit game           |\n\n");

  choice = 1;
    
  while (choice != 0){
    	verif = scanf("%d", &menu);
    	vide_buffer();
    	switch(menu){
    		
    		case 1:
    			choice = 0;
    			break;
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
    			printf("ERROR !\n\n");	
    			sleep(1);
    			ClearScreen();
    			printf("\tHELLO GAMERS !!! WELCOME IN THE BEST GAME OF THE WORLD : THE MEMORY RPG !!! \n\n\n\n  \n");
    			printf("1. Start a new game    |\n2. Read the rules      |\n3. View previous score |\n4. Quit game           |\n\n");
    			break;
    	}
    }
  
  ClearScreen();
  return menu;
 }
  


int rules(){
	int choice, choice2;
	char verif, temp_choice;
	printf("RULES: \n\nYour goal is to find your secret weapon and also a legendary chest (\U0001F381). \nYour secret weapon is in keeping with your role: \n\nIf you are WARRIOR you have to find a fire sword (\U0001F5E1 ) \nIf you are RANGER, you have to find your pet control staff (\U0001F9F9)\nIf you are MAGE, you have to find your forbidden grimoire (\U0001F4D3)\nIf you are THIEF, you have to find your sleep dagger (\U0001F52A)\n\n\n\nAt each turn, you have to choose a weapon to kill a monster in the plateau:\nIf you want to kill a ZOMBIE (\U0001F9DF) you have to take a Torch (\U0001F525) \nIf you want to kill a TROLL (\U0001F437) you have to take an Axe (\U0001FA93) \nIf you want to kill a BASILISK (\U0001F40D) you have to take a Mirror (\U0001FA9E) \nIf you want to kill a HARPY (\U0001F985) you have to take a Bow (\U0001F3F9)\n\n\nThere are 2 special items in the game:\nThe first one is teleport magic portal (\U0001F300), you can go in each hidden squares you want, you just have to put the coordinate between 1 and 5\n\nThe second one is the transmutation totem (\U0001F5FF), you can choose a square with also the coordinate of your square (between 1 and 5), and the item in the square you choose is changed by the totem, but you can't change item in front of the starting square. Using the totem ends the player's turn.\n\n\n\n");
	printf("Have fun ^^\n\n");
  printf("Press : 'm' to go back in the main menu ;\n        'q' to quit the game ;\n");
  		
	choice = 1;
    
  	while (choice != 0){
    		verif = scanf("%c", &temp_choice);
    		vide_buffer();
    		switch(temp_choice){
    		
    			case 'm':
    				choice = 0;
    				break;
    			
    			case 'q':
    				choice = 0;
    				break;

    			default:
    				printf("ERROR !\n");
    				sleep(1);
    				ClearScreen();
    				printf("RULES :\n\n");
  				  printf("Press : 'm' to go back in the main menu ;\n        'q' to quit the game ;\n");
    				break;
    		}
    	}
	if(temp_choice == 'm'){
		choice2 = 1;
	}
	else if(temp_choice == 'q'){
		choice2 = 0;
		ClearScreen();
		printf("Thanks you for having playing ! GOODBYE !\n");
		sleep(3);
		ClearScreen();
	}
	return choice2;
}



int same_players(){
  int verif, choice, choice_A;

  ClearScreen();
  
  printf("SELECT WHAT YOU WANT TO DO : \n\n\n\n  \n");
  printf("1. Restart a game with the same players |\n2. Go back to the main menu   |\n\n");

  choice = 1;
    
  while (choice != 0){
    	verif = scanf("%d", &choice_A);
    	vide_buffer();
    	switch(choice_A){
    		
    		case 1:
    			choice = 0;
    			break;
    		case 2:
    			choice = 0;
    			break;
    		default:
    			ClearScreen();
    			printf("ERROR !\n\n");	
    			sleep(1);
    			ClearScreen();
    			printf("SELECT WHAT YOU WANT TO DO : \n\n\n\n  \n");
    			printf("1. Restart a game with the same players |\n2. Go back to the main menu   |\n\n");
    			break;
    	}
    }
  
  ClearScreen();
  
  if(choice_A == 1){
    return 1;
  }
  else if(choice_A == 2){
    return 0;
  }
  
  printf("ERROR ON same_players FUNCTION !!!");
  sleep(2);
  return -1; 
}
