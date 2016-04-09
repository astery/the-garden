/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "map.h"

void MapGS_HandleInput(Game *game, SDL_Event *e) {
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

	if (o != -1) {
		Game_MovePlayer(game, o);
	}
}

void MapGS_Render(Game *game, SDL_Renderer *render) {
	Map_Render(game->current_map, render);
}
