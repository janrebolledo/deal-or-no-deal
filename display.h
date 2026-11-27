#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h"



//prints money in readable format
void printMoney(long long cents);


//prints stats
void printStats(const GameState *game);

//prints board with prizes with small to big
void printBoard(const GameState *game);


#endif
