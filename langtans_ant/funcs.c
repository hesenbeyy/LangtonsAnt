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

void ant_direction_change(SDL_Rect* ant, int grid[TILES / CELL_SIZE][TILES / CELL_SIZE], Direction *currentDir) {
	if (grid[ant->x / CELL_SIZE][ant->y / CELL_SIZE]) {
		switch (*currentDir) {
		case UP:
			*currentDir = LEFT;
			break;
		case DOWN:
			*currentDir = RIGHT;
			break;
		case LEFT:
			*currentDir = DOWN;
			break;
		case RIGHT:
			*currentDir = UP;
			break;
		}
	}
	else {
		switch (*currentDir) {
		case UP:
			*currentDir = RIGHT;
			break;
		case DOWN:
			*currentDir = LEFT;
			break;
		case LEFT: 
			*currentDir = UP;
			break;
		case RIGHT:
			*currentDir = DOWN;
			break;
		}
	}
	
}

void ant_forward(Direction currentDir, SDL_Rect* ant) {
	switch (currentDir) {
	case UP:
		ant->y -= CELL_SIZE;
		break;

	case DOWN:
		ant->y += CELL_SIZE;
		break;
	case RIGHT:
		ant->x += CELL_SIZE;
		break;
	case LEFT:
		ant->x -= CELL_SIZE;
		break;
	}
}

void move_ant(SDL_Renderer* renderer, SDL_Rect* ant, int grid[TILES / CELL_SIZE][TILES / CELL_SIZE], Direction* currentDir) {
	if (grid[ant->x / CELL_SIZE][ant->y / CELL_SIZE]) {
	
		ant_direction_change(ant, grid, currentDir);
		grid[ant->x / CELL_SIZE][ant->y / CELL_SIZE] = 0;
		SDL_SetRenderDrawColor(WHITE_COLOUR);
		SDL_RenderFillRect(renderer, ant);
		ant_forward(*currentDir, ant);
	}
	else {
		
		ant_direction_change(ant, grid, currentDir);
		grid[ant->x / CELL_SIZE][ant->y / CELL_SIZE] = 1;
		SDL_SetRenderDrawColor(BLACK_COLOUR);
		SDL_RenderFillRect(renderer, ant);
		ant_forward(*currentDir, ant);
		
	}
}

