
/**
 * @brief Constants used in the game
 *
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

#define CELL_SIZE 16
#define X_CELLS 28
#define Y_CELLS 36

#define CELL_CENTER ((CELL_SIZE / 2) + 1)

#define SCREEN_WIDTH (X_CELLS * CELL_SIZE)
#define SCREEN_HEIGHT (Y_CELLS * CELL_SIZE)

#define FPS 60

const SDL_Rect SRC_BG = {228, 0, 224, 248};
const SDL_Rect BG = {0, 3 * CELL_SIZE, X_CELLS *CELL_SIZE, (Y_CELLS - 5) * CELL_SIZE};

const SDL_Rect SRC_GUM = {8, 8, 8, 8};
const SDL_Rect SRC_PACGUM = {8, 24, 8, 8};

#define STARTING 0
#define PLAYING 1
#define WIN 2
#define LOSE 3

#define GAMEOVER 0
#define CONTINUE 1

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define STOP 4

#define CHASE 0
#define SCATTER 1
#define FRIGHTENED 2
#define EYES 3

#define GUM 0
#define PACGUM 1
#define FRUIT 2
#define UNDEFINED 3

#endif
