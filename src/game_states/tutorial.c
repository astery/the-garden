/*
 * tutorial.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "tutorial.h"
#include <stdlib.h>
#include "../assets.h"
#include "../game.h"
#include "../colors.h"

void TutorialGS_OnEnter(Game *game, GameState *from_state) {
	TutorialGSData *data = malloc(sizeof *data);
	data->action = TGSA_DOWN;
	game->state->data = (void *) data;
}

void TutorialGS_OnLeave(Game *game, GameState *from_state) {
	free(game->state->data);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void TutorialGS_HandleInput(Game *game, SDL_Event *e) {
	TutorialGSData *data = (TutorialGSData *) game->state->data;
	enum TGSAction a = data->action;

	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			if (a == TGSA_DOWN) { data->action = TGSA_LEFT; }
			break;
		case SDL_SCANCODE_LEFT:
			if (a == TGSA_LEFT) { data->action = TGSA_RIGHT; }
			break;
		case SDL_SCANCODE_RIGHT:
			if (a == TGSA_RIGHT) { data->action = TGSA_UP; }
			break;
		case SDL_SCANCODE_UP:
			if (a == TGSA_UP) { data->action = TGSA_A; }
			break;
		case SDL_SCANCODE_A:
			if (a == TGSA_A) { data->action = TGSA_STATS_HP; }
			break;
		case SDL_SCANCODE_D:
			if (a == TGSA_D) {
				Game_SetCurrentState(game, GS_MAP);
			}
			break;
		default:
			if (data->action == TGSA_STATS_HP) {
				data->action = TGSA_STATS_HP_BAR;
				break;
			}
			if (data->action == TGSA_STATS_HP_BAR) {
				data->action = TGSA_STATS_AT;
				break;
			}
			if (data->action == TGSA_STATS_AT) {
				data->action = TGSA_STATS_AT_BAR;
				break;
			}
			if (data->action == TGSA_STATS_AT_BAR) {
				data->action = TGSA_STATS_DF;
				break;
			}
			if (data->action == TGSA_STATS_DF) {
				data->action = TGSA_STATS_DF_BAR;
				break;
			}
			if (data->action == TGSA_STATS_DF_BAR) {
				data->action = TGSA_STATS_GD;
				break;
			}
			if (data->action == TGSA_STATS_GD) {
				data->action = TGSA_STATS_GD_BAR;
				break;
			}
			if (data->action == TGSA_STATS_GD_BAR) {
				data->action = TGSA_D;
				break;
			}
		}
	}
}

#pragma GCC diagnostic pop

void TutorialGS_Render(Game *game, SDL_Renderer *render) {
	TutorialGSData *data = (TutorialGSData *) game->state->data;
	SDL_Color *c;

	switch(data->action) {
	case TGSA_UP:
		Animation_Render(&anim_arrow_up, render, 0, 0);
		break;
	case TGSA_DOWN:
		Animation_Render(&anim_arrow_down, render, 0, 0);
		break;
	case TGSA_LEFT:
		Animation_Render(&anim_arrow_left, render, 0, 0);
		break;
	case TGSA_RIGHT:
		Animation_Render(&anim_arrow_right, render, 0, 0);
		break;
	case TGSA_A:
		SDL_RenderCopy(render, img_tutor_a.texture, NULL, NULL);
		break;
	case TGSA_STATS_HP:
		SDL_RenderCopy(render, img_stat_hp.texture, NULL, NULL);
		break;
	case TGSA_STATS_AT:
		SDL_RenderCopy(render, img_stat_at.texture, NULL, NULL);
		break;
	case TGSA_STATS_DF:
		SDL_RenderCopy(render, img_stat_df.texture, NULL, NULL);
		break;
	case TGSA_STATS_GD:
		SDL_RenderCopy(render, img_stat_gd.texture, NULL, NULL);
		break;
	case TGSA_STATS_HP_BAR:
		c = &color_light_red;
		SDL_SetRenderDrawColor(render, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(render, 0, 7, 0, 3);
		break;
	case TGSA_STATS_AT_BAR:
		c = &color_light_gray;
		SDL_SetRenderDrawColor(render, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(render, 2, 7, 2, 3);
		break;
	case TGSA_STATS_DF_BAR:
		c = &color_green;
		SDL_SetRenderDrawColor(render, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(render, 4, 7, 4, 3);
		break;
	case TGSA_STATS_GD_BAR:
		c = &color_gold;
		SDL_SetRenderDrawColor(render, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(render, 6, 7, 6, 3);
		break;
	case TGSA_D:
		SDL_RenderCopy(render, img_tutor_d.texture, NULL, NULL);
		break;
	}
}
