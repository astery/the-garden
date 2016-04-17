/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "map.h"
#include "fight.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void MapGS_HandleInput(Game *game, SDL_Event *e) {
	Orientation o = -1;
	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			o = PO_S;
			break;
		case SDL_SCANCODE_LEFT:
			o = PO_W;
			break;
		case SDL_SCANCODE_RIGHT:
			o = PO_E;
			break;
		case SDL_SCANCODE_UP:
			o = PO_N;
			break;
		}
		switch(e->key.keysym.sym) {
		case SDLK_f:
			Game_SetCurrentState(game, GS_FPV);
			return;
		}
	}

	if (o != -1) {
		Position pos = Pawn_PeekMove(&game->player, o);
		TileItem *item = Map_GetTopItemAt(game->current_map, pos.x, pos.y);
		switch (item->type) {
		case EXIT: ;
			int next_map_index = game->current_map_index + 1;
			if (next_map_index >= GAME_MAPS_COUNT - 1) {
				Game_Reset(game);
			} else {
				Game_SetCurrentMap(game, next_map_index);
			}
			break;
		default:
			Game_MovePlayer(game, o);
			game->player.orient = o;
		}
	}
}

#pragma GCC diagnostic pop

void MapGS_Render(Game *game, SDL_Renderer *renderer) {
	Map_Render(game->current_map, renderer);

	if (Game_IsMonsterNearPlayer(game) || game->defeat_enemy_on_this_step) {
		FightGS_RenderHUD(game, renderer);
	}
}
