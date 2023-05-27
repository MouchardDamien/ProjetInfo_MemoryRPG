#include "header.h"


//Fonction vide buffer
//Utiliser pour securiser et verifier les scanf
void vide_buffer(){
	while(getchar()!='\n'){
	}
}


//Fonction ClearScreen
//Utiliser pour l'affichage graphique --> supprime la page pour laisser les nouvelles instructions au propre
void ClearScreen(){ 
  printf("\033[H\033[J");
}


//Fonction chrono
//Permet de recuperer le temps selon le moment ou la fonction est lance
time_t chrono(){
  time_t ta;
  time (&ta);
  return ta;
}
