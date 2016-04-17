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
   if (e->type == SDL_KEYDOWN) {
	   switch(e->key.keysym.scancode) {
	   case SDL_SCANCODE_DOWN:
		   break;
	   case SDL_SCANCODE_LEFT:
		   break;
	   case SDL_SCANCODE_RIGHT:
		   break;
	   case SDL_SCANCODE_UP:
		   break;
	   default:
		   Game_SetCurrentState(game, game->prev_state);
	   }
   }
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

void FightGS_RenderStats(FightGS_Stats stat, Game *game, SDL_Renderer *renderer) {
	int w = AWIDTH - 1;
	int h = AHEIGHT - 1;
	int prop;
	SDL_Color *c;

	switch (stat) {
	case ST_HP:
		c = &color_light_red;
		prop = game->player.health;
		SDL_RenderCopy(renderer, img_stat_hp.texture, NULL, NULL);
		SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(renderer, 1, h, 1+prop, h);
		break;
	}
}

void FightGS_Render(Game *game, SDL_Renderer *renderer) {
	FightGS_RenderStats(ST_HP, game, renderer);
}
