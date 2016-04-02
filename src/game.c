/*
 * game.c
 *
 *  Created on: 2 апр. 2016 г.
 *      Author: Astery
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"


int Game_Init(Game *game, int screen_width, int screen_height) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Unable to initialize SDL");
		return 1;
	}

	game->window = SDL_CreateWindow("The garden", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if (game->window == NULL){
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	game->screen_height = screen_height;
	game->screen_width = screen_width;

	game->render = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (game->render == NULL){
		printf("SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_DestroyWindow(game->window);
		SDL_Quit();
		return 1;
	}

	return 0;
}

void Game_Destroy(Game *game) {
	SDL_DestroyRenderer(game->render);
	game->render = NULL;
	SDL_DestroyWindow(game->window);
	game->window = NULL;
	SDL_Quit();
}
