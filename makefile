all: main

main: main.c game.c game.h banker.c banker.h display.c display.h
	gcc main.c game.c banker.c display.c -o main

