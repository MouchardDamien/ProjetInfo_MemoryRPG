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

typedef enum{TORCH, SHIELD, AXE, BOW} T_Weapon;
}

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


T_Role init_role(T_Role used_roles[NB_ROLE]);

Player init_player(int num_player, T_Role used_roles[NB_ROLE], int coord_x, int coord_y, char yes_roles[NB_ROLE][10]);

void create_plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]);

void create_hiden_plateau(T_Element tab[SIZE_PLATEAU][SIZE_PLATEAU]);

void print_Plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]);

void game(Player player, int nb_p);

void playerturn();
