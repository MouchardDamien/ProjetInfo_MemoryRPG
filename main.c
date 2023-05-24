#include "header.h"

int main() {
  
  int play = 1;
  
  do{
  
  ClearScreen();
  
  srand(time(NULL));
  // Creer un menu de lancement (avec option: Voir les stats + Lancer une
  // partie)
  // Creer les personnages (nombre, nom, role, ?couleur?)
  T_Element tab_Elements[] = {
    WARRIOR_WEAPON, RANGER_WEAPON, MAGE_WEAPON, THIEF_WEAPON, CHEST,
    CHEST,          ZOMBIE,        ZOMBIE,      ZOMBIE,       ZOMBIE,
    TROLL,          TROLL,         TROLL,       TROLL,        BASILISK,
    BASILISK,       BASILISK,      BASILISK,    HARPY,        HARPY,
    HARPY,          HARPY,         PORTAL,      TOTEM,        TOTEM,
    EMPTY,          HIDEN};

  char name_Elements[14][11] = {
    " \U000025A1", "\U0001F5E1 ", "\U0001F9F9", "\U0001F4D3", "\U0001F52A",
    "\U0001F381", "\U0001F9DF",  "\U0001F437", "\U0001F40D", "\U0001F985",
    "\U0001F300", "\U0001F5FF",  "USED", "\U0001F533"};
  
  Player player1, player2, player3, player4;
  T_Role unavailable_roles[NB_ROLE];
  int num_ppl, menu_choice;
  char roles[NB_ROLE][10] = {"WARRIOR", "RANGER", "MAGE", "THIEF"};
    
  menu_choice = welcome();
  
  switch(menu_choice){
  	
  	case 1:
  		num_ppl = init_nb_ppl();
  		for (int i = 0; i < NB_ROLE; i++) {
    			unavailable_roles[i] = NOROLE;
  		}

  		init_player(&player1, 1, unavailable_roles, -1, 1, roles);
  		unavailable_roles[0] = player1.role;
  
  		init_player(&player2, 2, unavailable_roles, 3, -1, roles);
  		unavailable_roles[1] = player2.role;

      sleep(3);
  		switch (num_ppl) {
  		default:
    			break;

  		case 3:
    			init_player(&player3, 3, unavailable_roles, 5, 3, roles);
    			unavailable_roles[2] = player3.role;

    			break;

  		case 4:
    			init_player(&player3, 3, unavailable_roles, 5, 3, roles);
    			unavailable_roles[2] = player3.role;

    			init_player(&player4, 4, unavailable_roles, 1, 5, roles);
    			unavailable_roles[3] = player4.role;

    			break;
  		}

  		// Creer le plateau
  		T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  		T_Element display_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  	
  		create_plateau(plateau, tab_Elements);
  		print_Plateau(num_ppl, plateau, name_Elements);
  
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
      break;
  		
	case 2:
  		play = rules();
  		break;

  	case 3:
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
