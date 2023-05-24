#include "header.h"



int welcome(){
  int verif, choice, menu;
  
  printf("\tHELLO GAMERS !!! WELCOME IN THE BEST GAME OF THE WORLD : THE MEMORY RPG !!! \n\n\n\n  \n");

  sleep(2);
  
  printf("1. Start a new game |\n2. Read the rules   |\n3. Quit game        |\n\n");

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
    		default:
    			ClearScreen();
    			printf("ERROR !\n\n");	
    			sleep(1);
    			ClearScreen();
    			printf("\tHELLO GAMERS !!! WELCOME IN THE BEST GAME OF THE WORLD : THE MEMORY RPG !!! \n\n\n\n  \n");
    			printf("1. Start a new game |\n2. Read the rules   |\n3. Quit game        |\n\n");
    			break;
    	}
    }
  
  ClearScreen();
  return menu;
 }
  


int rules(){
	int choice, choice2;
	char verif, temp_choice;
	
	printf("RULES : have fun ^^\n\n");
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
