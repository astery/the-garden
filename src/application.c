/*
 * app.c
 *
 *  Created on: 2 апр. 2016 г.
 *      Author: Astery
 */

#include <stdio.h>
#include <stdbool.h>
#include "application.h"


int Application_Init(Application *app, int screen_width, int screen_height) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Unable to initialize SDL");
		return 1;
	}

	app->window = SDL_CreateWindow("The garden", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if (app->window == NULL){
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	app->screen_height = screen_height;
	app->screen_width = screen_width;

	app->render = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (app->render == NULL){
		printf("SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_DestroyWindow(app->window);
		SDL_Quit();
		return 1;
	}

	return 0;
}

void Application_RunLoop(Application *app, GameController *controller) {
	SDL_Event e;
	bool quit = false;

	while (!quit){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_KEYDOWN){
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN){
				quit = true;
			}
			GameController_HanleInput(controller, e);
		}

		SDL_RenderClear(app->render);
		GameController_RenderScene(controller, app->render);
		SDL_RenderPresent(app->render);
	}
}

void Application_Destroy(Application *app) {
	SDL_DestroyRenderer(app->render);
	app->render = NULL;
	SDL_DestroyWindow(app->window);
	app->window = NULL;
	SDL_Quit();
}
