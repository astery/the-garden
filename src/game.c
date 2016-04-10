/*
 * game.c
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#include "game.h"
#include "assets.h"
#include "game_states.h"
#include "animation.h"

void Game_Init(Game *game) {
	game->state = NULL;
	LoadMap1(&game->maps[0]);
	game->current_map = &game->maps[0];

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
	Animation_ResetClock();
}

void Game_MovePawn(Game *game, Pawn *pawn, Orientation orient) {
	Position p = Pawn_PeekMove(pawn, orient);

	if (!Position_IsInMapBoundaries(&p, game->current_map)) {
		return;
	}

	MapItem *item = Map_GetItemAtPos(game->current_map, p.x, p.y);
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
	}
	return p;
}
