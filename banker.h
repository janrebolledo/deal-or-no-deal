//Juan Byeon, Eric Dong, Ahmed Elnaggar, Nathan Hong, Jan Rebolledo Jimenez
//banker.h, banker offer calculation
#ifndef BANKER_H
#define BANKER_H

#include "game.h"


//returns banker offer in cents based on closed cases
//doesnt change game
long long calculateOffer(const GameState *game);

#endif

