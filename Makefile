all: main

main: point.o grid.o player.o play.o main.o
	gcc main.o play.o player.o grid.o point.o -o Game -lncurses

point.o: point.c point.h
	gcc -c point.c

grid.o: grid.c grid.h point.h 
	gcc -c grid.c 

player.o: player.c player.h point.h
	gcc -c player.c

play.o: play.c play.h player.h grid.h 
	gcc -c play.c

main.o: main.c play.h
	gcc -c main.c
