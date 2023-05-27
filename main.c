#include "header.h"

int main() {
  
  int play = 1;
  
  do{
  
  ClearScreen();
  
  srand(time(NULL));

    //Tableau de tous les elements a mettre dans le plateau
  T_Element tab_Elements[] = {
    WARRIOR_WEAPON, RANGER_WEAPON, MAGE_WEAPON, THIEF_WEAPON, CHEST,
    CHEST,          ZOMBIE,        ZOMBIE,      ZOMBIE,       ZOMBIE,
    TROLL,          TROLL,         TROLL,       TROLL,        BASILISK,
    BASILISK,       BASILISK,      BASILISK,    HARPY,        HARPY,
    HARPY,          HARPY,         PORTAL,      TOTEM,        TOTEM,
    EMPTY,          HIDEN};

    //Permet de transformer les elements du Tab_Elements en chaine de caractere, et ici avec des emojis unicode
  char name_Elements[14][11] = {
    " \U000025A1", "\U0001F5E1 ", "\U0001F9F9", "\U0001F4D3", "\U0001F52A",
    "\U0001F381", "\U0001F9DF",  "\U0001F437", "\U0001F40D", "\U0001F985",
    "\U0001F300", "\U0001F5FF",  "USED", "\U0001F533"};
  
  Player player1, player2, player3, player4;
  char p1_name[30], p2_name[30], p3_name[30], p4_name[30];
  T_Role unavailable_roles[NB_ROLE];
  int num_ppl, menu_choice, same_play=1;
  char roles[NB_ROLE][10] = {"WARRIOR", "RANGER", "MAGE", "THIEF"}; //Meme role que name_Elements
  time_t chronometer;
  
  menu_choice = welcome(); //Lance le menu du jeu

    
  switch(menu_choice){
  	
  	case 1:
  		num_ppl = init_nb_ppl();
  		for (int i = 0; i < NB_ROLE; i++) {
    			unavailable_roles[i] = NOROLE;
  		}

      switch (num_ppl) {
  			default:
    				printf("ERROR IN main FOR num_ppl !!!\n\n");
            break;

  			case 2:
    				players_names2(p1_name,p2_name);

    				break;

  			case 3:
    				players_names3(p1_name,p2_name,p3_name);

    				break;

        case 4:
    				players_names4(p1_name,p2_name,p3_name,p4_name);

    				break;
  		}


      do{
      
  		  init_player(&player1, 1, unavailable_roles, -1, 1, roles, p1_name);
  		  unavailable_roles[0] = player1.role;
  
  		  init_player(&player2, 2, unavailable_roles, 3, -1, roles, p2_name);
  		  unavailable_roles[1] = player2.role;

  		  switch (num_ppl) {
  			   default:
    				  break;

  			   case 3:
    				  init_player(&player3, 3, unavailable_roles, 5, 3, roles, p3_name);
    				  unavailable_roles[2] = player3.role;

    				  break;

  			   case 4:
    				  init_player(&player3, 3, unavailable_roles, 5, 3, roles, p3_name);
    				  unavailable_roles[2] = player3.role;

    				  init_player(&player4, 4, unavailable_roles, 1, 5, roles, p4_name);
    				  unavailable_roles[3] = player4.role;

    				  break;
  		    }

          for(int i = 0; i<NB_ROLE; i++){ 
            unavailable_roles[i] = NOROLE;
          }
      
          	    T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  		    T_Element display_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  	
  		    create_plateau(plateau, tab_Elements);
  
  		    chronometer = chrono();
  		    switch(num_ppl){
  			     case 2:
  			       game2(&player1,&player2,plateau,num_ppl,tab_Elements,name_Elements,roles);
  			       break;
  			     case 3:
  				      game3(&player1,&player2,&player3,plateau,num_ppl,tab_Elements,name_Elements,roles);
  				      break;
  			     case 4:
  				      game4(&player1,&player2,&player3,&player4,plateau,num_ppl,tab_Elements,name_Elements,roles);
  				      break;
  			     default:
  				      break;
  		      }
          chronometer = chrono() - chronometer;
          printf("Your game lasted %ld secondes !\n\n", chronometer);
          printf("15 SECONDES BEFORE THE ENDGAME SCREEN DISAPPEARS !\n\n");
 	        sleep(15);
          same_play = same_players();
          
      }while(same_play == 1);
      break; 
  		
	case 2:
  		play = rules();
  		break;

  case 3:
      ClearScreen();
      printf("SCORE : empty \n");
      sleep(2);
      break;
    
  case 4:
  		printf("Thanks you for having playing ! GOODBYE !\n");
  		sleep(3);
  		ClearScreen();
  		play = 0;
  		
  		break;
  
 	default:
 		break;
  }
  }while(play == 1);
	
	return 0;
}
