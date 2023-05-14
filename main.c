#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NB_ROLE 5
#define SIZE_PLATEAU 5
#define ROLES 4
#define NB_ELEMENTS (SIZE_PLATEAU*SIZE_PLATEAU)

typedef enum { WARRIOR, RANGER, MAGE, THIEF, NOROLE } T_Role;

typedef enum {
  EMPTY,
  WARRIOR_WEAPON,
  RANGER_WEAPON,
  MAGE_WEAPON,
  THIEF_WEAPON,
  CHEST,
  ZOMBIE,
  TROLL,
  BASILISK, 
  HARPY,
  PORTAL,
  TOTEM,
  USED,
  HIDEN
} T_Element;


T_Element tab_Elements[] = {
  WARRIOR_WEAPON,
  RANGER_WEAPON,
  MAGE_WEAPON,
  THIEF_WEAPON,
  CHEST,
  CHEST,
  ZOMBIE,
  ZOMBIE,
  ZOMBIE,
  ZOMBIE,
  TROLL,
  TROLL,
  TROLL,
  TROLL,
  BASILISK,
  BASILISK,
  BASILISK,
  BASILISK, 
  HARPY,
  HARPY,
  HARPY,  
  HARPY,
  PORTAL,
  TOTEM,
  TOTEM,
  EMPTY
};

char nom_element[14][11] =
{ "\U0001F532",
  "\U00002694",
  "\U0001F9F9",
  "\U0001F4D3",
  "\U0001F52A",
  "\U0001F4E6",
  "\U0001F9DF",
  "\U0001F437",
  "\U0001F40D", 
  "\U0001F985",
  "\U0001F6AA",
  "\U0001F5FF",
  "USED",
  "\U0001F533"};

typedef struct {
  char name[30];
  int num;
  T_Role role;
  int kill;
  int nb_cases;
  int chest;
  int spe_obj;
  int x;
  int y;
} Player;


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

Player init_player(int num_player, T_Role used_roles[NB_ROLE], int coord_x, int coord_y,
                   char yes_roles[NB_ROLE][10]) {
  Player create;
  printf("What is the name of the player n°%d ?\n \n", num_player);
  scanf("%s", create.name);
  create.num = num_player;
  create.role = init_role(used_roles);
  create.kill = 0;
  create.nb_cases = 0;
  create.chest = 0;
  create.spe_obj = 0;
  create.x = coord_x;
  create.y = coord_y;
  printf("You are the %s\n", yes_roles[create.role]);
  return create;
}


void create_plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]) {
  int index;
  for(int i=0; i<SIZE_PLATEAU; i++){
    for(int j=0; j<SIZE_PLATEAU; j++){
      int used = 1;
      while(used){
        index = rand()%25; //<-- Eventuellement une erreur ici
        if( tab_Elements[index] != USED){
          tab_plateau[i][j] = tab_Elements[index];
          tab_Elements[index] = USED;
          used = 0;
        }
      }
   }
 }
}




void print_Plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]){
  printf("\n\n");
  printf("");
  for(int i=0; i<SIZE_PLATEAU; i++){
    for(int j=0; j<(SIZE_PLATEAU); j++){
      printf("%s ", nom_element[tab_plateau[i][j]]); //Le nom_element permet de transformer l'enumeration en chaine de caractere
    } 
    printf("\n");
  }
  printf("\n\n");
}






int main() {
  srand(time(NULL));
  // Creer un menu de lancement (avec option: Voir les stats + Lancer une
  // partie)

  // Creer les personnages (nombre, nom, role, ?couleur?)
  Player player1, player2, player3, player4;
  T_Role unavailable_roles[NB_ROLE];
  int num_ppl;
  char roles[NB_ROLE][10] = {"WARRIOR", "RANGER", "MAGE", "THIEF"};

  

  printf("How many people are going to play (2,3 or 4) ? \n");
  scanf("%d", &num_ppl);

  for(int i=0;i<NB_ROLE;i++){
    unavailable_roles[i] = NOROLE;
  }

  player1 = init_player(1,unavailable_roles, 0, 0,roles);
  unavailable_roles[0] = player1.role;

  player2 = init_player(2,unavailable_roles,0,0,roles);
  unavailable_roles[1] = player2.role;
  
  switch (num_ppl) {
    default :
      break;

    case 3 :
      player3 = init_player(3,unavailable_roles,0,0,roles);
      unavailable_roles[2] = player3.role;

      break;

    case 4 :
      player3 = init_player(3,unavailable_roles,0,0,roles);
      unavailable_roles[2] = player3.role;

      player4 = init_player(4,unavailable_roles,0,0,roles);
      unavailable_roles[3] = player4.role;

      break;
  }
  
  // Creer le plateau
  T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  T_Element display_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  create_plateau(plateau);
  //create_plateau(display_plateau);
  print_Plateau(plateau);
  // Boucler sur les tours de jeux
  // Boucler sur chaque joueur
  //
  // Choisir une arme
  // Parcours le labyrinthe
  // Les conditions de victoires (si le joueur a gagne ou nn)
  
  return 0;
}

//2eme tableau
