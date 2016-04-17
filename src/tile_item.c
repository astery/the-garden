/*
 * tile_item.c
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#include "tile_item.h"
#include <SDL2/SDL.h>
#include "colors.h"
#include "position.h"
#include "tile.h"
#include "assets.h"

void TileItem_MoveItem(TileItem *item, Tile *from_tile, Tile *to_tile) {
	Tile_AddItem(to_tile, *item);
	Tile_RemoveItem(from_tile, item);
}

void TileItem_Render(TileItem *item, SDL_Renderer *renderer) {
	SDL_Color *c;
	switch (item->type) {
	case WALL:
		c = &color_dark_green;
		break;
	case PLAYER:
		c = &color_blue;
		break;
	case MONSTER:
		c = &color_magenta;
		break;
	case EXIT:
		c = &color_red;
		break;
	default:
		c = &color_light_green;
	}
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawPoint(renderer, item->tile->pos.x, item->tile->pos.y);
}

void TileItem_RenderFPV(TileItem *item, SDL_Renderer *renderer, int dist) {
	switch (item->type) {
	case WALL:
		break;
	case PLAYER:
		break;
	case MONSTER: ;
		Pawn *m = item->pawn;
		if (m->health <= 0) {
			switch(dist) {
			case 3:
				SDL_RenderCopy(renderer, img_knight_3_down.texture, NULL, NULL);
				break;
			case 2:
				SDL_RenderCopy(renderer, img_knight_2_down.texture, NULL, NULL);
				break;
			case 1:
				SDL_RenderCopy(renderer, img_knight_1_down.texture, NULL, NULL);
				break;
			}
		} else {
			switch(dist) {
			case 4:
				SDL_RenderCopy(renderer, img_knight_4.texture, NULL, NULL);
				break;
			case 3:
				SDL_RenderCopy(renderer, img_knight_3.texture, NULL, NULL);
				break;
			case 2:
				Animation_Render(&anim_knight_2_idle, renderer, 0, 0);
				break;
			case 1:
				Animation_Render(&anim_knight_idle, renderer, 0, 0);
				break;
			}
		}
		break;
	case EXIT:
		switch(dist) {
		case 4:
			SDL_RenderCopy(renderer, img_door_4.texture, NULL, NULL);
			break;
		case 3:
			SDL_RenderCopy(renderer, img_door_3.texture, NULL, NULL);
			break;
		case 2:
			SDL_RenderCopy(renderer, img_door_2.texture, NULL, NULL);
			break;
		case 1:
			SDL_RenderCopy(renderer, img_door_1.texture, NULL, NULL);
			break;
		}
		break;
	default:
		break;
	}
}
