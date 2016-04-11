/*
 * game.c
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#include "game.h"
#include <stdio.h>
#include "assets.h"
#include "game_states.h"
#include "animation.h"

void Game_Init(Game *game) {
	Game_Reset(game);
}

void Game_Reset(Game *game) {
	game->state = NULL;
	LoadMaps(game->maps);
	Game_SetCurrentMap(game, 0);
	Game_SetCurrentState(game, GS_MENU);
	Game_ResetPlayer(game);
}

void Game_ResetPlayer(Game *game) {
	game->player.health = 3;
	game->player.atk = 2;
	game->player.def = 1;
}

void Game_UpdatePlayerReference(Game *game) {
	MapItem *item;
	int i;
	for (i=0; i < game->current_map->items_count; i++) {
		item = &game->current_map->items[i];
		if (item->type == PLAYER) {
			game->player.pos = &item->pos;
		}
	}

	if (game->player.pos == NULL) {
		printf("Game: current map has no player");
	}

	game->player.type = PT_PLAYER;
	game->player.orient = PO_N;
}

void Game_SetCurrentMap(Game *game, int map_index) {
	game->current_map_index = map_index;
	game->current_map = &game->maps[map_index];
	Game_UpdatePlayerReference(game);
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
	Animation_ResetClock();
}

void Game_MovePawn(Game *game, Pawn *pawn, Orientation orient) {
	Position p = Pawn_PeekMove(pawn, orient);

	if (!Position_IsInMapBoundaries(&p, game->current_map)) {
		return;
	}

	MapItem *item = Map_GetFirstItemAtPos(game->current_map, p.x, p.y);
	if (item == NULL) {
		return;
	}

	switch (item->type) {
	case WALL:
		break;
	default:
		*pawn->pos = p;
		break;
	}
}

void Game_MovePlayer(Game *game, Orientation orient) {
	Game_MovePawn(game, &game->player, orient);
}

Position Pawn_PeekMove(Pawn *pawn, Orientation orient) {
	Position p = *pawn->pos;
	switch (orient) {
		case PO_N:
			p.y--;
			break;
		case PO_S:
			p.y++;
			break;
		case PO_W:
			p.x--;
			break;
		case PO_E:
			p.x++;
			break;
		case PO_SIZE:
			break;
	}
	return p;
}
