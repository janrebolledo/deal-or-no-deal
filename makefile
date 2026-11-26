all: main

main: main.c game.c game.h banker.c banker.h
	gcc main.c game.c banker.c -o main

