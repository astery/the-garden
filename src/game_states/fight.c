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

void FightGS_OnEnter(Game *game, GameState *from_state) {

}

void FightGS_OnLeave(Game *game, GameState *from_state) {

}

void FightGS_HandleInput(Game *game, SDL_Event *e) {
   if (e->type == SDL_KEYDOWN) {
	   switch(e->key.keysym.scancode) {
	   default:
		   if (game->player.health < 0) {
			   Game_SetCurrentState(game, GS_MENU);
		   } else {
			   Game_SetCurrentState(game, game->prev_state);
		   }
	   }
   }
}

void FightGS_RenderHUD(Game *game, SDL_Renderer *renderer) {
	int w = AWIDTH - 1;
	int h = AHEIGHT - 1;
	int prop;
	SDL_Color *c;
	c = &color_light_red;

	prop = game->player.health;
	if (prop > 0) {
		SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(renderer, 0, h, 0, h + 1 - prop);
	}

	prop = game->last_monster->health;
	if (prop > 0) {
		SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(renderer, w, h, w, h + 1 - prop);
	}
}

void FightGS_RenderStats(FightGS_Stats stat, Game *game, SDL_Renderer *renderer) {
	int w = AWIDTH - 1;
	int h = AHEIGHT - 1;

	switch (stat) {
	case ST_HP: ;
		SDL_Color *c = &color_light_red;
		int p_health = game->player.health;
		int m_health = game->last_monster->health;
		SDL_RenderCopy(renderer, img_stat_hp.texture, NULL, NULL);
		SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(renderer, 1, h, 1+p_health, h);
		SDL_RenderDrawLine(renderer, 1, 0, 1+m_health, 0);
		break;
	}
}

#pragma GCC diagnostic pop

void FightGS_Render(Game *game, SDL_Renderer *renderer) {
	FightGS_RenderStats(ST_HP, game, renderer);
}
