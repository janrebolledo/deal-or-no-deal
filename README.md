<div align="center">

<h1>Deal or No Deal</h1>

CS 2600 Final Project

<small>
Juan Byeon, Eric Dong, Ahmed Elnaggar, Nathan Hong, Jan Rebolledo Jimenez
</small>

</div>

## Overview

A Deal or No Deal recreation in the terminal, written in C.

Project Scope:

| Feature         | Completion  |
| --------------- | ----------- |
| 26 Brief Cases  | done        |
| Case Selection  | done        |
| Rounds + opening| done        |
| Banker offers   | done        |
| Deal or No Deal | done        |
| Swapping        | done        |
| Prize board     | done        |
| Game Statistics | done        |


## How to Play

1. Pick your own briefcase (1-26). It will stay closed until the end.
2. Each round, open other cases and eliminated prizes.
3. After each round, the banker makes an offer based on prizes left.
4. Choose **Deal** to take the money and end the game, or **No deal** to keep playing.
5. If you never take a deal, choose to **Keep* or **Swap** your case with the last case.

Type `stat` at any point to see the stats of your game.

## Compiling

Compile the C program in the terminal

```bash
make
```

Run the output

```bash
./main
```


## File Structure

| File                    | Purpose                                                  |
| ----------------------- | -------------------------------------------------------- |
| `main.c`                | Game loop, user input, rounds, deal / keep-or-swap logic |
| `game.c` / `game.h`     | GameState struct, prize shuffling, picking/opening cases |
| `banker.c` / `banker.h` | Banker offer calculation                                 |
| `display.c` / `display.h` | Money printing, stats screen, prize board              |
| `makefile`              | Builds the program with `make`                           |

## Banker formula

The banker offer is average of all prizes still available to pick, including the player's case, multiplied by a percentage increasing every round. We made this calculation up for the banker to make things simplier. 

## References

See [REFERENCES.md](REFERENCES.md) for outside sources used.




