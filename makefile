all: main

main: main.c game.c game.h
	gcc main.c game.c -o main

