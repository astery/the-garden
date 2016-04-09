/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "menu.h"
#include <stdio.h>
#include "../assets.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void MenuGS_HandleInput(Game *game, SDL_Event *e) {
	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_SPACE:
		case SDL_SCANCODE_RETURN:
			Game_SetCurrentState(game, GS_TUTOR);
			break;
		}
	}
}

#pragma GCC diagnostic pop

void MenuGS_Render(Game *game, SDL_Renderer *render) {
	SDL_RenderCopy(render, img_menu.texture, NULL, NULL);
}
