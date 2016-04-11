/*
 * fight.c
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#include "fight.h"
#include "../application.h"
#include "../colors.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void FightGS_HandleInput(Game *game, SDL_Event *e) {

}

#pragma GCC diagnostic pop

void FightGS_RenderHUD(Game *game, SDL_Renderer *renderer) {
	int w = AWIDTH - 1;
	int h = AHEIGHT - 1;
	int prop;
	SDL_Color *c;

	prop = game->player.def;
	c = &color_light_gray;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, 0, h - prop, 0, h);

	prop = game->player.atk;
	c = &color_white;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, w, h - prop, w, h);

	prop = game->player.health;
	c = &color_red;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, w/2 - prop/2, h, w/2 + prop/2, h);
}

void FightGS_Render(Game *game, SDL_Renderer *renderer) {
	FightGS_RenderHUD(game, renderer);
}
