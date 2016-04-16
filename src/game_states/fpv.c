/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "fpv.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void FPVGS_HandleInput(Game *game, SDL_Event *e) {
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
		case SDLK_r:
			Game_SetCurrentState(game, GS_MAP);
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
		}
	}
}

#pragma GCC diagnostic pop

void FPVGS_RenderSideWall(Game *game, Position pos, int dist, SDL_Renderer *renderer, SDL_RendererFlip flip) {
	int i = dist;

	for (; i>=0; i--) {
		switch(i) {
		case 3:
			if (Map_IsWallAtPos(game->current_map, Position_RelativeTo(&pos, 0, -2))) {
				if (dist != 3 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&pos, 0, -3)))
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
			if (Map_IsWallAtPos(game->current_map, Position_RelativeTo(&pos, 0, -1))) {
				if (dist != 2 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&pos, 0, -2)))
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
			if (Map_IsWallAtPos(game->current_map, Position_RelativeTo(&pos, 0, 0))) {
				if (dist != 1 && Map_IsWallAtPos(game->current_map, Position_RelativeTo(&pos, 0, -1))) {
					SDL_RenderCopyEx(renderer, img_side_0_opened.texture, NULL, NULL, 0, NULL, flip);
				}
				else {
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

void FPVGS_Render(Game *game, SDL_Renderer *renderer) {
	SDL_RenderCopyEx(renderer, img_fpv_bground.texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
	Position *pos = &game->player.tile->pos;

	int dist = Map_GetFrontWallDistance(game->current_map, pos, game->player.orient);

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
	FPVGS_RenderSideWall(game, Position_RelativeTo(pos, -1, 0), dist, renderer, SDL_FLIP_NONE);
	FPVGS_RenderSideWall(game, Position_RelativeTo(pos, 1, 0), dist, renderer, SDL_FLIP_HORIZONTAL);
//	SDL_RenderCopyEx(renderer, img_front_3.texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
//	SDL_RenderCopyEx(renderer, img_side_3_opened.texture, NULL, NULL, 0, NULL, SDL_FLIP_HORIZONTAL);
}
