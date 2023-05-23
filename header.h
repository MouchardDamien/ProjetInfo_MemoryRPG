#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define NB_ROLE 5
#define SIZE_PLATEAU 5
#define ROLES 4
#define NB_ELEMENTS (SIZE_PLATEAU*SIZE_PLATEAU)

//#define U0001F7E9 PLAYER_ONE

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

typedef enum{TORCH, MIRROR, AXE, BOW} T_Weapon;



typedef struct {
  char name[30];
  int num;
  T_Role role;
  int kill;
  int dead;
  int nb_cases;
  int chest;
  int spe_obj;
  int x;
  int y;
} Player;


int welcome();

T_Role init_role(T_Role used_roles[NB_ROLE]);

void init_player(Player * create, int num_player, T_Role used_roles[NB_ROLE], int coord_x, int coord_y, char yes_roles[NB_ROLE][10]);

void create_plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements1[]);

void create_hiden_plateau(T_Element tab[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements2[]);

void print_Plateau(int nb_p, T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11]);

void game(Player player, int nb_p);

int player_turn(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_elements[], char name_elements[14][11], char name_roles[NB_ROLE][10]);

void ClearScreen();

void game2(Player * playerA, Player * playerB, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role1[NB_ROLE][10]);

void game3(Player * playerA, Player * playerB, Player * playerC, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role2[NB_ROLE][10]);

void game4(Player * playerA, Player * playerB, Player * playerC, Player * playerD, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role3[NB_ROLE][10]);
