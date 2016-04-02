/*
 * game_controller.c
 *
 *  Created on: 3 апр. 2016 г.
 *      Author: Astery
 */

#include "game_controller.h"
#include "assets.h"

int GameController_Init(GameController *controller, SDL_Renderer *render) {
	controller->background = &controller->backgrounds[0];
	int ret = Image_Init(controller->background, IMG_MENU, render);

	return ret;
}

void GameController_HanleInput(GameController *controller, SDL_Event e) {

}

void GameController_RenderScene(GameController *controller, SDL_Renderer *render) {
	SDL_RenderCopy(render, controller->background->texture, NULL, NULL);
}
