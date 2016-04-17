/*
 * tile_item.h
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#ifndef TILE_ITEM_H_
#define TILE_ITEM_H_

#include "map_typedefs.h"
#include <SDL2/SDL.h>

enum TileItemType {
	NONE = 0,
	WALL,
	EXIT,
	MONSTER,
	PLAYER,
	MAP_ITEMS_SIZE
};

struct TileItem {
	TileItemType type;
	Tile *tile;
	void *data;
};


void TileItem_MoveItem(TileItem *item, Tile *from_tile, Tile *to_tile);
void TileItem_Render(TileItem *item, SDL_Renderer *render);
void TileItem_RenderFPV(TileItem *item, SDL_Renderer *render, int dist);


#endif /* TILE_ITEM_H_ */
