all: exec clean 

main.o: main.c header.h 
	gcc -c main.c -o main.o 

box_elements.o: box_elements.c header.h 
	gcc -c box_elements.c -o box_elements.o 

choice.o: choice.c header.h 
	gcc -c choice.c -o choice.o 

game.o: game.c header.h 
	gcc -c game.c -o game.o 

initialisation.o: initialisation.c header.h 
	gcc -c initialisation.c -o initialisation.o 

menu.o: menu.c header.h 
	gcc -c menu.c -o menu.o 

one_turn.o: one_turn.c header.h 
	gcc -c one_turn.c -o one_turn.o 

plateau.o: plateau.c header.h 
	gcc -c plateau.c -o plateau.o 

score.o: score.c header.h 
	gcc -c score.c -o score.o 

utility.o: utility.c header.h 
	gcc -c utility.c -o utility.o 

exec: main.o box_elements.o choice.o game.o initialisation.o menu.o one_turn.o plateau.o score.o utility.o
	gcc main.o box_elements.o choice.o game.o initialisation.o menu.o one_turn.o plateau.o score.o utility.o -o exec 

clean: 
	rm *.o
