//Juan Byeon, Eric Dong, Ahmed Elnaggar, Nathan Hong, Jan Rebolledo Jimenez

#include <stdlib.h>
#include <time.h>
#include "game.h"

//26 prizes, $.01 = 1, $1 = 100.
static const long long PRIZE_VALUE[NUM_CASES] = {
  1, 100, 500, 1000, 2500, 5000, 7500, 10000, 20000, 30000,
  40000, 50000, 75000, 100000, 500000, 1000000, 2500000, 5000000,
  7500000, 10000000, 20000000, 30000000, 40000000, 50000000,
  75000000, 100000000
};



//Fisher-Yates shuffle (apparantly the best shuffle method)
static void shufflePrizes(long long prizes[], int n) {
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1); //random from 0 to i
    long long temp = prizes[i];
    prizes[i] = prizes[j];
    prizes[j] = temp;
  }
}

void initializeGame(GameState *game) {
  srand((unsigned) time(NULL)); //This is for randon numgen every time you run

  for (int i = 0; i < NUM_CASES; i++) {
    game -> prizes[i] = PRIZE_VALUE[i];
    //this syntax basically same as (*game).prizes[i] = PRIZE_VALUE[i]
    //using because easier to type
    game -> opened[i] = 0;
  }
  shufflePrizes(game -> prizes, NUM_CASES);

  game -> playerCase = -1;
  game -> currentRound = 1;
  game -> lastOffer = 0;
  
}

//player picks case, return 1 if ok, 0 if invalid.
int selectPlayerCase(GameState *game, int caseNumber) {
  if (caseNumber < 1 || caseNumber > NUM_CASES)
    return 0;
  game -> playerCase = caseNumber - 1; //since array starts at 0
  return 1;
}

//open a case. returns 1 if opened, 0 if invalid/alreadyopened/player's
int openCase(GameState *game, int caseNumber) {
  int index = caseNumber - 1;

  if (caseNumber < 1 || caseNumber > NUM_CASES)
    return 0;
  if (game -> opened[index])
    return 0;
  if (index == game -> playerCase)
    return 0;

  game -> opened[index] = 1;
  return 1;
}

//no. of closed cases
int countRemaining(const GameState *game) { //don't want to change the game
  int count = 0;
  for (int i = 0; i < NUM_CASES; i++) {
    if (!game -> opened[i])
      count++;
  }
  return count;
}



