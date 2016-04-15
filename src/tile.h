/*
 * tile.h
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#ifndef TILE_H_
#define TILE_H_

#define MAX_ITEMS_ON_TILE 3

#include "map_typedefs.h"
#include "position.h"
#include "tile_item.h"
#include "tile.h"
#include <SDL2/SDL.h>

struct Tile {
	TileItem default_item;
	TileItem items[MAX_ITEMS_ON_TILE];
	int items_count;
	Position pos;
};

TileItem* Tile_GetTopItem(Tile *tile);
void Tile_RemoveItem(Tile *tile, TileItem *item);
TileItem* Tile_AddItem(Tile *tile, TileItem item);
void Tile_Render(Tile *tile, SDL_Renderer *render);

#endif /* TILE_H_ */
