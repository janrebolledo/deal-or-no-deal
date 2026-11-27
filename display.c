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



void printBoard(const GameState *game) {

  long long values[NUM_CASES]; //prize amt
  
  int gone[NUM_CASES]; //holds 1 if prize eliminated

  //copy values in the arrays
  for(int i = 0; i < NUM_CASES; i++) {
    values[i] = game -> prizes[i];
    gone[i] = game -> opened[i];
  }

  //BUBBLE SORT FOR SORTING LOWEST TO HIGHST simultaneously

  for(int i = 0; i < NUM_CASES - 1; i++) {
    for(int j = 0; j < NUM_CASES - 1 - i; j++) {
      if(values[j] > values[j + 1]) {
	long long temp1 = values[j];
	values[j] = values[j + 1];
	values[j + 1] = temp1;

	int temp2 = gone[j];
	gone[j] = gone[j + 1];
	gone[j + 1] = temp2;
	
      }
    }
  }


  int half = NUM_CASES / 2;

  printf("\n+--------- PRIZE BOARD ---------+\n");

  for(int i = 0; i < half; i++) {

    long long left = values[i];
    long long right = values[i + half];

    //mark with x if money taken


    if(gone[i])
      printf("| X $%7lld.%02lld", left / 100, left % 100);
    else
      printf("|   $%7lld.%02lld", left / 100, left % 100);


    if(gone[i + half])
      printf("   X $%7lld.%02lld |\n", right / 100, right % 100);
    else
      printf("     $%7lld.%02lld |\n", right / 100, right % 100);
    
  }

  printf("+-------------------------------+\n");

  

    

  
  

  
}
