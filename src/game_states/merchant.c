/*
 * tutorial.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "merchant.h"
#include <stdlib.h>
#include "../application.h"
#include "../assets.h"
#include "../game.h"
#include "../colors.h"
#include "stats.h"

void MerchantGS_OnEnter(Game *game, GameState *from_state) {
	MerchantGSData *data = malloc(sizeof *data);
	data->current_stat = MGSS_HP;
	game->state->data = (void *) data;
}

void MerchantGS_OnLeave(Game *game, GameState *from_state) {
	free(game->state->data);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void MerchantGS_HandleInput(Game *game, SDL_Event *e) {
	MerchantGSData *data = (MerchantGSData *) game->state->data;
	enum MGS_Stat *s = &data->current_stat;

	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_LEFT:
			if (*s >= 1) {
				(*s)--;
			}
			break;
		case SDL_SCANCODE_RIGHT:
			if (*s < MGSS_ITEMS_COUNT - 1) {
				(*s)++;
			}
			break;
		case SDL_SCANCODE_UP: ;
			Pawn *p = &game->player;
			if (p->gold > 0) {
				switch (*s) {
				case MGSS_AT:
					p->atk++;
					p->gold--;
					break;
				case MGSS_DF:
					p->def++;
					p->gold--;
					break;
				case MGSS_HP:
					p->health += 2;
					p->gold--;
					break;
				}
			}
			break;
		default:
			Game_MoveToNextMap(game);
			break;
		}
	}
}

void MerchantGS_Render(Game *game, SDL_Renderer *renderer) {
	StatsGS_Render(game, renderer);

	MerchantGSData *data = (MerchantGSData *) game->state->data;
	SDL_Color *c;
	int offset = 0;

	switch(data->current_stat) {
	case MGSS_HP:
		offset = 0;
		break;
	case MGSS_AT:
		offset = 2;
		break;
	case MGSS_DF:
		offset = 4;
		break;
	}

	c = &color_magenta;
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawPoint(renderer, offset, AHEIGHT - 1);
}

#pragma GCC diagnostic pop
