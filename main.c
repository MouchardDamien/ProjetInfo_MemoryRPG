#include "header.h"

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

  player1 = init_player(1,unavailable_roles, 0, 1,roles);
  unavailable_roles[0] = player1.role;

  player2 = init_player(2,unavailable_roles,3,0,roles);
  unavailable_roles[1] = player2.role;
  
  switch (num_ppl) {
    default :
      break;

    case 3 :
      player3 = init_player(3,unavailable_roles,4,3,roles);
      unavailable_roles[2] = player3.role;

      break;

    case 4 :
      player3 = init_player(3,unavailable_roles,4,3,roles);
      unavailable_roles[2] = player3.role;

      player4 = init_player(4,unavailable_roles,1,4,roles);
      unavailable_roles[3] = player4.role;

      break;
  }
  
  // Creer le plateau
  T_Element plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  T_Element display_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  T_Element hide_plateau[SIZE_PLATEAU][SIZE_PLATEAU];
  create_plateau(plateau);
  //create_plateau(display_plateau);
  print_Plateau(plateau);
  create_hiden_plateau(hide_plateau);
  print_Plateau(hide_plateau);


  // 1) Boucler tous les tours de jeux de la partie
  
  // 2) Boucler sur les tours de jeux
   
  // 3) Boucler sur chaque joueur
  // Choisir une arme
  // Parcours le labyrinthe
  // Les conditions de victoires (si le joueur a gagne ou nn)

 //while(personne a gagné){
   
 //}
  
  return 0;
}

