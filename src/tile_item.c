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

