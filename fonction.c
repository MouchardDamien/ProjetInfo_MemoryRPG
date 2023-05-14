#include "header.h"

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
  EMPTY,
  HIDEN
};

char nom_element[14][11] =
{ "\U0001F532",
  " \U00002694",
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


void create_hiden_plateau(T_Element tab[SIZE_PLATEAU][SIZE_PLATEAU]){
  for(int i=0;i<SIZE_PLATEAU;i++){
    for(int j=0;j<SIZE_PLATEAU;j++){
      tab[i][j] = tab_Elements[26];
    }
  }
}



void print_Plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]){
  printf("\n\n");
  printf("");
  printf("           \U0001F7E9 \n");
  for(int i=0; i<SIZE_PLATEAU; i++){
    for(int j=0; j<(SIZE_PLATEAU); j++){
      if(j==0){ 
        if(i==1){
        printf("\U0001F7E6");
        }
        else{
          printf("  ");
        }
      }
      printf("%s ", nom_element[tab_plateau[i][j]]); //Le nom_element permet de transformer l'enumeration en chaine de caractere
      if(j==4 && i == 3){
        printf("\U0001F7E5");
      }
    } 
    printf("\n");
  }
  printf("     \U0001F7E8 \n");
  printf("\n\n");
}

void playerturn(){
  T_Weapon weapon;
  for(int i=0; i<3; i++){
    printf("Choose a weapon:\n1) Torch\n2) Shield\n3) Axe\n 4) Bow");
    scanf("%d", weapon);
  }
}
