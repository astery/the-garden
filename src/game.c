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
	game->show_hud = false;
	game->defeat_enemy_on_this_step = false;
	LoadMaps(game->maps);
	Game_SetCurrentMap(game, 0);
	Game_SetCurrentState(game, GS_MENU);
	Game_ResetPlayer(game);
}

void Game_ResetPlayer(Game *game) {
	game->player.health = 3;
	game->player.atk = 1;
	game->player.def = 0;
	game->player.gold = 1;
}

void Game_UpdatePlayerReference(Game *game) {
	int i, j;
	for (i=0; i < MAP_SIZE; i++) {
		for (j=0; j < MAP_SIZE; j++) {
			Tile *tile = &game->current_map->tiles[i][j];
			TileItem *item = Tile_GetTopItem(tile);
			if (item != NULL && item->type == PLAYER) {
				Pawn_Init(&game->player, tile, item);
			}

		}
	}

	if (game->player.tile == NULL) {
		printf("Game: current map has no player");
	}
}

void Game_SetCurrentMap(Game *game, int map_index) {
	game->current_map_index = map_index;
	game->current_map = &game->maps[map_index];
	Game_UpdatePlayerReference(game);
}

void Game_SetCurrentState(Game *game, GameStateName state_name) {
	if (game->state != NULL) {
		game->prev_state = game->state->name;
	}
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

	TileItem *item = Map_GetTopItemAt(game->current_map, p.x, p.y);
	if (item == NULL) {
		return;
	}

	switch (item->type) {
	case WALL:
		break;
	default:
		Pawn_MoveTo(pawn, game->current_map, &p);
		break;
	}
}

bool Game_IfPlayerStepOnMonsterGoFight(Game *game, Orientation orient) {

	Position pos = Pawn_PeekMove(&game->player, orient);
	TileItem *item = Map_GetTopItemAt(game->current_map, pos.x, pos.y);

	if (item->type == MONSTER) {
		game->last_monster = item->pawn;

		Pawn *m = game->last_monster;
		Pawn *p = &game->player;

		if (m->health <= 0) {
			return false;
		}

		Game_PawnHitPawn(game, p, m);
		if (m->health > 0) {
			Game_PawnHitPawn(game, m, p);
		}

		return true;
	}
	return false;
}

void Game_MovePlayer(Game *game, Orientation orient) {
	if (Game_IfPlayerStepOnMonsterGoFight(game, orient)) {
		game->player.orient = orient;
		return;
	}
	Game_MovePawn(game, &game->player, orient);
	game->defeat_enemy_on_this_step = false;
}

void Game_PawnHitPawn(Game *game, Pawn *att, Pawn *rec) {
	int hit = att->atk - rec->def;
	hit = hit < 0 ? 0 : hit;

	int health = rec->health - hit;
	health = health < 0 ? 0 : health;
	rec->health = health;

	if (health <= 0) {
		game->defeat_enemy_on_this_step = true;
		att->gold += rec->gold;
		rec->gold = 0;
	}
}

bool Game_IsMonsterNearPlayer(Game *game) {
	int i = PO_N;
	for (; i < PO_SIZE; i++) {
		Position pos = Position_NextToOrientation(&game->player.tile->pos, i);
		TileItem *item = Map_GetTopItemAtPos(game->current_map, pos);
		if (item->type == MONSTER && item->pawn->health > 0) {
			game->last_monster = item->pawn;
			return true;
		}
	}
	return false;
}

void Game_StepInDoor(Game *game) {
	int next_map_index = game->current_map_index + 1;
	if (next_map_index >= GAME_MAPS_COUNT - 1) {
		Game_SetCurrentState(game, GS_WIN);
	} else {
		Game_SetCurrentState(game, GS_MERCHANT);
	}
}

void Game_MoveToNextMap(Game *game) {
	int next_map_index = game->current_map_index + 1;
	if (next_map_index >= GAME_MAPS_COUNT - 1) {
		Game_SetCurrentState(game, GS_WIN);
	} else {
		Game_SetCurrentMap(game, next_map_index);
		Game_SetCurrentState(game, GS_MAP);
	}
}
