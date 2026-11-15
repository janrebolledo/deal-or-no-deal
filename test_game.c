#include <stdio.h>
#include "game.h"

int main(void) {
  GameState game;
  initializeGame(&game);

  for (int i = 0; i < NUM_CASES; i++) {
    printf("Case %2d: $%lld.%02lld\n", i + 1, game.prizes[i] / 100,
	   game.prizes[i] % 100);
  }

  printf("Pick case 7:                      %d\n", selectPlayerCase(&game, 7));
  printf("Open case 7 (should fail):        %d\n", openCase(&game, 7));
  printf("Open case 3:                      %d\n", openCase(&game, 3));
  printf("Open case 3 again (fail):         %d\n", openCase(&game, 3));
  printf("Open case 99 (fail):              %d\n", openCase(&game, 99));
  printf("Cases remaining (should be 25):   %d\n", countRemaining(&game));
  return 0;
}
