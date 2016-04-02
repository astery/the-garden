/*
 * game_controller.h
 *
 *  Created on: 3 апр. 2016 г.
 *      Author: Astery
 */

#ifndef GAME_CONTROLLER_H_
#define GAME_CONTROLLER_H_

#include <SDL2/SDL.h>
#include "image.h"

typedef struct {
	Image backgrounds[1];
	Image *background;
} GameController;

int GameController_Init(GameController *controller, SDL_Renderer *render);
void GameController_HanleInput(GameController *controller, SDL_Event e);
void GameController_RenderScene(GameController *controller, SDL_Renderer *render);

#endif /* GAME_CONTROLLER_H_ */
