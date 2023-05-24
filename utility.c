#include "header.h"



void vide_buffer(){
	while(getchar()!='\n'){
	}
}



void ClearScreen(){ 
  printf("\033[H\033[J");
}
