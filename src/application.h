/*
 * app.h
 *
 *  Created on: 2 ���. 2016 �.
 *      Author: Astery
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SDL2/SDL.h>
#include "game_controller.h"

typedef struct {
	SDL_Window *window;
	SDL_Renderer *render;
	int screen_width;
	int screen_height;
} Application;

int Application_Init(Application *app, int screen_width, int screen_height);
void Application_RunLoop(Application *app, GameController *controller);
void Application_Destroy(Application *app);

#endif /* APPLICATION_H_ */
