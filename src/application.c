/*
 * app.c
 *
 *  Created on: 2 ���. 2016 �.
 *      Author: Astery
 */

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_mixer.h>
#include "application.h"
#include "animation.h"


int Application_Init(
		Application *app,
		int screen_width,
		int screen_height
		) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Unable to initialize SDL\n");
		return 1;
	}

	app->window = SDL_CreateWindow("The garden", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if (app->window == NULL){
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	app->screen_height = screen_height;
	app->screen_width = screen_width;

	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (app->renderer == NULL){
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(app->window);
		SDL_Quit();
		return 1;
	}
	SDL_RenderSetLogicalSize(app->renderer, AWIDTH, AHEIGHT);

	int result = 0;
	int flags = MIX_INIT_MP3;

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		printf("Failed to init SDL\n");
	}

	if (flags != (result = Mix_Init(flags))) {
		printf("Could not initialize mixer (result: %d).\n", result);
		printf("Mix_Init: %s\n", Mix_GetError());
	}

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_AllocateChannels(4);

	return 0;
}

void Application_RunLoop(Application *app, Game *game) {
	SDL_Event e;
	bool quit = false;

	while (!quit){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			game->state->input_handler(game, &e);
		}

		SDL_SetRenderDrawColor(app->renderer, 0x80, 0x80, 0x80, 0xFF);
		SDL_RenderClear(app->renderer);
		game->state->renderer(game, app->renderer);
		SDL_RenderPresent(app->renderer);
	}
}

void Application_Destroy(Application *app) {
	SDL_DestroyRenderer(app->renderer);
	app->renderer = NULL;
	SDL_DestroyWindow(app->window);
	app->window = NULL;
	SDL_Quit();
}
