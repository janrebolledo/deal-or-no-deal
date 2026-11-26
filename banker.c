#include "banker.h"

#define NUM_OF_ROUNDS 9

static const int ROUND_PERCENT[NUM_OF_ROUNDS] = {15, 25, 35, 45, 55, 65, 75, 85, 95};

long long calculateOffer(const GameState *game) {


  long long total = 0;

  int closed = 0;

  //adds everything in closed cases

  for(int i = 0; i < NUM_CASES; i++) {

    if(!game -> opened[i]) {

      total += game -> prizes[i];
      closed++;
    }
  }

  if(closed == 0) //don't wanna divide by 0
    return 0;

  long long average = total / closed;

  //we must keep the round range in 1-9 because ROUND_PERCENT contains only 9

  int round = game -> currentRound;

  if(round < 1)
    round = 1;
  if(round > NUM_OF_ROUNDS)
     round = NUM_OF_ROUNDS;


  long long offer = average * ROUND_PERCENT[round - 1] / 100;

  offer = offer / 100 * 100; //This basically cuts off the cents and make num whole

  return offer;
  
}
