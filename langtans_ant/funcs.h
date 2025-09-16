#ifndef FUNCS_H
#define FUNCS_H

#include <SDL.h>
#include "macros.h"

void SDL_RenderDrawGrid(SDL_Renderer* renderer);
void ant_direction_change(SDL_Rect* ant, int grid[TILES / CELL_SIZE][TILES / CELL_SIZE], Direction* currentDir);
void ant_forward(Direction currentDir, SDL_Rect* ant);
void move_ant(SDL_Renderer* renderer, SDL_Rect* ant, int grid[TILES / CELL_SIZE][TILES / CELL_SIZE], Direction* currentDir);


#endif 
