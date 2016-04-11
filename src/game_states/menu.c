/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "menu.h"
#include "../application.h"
#include <stdio.h>
#include "../assets.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void MenuGS_HandleInput(Game *game, SDL_Event *e) {
	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.sym) {
		case SDLK_SPACE:
		case SDLK_RETURN:
			Game_SetCurrentState(game, GS_TUTOR);
			break;
		}

		if (DEBUG) {
			switch(e->key.keysym.sym) {
			case SDLK_m:
				Game_SetCurrentState(game, GS_MAP);
				break;
			case SDLK_f:
				Game_SetCurrentState(game, GS_FIGHT);
				break;
			}
		}
	}
}

#pragma GCC diagnostic pop

void MenuGS_Render(Game *game, SDL_Renderer *render) {
	SDL_RenderCopy(render, img_menu.texture, NULL, NULL);
}
