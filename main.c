// Juan Byeon, Eric Dong, Ahmed Elnaggar, Nathan Hong, Jan Rebolledo Jimenez
// CS2600 Systems Programming Final Project
//Doodoo prototype for game


#include <stdio.h>
#include "game.h"

int main() {
  GameState game;

  initializeGame(&game);

  printf("\npropotype deal or no deal \n\n");

  int choice;

  printf("Pick case (1 - 26): ");
  scanf("%d", &choice);

  while (!selectPlayerCase(&game, choice)) {
    printf("Invalid case. Valid numbers are 1-26.");
    scanf("%d", &choice);
  }

  printf("You chose case #%d. It will stay closed.\n", choice);

  for (int i = 0; i < 3; i++) {
    printf("Open a case: ");
    scanf("%d", &choice);
    while (!openCase(&game, choice)) {
      printf("Error opening that one. try again: ");
      scanf("%d", &choice);
    }

    //dollar and cents
    printf("Case #%d had $%lld.%02lld\n", choice,
	   game.prizes[choice - 1] / 100, game.prizes[choice - 1] % 100);
    

    printf("Cases remaining: %d\n\n", countRemaining(&game));
    
  }

  printf("thats it for now lol\n");
  
  return 0;
}
