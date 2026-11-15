#ifndef GAME_H
#define GAME_H

#define NUM_CASES 26

typedef struct {

  long long prizes[NUM_CASES]; //just a bigger int
  int opened[NUM_CASES];
  int playerCase;
  int currentRound;
  long long lastOffer;
} GameState;
//Struct, holds mulple variables together in GameState.


void initializeGame(GameState *game);
int selectPlayerCase(GameState *game, int caseNumber);
int openCase(GameState *game, int caseNumber);
int countRemaining(const GameState *game);

#endif


//ifndef, define, endif stops this file from being included twice
