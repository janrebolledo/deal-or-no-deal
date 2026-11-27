// Juan Byeon, Eric Dong, Ahmed Elnaggar, Nathan Hong, Jan Rebolledo Jimenez
// CS2600 Systems Programming Final Project
//Doodoo prototype for game


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banker.h"
#include "game.h"
#include "display.h"

#define NUM_OF_ROUNDS 9
#define IN_STAT -1 //player wants to view "stats"
#define IN_INVALID -2 //invalid input

static const int CASES_PER_ROUND[NUM_OF_ROUNDS] = {6, 5, 4, 3, 2, 1, 1, 1, 1};


//reads player input, return input of stat (IN_STAT) if type "stat", or check invalid

static int readInput() {
  char line[100];
  int number;

  if(fgets(line, sizeof(line), stdin) == NULL) {
    printf("\nBYE\n");
    exit(0);
  }


  if(strncmp(line, "stat", 4) == 0)
    return IN_STAT;
  if(sscanf(line, "%d", &number) == 1)
    return number;

  return IN_INVALID;
  
}

int main() {
  
  GameState game;
  int choice;
  initializeGame(&game);

  printf("\nDEAL OR NO DEAL\n\n");
  printf("TYPE \"stat\" for STATS\n\n");
  while(1) {
    printf("pick case (1 - 26) : ");
    choice = readInput();

    if(choice == IN_STAT)
      printStats(&game);
    else if(selectPlayerCase(&game, choice)) //valid choice so leave loop
      break;
    else
      printf("Invalid. pick another. Number between 1 and 26.\n");
  }

  printf("You chose case #%d. It will stay closed till the end.\n", choice);


  for(int round = 1; round <= NUM_OF_ROUNDS; round++) {
    game.currentRound = round;

    int howManyOpen = CASES_PER_ROUND[round - 1];


    printf("\nROUND %d: open %d case(s)\n", round, howManyOpen);

    while(howManyOpen > 0) {
      printf("open a case (%d left this round.): ", howManyOpen);
      choice = readInput();

      if(choice == IN_STAT)
	printStats(&game);

      else if(openCase(&game, choice)) {
	printf("Case #%d had ", choice);
	printMoney(game.prizes[choice - 1]);
	printf("\n");
	howManyOpen--;
      }
      else
	printf("can't open that one. pick a closed case that's not yours.\n");
    }

    game.lastOffer = calculateOffer(&game);
    printf("The banker offers: ");
    printMoney(game.lastOffer);
    printf("\n");
    

    //asking deal or no deal

    while(1) {
      printf("Deal(1) or NO deal(2)? ");
      choice = readInput();

      if(choice == IN_STAT)
        printStats(&game);

      
      else if(choice == 1) {
	printf("\nDEAL!!1! you won: "); 
	printMoney(game.lastOffer);
	printf("\nYour case had:; ");
	printMoney(game.prizes[game.playerCase]);
	printf("\n");
	return 0; //game over, exit.
	
      }

      else if(choice == 2) {
	printf("NO deal. Moving on.\n");
	break; //going back to game
      }
      else {
	printf("type 1 for deal or 2 for NO deal.\n");
      }
      
    }

  }

  //keep or swap

  int otherCase = -1;
  for(int i = 0; i < NUM_CASES; i++) {
    if(!game.opened[i] && i != game.playerCase)
      otherCase = i;
  }

  printf("\nTHERE'S ONLY TWO CASES LEFT. yours(#%d) and #%d\n",
	 game.playerCase + 1, otherCase + 1);


  while(1) {
    printf("Keep(1) or Swap(2) cases? ");
    choice = readInput();


    if(choice == IN_STAT)
      printStats(&game);
    
    else if(choice == 1) {
      printf("You kept your case.");
      break;
    }

    else if(choice == 2) {
      int temp = game.playerCase;
      game.playerCase = otherCase;
      otherCase = temp;
      printf("You swapped cases. You now have case #%d.\n", game.playerCase + 1);
      break;
    }
    else {
      printf("type 1 for keep or 2 for swap.\n");
    }
  }

  printf("You won: ");
  printMoney(game.prizes[game.playerCase]);
  printf(".\nThe other case had: ");
  printMoney(game.prizes[otherCase]);
  printf(".\n");
  
  return 0;
}
