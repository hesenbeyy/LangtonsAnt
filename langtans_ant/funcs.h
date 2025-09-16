#ifndef FUNCS_H
#define FUNCS_H

#include <SDL.h>
#include "macros.h"

void SDL_RenderDrawGrid(SDL_Renderer* renderer);
void move_ant(SDL_Renderer* renderer, SDL_Rect ant, int grid[TILES / CELL_SIZE][TILES / CELL_SIZE]);


#endif 
