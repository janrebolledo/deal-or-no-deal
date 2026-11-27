#include <stdio.h>
#include "display.h"

void printMoney(long long cents) {
  printf("$%lld.%02lld", cents / 100, cents % 100);
}

void printStats(const GameState *game) {
  long long highest = -1;
  long long lowest = -1;
  long long total = 0;
  int closed = 0;

  //go thru all cases for closed, highest available, lowest available, etc.

  for(int i = 0; i < NUM_CASES; i++) {

    if(!game->opened[i]) {
      long long prize = game ->prizes[i];

      if(highest == -1 || prize > highest)
	highest = prize;
      if(lowest == -1 || prize < lowest)
	lowest = prize;


      total += prize;
      closed++;
    }
  }


  printf("\n=============STATS=============\n");
  printf("Current round:          %d\n", game -> currentRound);

  if(game -> playerCase == -1)
    printf("You didn't choose your case yet.\n");
  else
    printf("Your case:              #%d\n", game -> playerCase + 1);

  printf("Cases opened:           %d\n", NUM_CASES - closed);
  printf("Cases still closed:     %d (including yours)\n", closed);

  printf("Highest prize left:     ");
  printMoney(highest);
  printf("\nLowest prize left:      ");
  printMoney(lowest);
  printf("\nAverage prize left:     ");
  printMoney(total / closed);

  printf("\nLast banker offer:      ");
  if(game -> lastOffer == 0)
    printf("no offer yet");
  else
    printMoney(game -> lastOffer);
  printf("\n===============================\n\n");
  
  
}
