#include <stdio.h>
#include <SDL.h>
#include "macros.h"
#include "funcs.h"

void SDL_RenderDrawGrid(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(GREY_COLOUR);
	for (int x = 0, y = 0; x <= TILES && y <= TILES; x += CELL_SIZE, y += CELL_SIZE) {
		SDL_RenderDrawLine(renderer, x, 0, x, TILES);
		SDL_RenderDrawLine(renderer, 0, y, TILES, y);
	}
}

void move_ant(SDL_Renderer* renderer, SDL_Rect ant, int grid[TILES / CELL_SIZE][TILES / CELL_SIZE]) {
	if (grid[ant.x / CELL_SIZE][ant.y / CELL_SIZE]) {
		SDL_SetRenderDrawColor(WHITE_COLOUR);
		SDL_RenderFillRect(renderer, &ant);
		ant.x++;
	}
	else {
		SDL_SetRenderDrawColor(BLACK_COLOUR);
		SDL_RenderFillRect(renderer, &ant);
		ant.x--;
	}
}

