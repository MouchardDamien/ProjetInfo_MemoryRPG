//Importation des biblioteques 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//Definition des constantes du programme
#define NB_ROLE 5
#define SIZE_PLATEAU 5
#define ROLES 4
#define NB_ELEMENTS (SIZE_PLATEAU*SIZE_PLATEAU)

//Enumeration des roles
typedef enum { WARRIOR, RANGER, MAGE, THIEF, NOROLE } T_Role;

//Enumeration de l'etat que peut prendre une case
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

//Enumeration des armes
typedef enum{TORCH, MIRROR, AXE, BOW} T_Weapon;


//Structure d'un joueur
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

//Fonctions du fichier menu.c :
int welcome();
int rules();
int same_players();

//Fonctions du fichier initialisation.c :
int init_nb_ppl();
void player_name(char name[30],int num_of_player);
void players_names2(char p1[30], char p2[30]);
void players_names3(char p1[30], char p2[30], char p3[30]);
void players_names4(char p1[30], char p2[30], char p3[30], char p4[30]);
void init_player(Player * create, int num_player, T_Role used_roles[NB_ROLE], int coord_x, int coord_y, char yes_roles[NB_ROLE][10], char p_name[30]);
T_Role init_role(T_Role used_roles[NB_ROLE]);


//Fonctions du fichier plateau.c :
void create_plateau(T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements1[]);
void create_hiden_plateau(T_Element tab[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_Elements2[]);
void print_Plateau(int nb_p, T_Element tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11]);
void name(Player * A);


//Fonctions du fichier choice.c :
T_Weapon choose_weapon(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11]);
int stucked(Player * player, int used[SIZE_PLATEAU][SIZE_PLATEAU]);
char choose_direction(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11], int used[SIZE_PLATEAU][SIZE_PLATEAU]);



//Fonction du fichier box_elements.c :
void interaction_box(int nb_ppl, Player * player,T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element one_turn_plateau[SIZE_PLATEAU][SIZE_PLATEAU], char name_elements[14][11], T_Weapon weapon, int used[SIZE_PLATEAU][SIZE_PLATEAU]);

//Fonction du fichier one_turn.c
int player_turn(int nb_ppl, Player * player, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], T_Element tab_elements[], char name_elements[14][11], char name_roles[NB_ROLE][10]);

//Fonctions du fichier utility.c :
void vide_buffer();
void ClearScreen();
time_t chrono();

//Fonctions du fichier game.c :
void game2(Player * playerA, Player * playerB, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role1[NB_ROLE][10]);
void game3(Player * playerA, Player * playerB, Player * playerC, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role2[NB_ROLE][10]);
void game4(Player * playerA, Player * playerB, Player * playerC, Player * playerD, T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU], int nb_player, T_Element tab_elements[], char name_elements[14][11], char name_role3[NB_ROLE][10]);
