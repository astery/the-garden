/*
 * fight.c
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#include "stats.h"
#include "../application.h"
#include "../colors.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void GMGS_OnEnter(Game *game, GameState *from_state) {

}

void GMGS_OnLeave(Game *game, GameState *from_state) {

}

void GMGS_HandleInput(Game *game, SDL_Event *e) {
   if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
		case SDL_SCANCODE_LEFT:
		case SDL_SCANCODE_RIGHT:
		case SDL_SCANCODE_UP:
			break;
		default:
		   Game_Reset(game);
		   break;
		}
   }
}

void GMGS_RenderGM(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, img_game_over.texture, NULL, NULL);
}

#pragma GCC diagnostic pop

void GMGS_Render(Game *game, SDL_Renderer *renderer) {
	GMGS_RenderGM(renderer);
}
