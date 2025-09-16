#include <stdio.h>
#include <SDL.h>
#include "macros.h"
#include "funcs.h"

int main() {
	printf("Welcome to Langton's Ant!\n");

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Langton's Ant", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TILES, TILES, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(WHITE_COLOUR);
	SDL_RenderClear(renderer);
	//SDL_RenderDrawGrid(renderer);
	//SDL_RenderPresent(renderer);
	int grid[TILES / CELL_SIZE][TILES / CELL_SIZE] = { 0 };
	SDL_Rect ant = { TILES / 2,TILES / 2,CELL_SIZE,CELL_SIZE };
	int running = 1;
	SDL_Event event;
	Direction currentDir = UP;
	SDL_Rect* ant_ptr = &ant;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)	running = 0;
		}
		int waiting = 1;
		if (ant.x == 0) {
			SDL_Delay(5000);
			running = 0;
		}
		move_ant(renderer, ant_ptr, grid, &currentDir);
		SDL_RenderDrawGrid(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_RenderDrawGrid(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(1000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	return 0;
}