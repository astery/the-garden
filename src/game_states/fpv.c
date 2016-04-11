/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "fpv.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void FPVGS_HandleInput(Game *game, SDL_Event *e) {
	Orientation o = -1;
	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			o = PO_S;
			break;
		case SDL_SCANCODE_LEFT:
			o = PO_W;
			break;
		case SDL_SCANCODE_RIGHT:
			o = PO_E;
			break;
		case SDL_SCANCODE_UP:
			o = PO_N;
			break;
		}
	}
}

#pragma GCC diagnostic pop

void FPVGS_Render(Game *game, SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, img_front_1_side_0.texture, NULL, NULL);
}
