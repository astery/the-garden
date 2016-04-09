/*
 * game.c
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#include "game.h"
#include "assets.h"
#include "game_states.h"

void Game_Init(Game *game) {
	game->state = NULL;
	LoadMap1(&game->maps[0]);
	game->current_map = &game->maps[0];

	MapItem *item;
	int i;
	for (i=0; i < game->current_map->items_count; i++) {
		item = &game->current_map->items[i];
		if (item->type == PLAYER) {
			game->player.pos = item;
		}
	}

	if (game->player.pos == NULL) {
		printf("Game: current map has no player");
	}

	game->player.orient = OUP;
	Game_SetCurrentState(game, GS_MENU);
}

void Game_SetCurrentState(Game *game, GameStateName state_name) {
	GameState *prev_state = game->state;
	game->state = &g_game_states[state_name];
	if (game->state->on_enter != NULL) {
		game->state->on_enter(game, prev_state);
	}
	if (prev_state != NULL && prev_state->on_leave != NULL) {
		prev_state->on_leave(game, prev_state);
	}
}
