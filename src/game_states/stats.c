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

void StatsGS_OnEnter(Game *game, GameState *from_state) {

}

void StatsGS_OnLeave(Game *game, GameState *from_state) {

}

void StatsGS_HandleInput(Game *game, SDL_Event *e) {
   if (e->type == SDL_KEYDOWN) {
//		if (e->key.keysym.sym == SDLK_a)
			Game_SetCurrentState(game, GS_FPV);
   }
}

void StatsGS_RenderStats(Game *game, SDL_Renderer *renderer) {
	int h = AHEIGHT - 1;
	int prop;
	SDL_Color *c;

	prop = game->player.health;
	c = &color_light_red;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, 0, h, 0, h-(h-prop));

	prop = game->player.def;
	c = &color_green;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, 2, h, 2, h-(h-prop));

	prop = game->player.atk;
	c = &color_light_gray;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, 4, h, 4, h-(h-prop));

	prop = game->player.gold;
	c = &color_gold;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawLine(renderer, 6, h, 6, h-(h-prop));
}


#pragma GCC diagnostic pop

void StatsGS_Render(Game *game, SDL_Renderer *renderer) {
	StatsGS_RenderStats(game, renderer);
}
