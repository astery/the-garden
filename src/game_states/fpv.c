/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "fpv.h"
#include "../orientation.h"
#include "../colors.h"
#include "fight.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void FPVGS_RenderEnvironment(Game *game, SDL_Renderer *renderer);
void FPVGS_RenderItems(Game *game, SDL_Renderer *renderer);

void FPVGS_HandleInput(Game *game, SDL_Event *e) {
	Orientation player_o = game->player.orient;
	Orientation move_o = -1;
	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			move_o = Orientation_RotateLeft(Orientation_RotateLeft(player_o));
			break;
		case SDL_SCANCODE_LEFT:
			player_o = Orientation_RotateLeft(player_o);
			break;
		case SDL_SCANCODE_RIGHT:
			player_o = Orientation_RotateRight(player_o);
			break;
		case SDL_SCANCODE_UP:
			move_o = player_o;
			break;
		}
		switch(e->key.keysym.sym) {
		case SDLK_d:
			Game_SetCurrentState(game, GS_MAP);
			return;
		case SDLK_a:
			Game_SetCurrentState(game, GS_STATS);
			return;
		}
	}

	game->player.orient = player_o;

	if (move_o != -1) {
		Position pos = Pawn_PeekMove(&game->player, move_o);
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
			Game_MovePlayer(game, move_o);
		}
	}
}

#pragma GCC diagnostic pop

void FPVGS_Render(Game *game, SDL_Renderer *renderer) {
	FPVGS_RenderEnvironment(game, renderer);
	FPVGS_RenderItems(game, renderer);


	if (Game_IsMonsterNearPlayer(game) || game->defeat_enemy_on_this_step) {
		FightGS_RenderHUD(game, renderer);
	}
}

void FPVGS_RenderItems(Game *game, SDL_Renderer *renderer) {
	Pawn *p = &game->player;
	TileItem *item;

	int dist = Map_GetFrontWallDistance(game->current_map, &p->tile->pos, p->orient);

	int i;
	for (i=4; i >= 1; i--) {
		Position pos = Position_RelativeTo(&p->tile->pos, 0, i, p->orient);
		if (dist < i) {
			continue;
		}

		item = Map_GetTopItemAtPos(game->current_map, pos);
		TileItem_RenderFPV(item, renderer, i);
	}
}

void FPVGS_RenderSideWall(Game *game, Position side_pos, int dist, Orientation orient, SDL_Renderer *renderer, SDL_RendererFlip flip) {
	int i = dist;

	for (; i>=0; i--) {
		switch(i) {
		case 3:
			if (Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 2, orient))) {
				if (dist != 3 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 3, orient)))
					SDL_RenderCopyEx(renderer, img_side_3_opened.texture, NULL, NULL, 0, NULL, flip);
				else
					SDL_RenderCopyEx(renderer, img_side_3.texture, NULL, NULL, 0, NULL, flip);
			} else {
				if (dist == 3)
					SDL_RenderCopyEx(renderer, img_side_3_opened.texture, NULL, NULL, 0, NULL, flip);
				else
					SDL_RenderCopyEx(renderer, img_side_3.texture, NULL, NULL, 0, NULL, flip);
			}
			break;
		case 2:
			if (Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 1, orient))) {
				if (dist != 2 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 2, orient)))
					SDL_RenderCopyEx(renderer, img_side_2_opened.texture, NULL, NULL, 0, NULL, flip);
				else
					SDL_RenderCopyEx(renderer, img_side_2.texture, NULL, NULL, 0, NULL, flip);
			} else {
				if (dist == 2)
					SDL_RenderCopyEx(renderer, img_side_2_opened.texture, NULL, NULL, 0, NULL, flip);
				else
					SDL_RenderCopyEx(renderer, img_side_2.texture, NULL, NULL, 0, NULL, flip);
			}
			break;
		case 1:
			if (Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 0, orient))) {
				if (dist != 1 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 1, orient))) {
					SDL_RenderCopyEx(renderer, img_side_0_opened.texture, NULL, NULL, 0, NULL, flip);
				} else if (dist == 1 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&side_pos, 0, 1, orient))) {
					SDL_RenderCopyEx(renderer, img_side_0_pixel.texture, NULL, NULL, 0, NULL, flip);
				} else {
					SDL_RenderCopyEx(renderer, img_side_0.texture, NULL, NULL, 0, NULL, flip);
				}
			} else {
				if (dist == 1 ){
					SDL_RenderCopyEx(renderer, img_side_1_opened.texture, NULL, NULL, 0, NULL, flip);
				}
				else {
					SDL_RenderCopyEx(renderer, img_side_1.texture, NULL, NULL, 0, NULL, flip);
				}
			}
			break;
		}
	}
}

void FPVGS_RenderFrontWall(Game *game, SDL_Renderer *renderer, int dist) {
	switch(dist) {
	case 1:
		SDL_RenderCopyEx(renderer, img_front_1.texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
		break;
	case 2:
		SDL_RenderCopyEx(renderer, img_front_2.texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
		break;
	case 3:
		SDL_RenderCopyEx(renderer, img_front_3.texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
		break;
	}
}

void FPVGS_RenderSun(Game *game, SDL_Renderer *renderer) {
	Orientation o = game->player.orient;

	if (o == PO_N) {
		SDL_Color *c;
		c = &color_yellow;
		SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
		SDL_RenderDrawLine(renderer, 2, 0, 3, 0);
	}
}

void FPVGS_RenderEnvironment(Game *game, SDL_Renderer *renderer) {
	Position *player_pos = &game->player.tile->pos;

	int dist = Map_GetFrontWallDistance(game->current_map, player_pos, game->player.orient);

	SDL_RenderCopyEx(renderer, img_fpv_bground.texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

	FPVGS_RenderSun(game, renderer);
	FPVGS_RenderFrontWall(game, renderer, dist);
	FPVGS_RenderSideWall(game, Position_RelativeTo(player_pos, -1, 0, game->player.orient), dist, game->player.orient, renderer, SDL_FLIP_NONE);
	FPVGS_RenderSideWall(game, Position_RelativeTo(player_pos, 1, 0, game->player.orient), dist, game->player.orient, renderer, SDL_FLIP_HORIZONTAL);
}
