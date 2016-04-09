/*
 * tutorial.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "tutorial.h"
#include "../assets.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void TutorialGS_OnEnter(Game *game, GameState *from_state) {
	TutorialGSData *data = malloc(sizeof *data);
	data->action = TGSA_DOWN;
	game->state->data = (void *) data;
}

void TutorialGS_OnLeave(Game *game, GameState *from_state) {
	free(game->state->data);
}

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
			if (a == TGSA_UP) {
				Game_SetCurrentState(game, GS_MAP);
			}
			break;
		}
	}
}

#pragma GCC diagnostic pop

void TutorialGS_Render(Game *game, SDL_Renderer *render) {
	TutorialGSData *data = (TutorialGSData *) game->state->data;
	switch(data->action) {
	case TGSA_UP:
		SDL_RenderCopy(render, img_tutor_up.texture, NULL, NULL);
		break;
	case TGSA_DOWN:
		SDL_RenderCopy(render, img_tutor_down.texture, NULL, NULL);
		break;
	case TGSA_LEFT:
		SDL_RenderCopy(render, img_tutor_left.texture, NULL, NULL);
		break;
	case TGSA_RIGHT:
		SDL_RenderCopy(render, img_tutor_right.texture, NULL, NULL);
		break;
	}
}
