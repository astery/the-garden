/*
 * tile.c
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#include "tile.h"
#include <stdlib.h>
#include <stdio.h>
#include "tile_item.h"
#include "tile.h"

TileItem* Tile_GetTopItem(Tile *tile) {
	if (tile->items_count <= 0 || tile->items_count > MAX_ITEMS_ON_TILE) {
		return &tile->default_item;
	}

	return &tile->items[tile->items_count -1];
}

void Tile_RemoveItem(Tile *tile, TileItem *item) {
	if (&tile->items[tile->items_count - 1] != item) {
		printf("TODO: Tile_RemoveItem able to remove items only from top");
		return;
	}
	tile->items_count--;
}

TileItem* Tile_AddItem(Tile *tile, TileItem item) {
	if (tile->items_count >= MAX_ITEMS_ON_TILE) {
		printf("Tile_RemoveItem can have only %d items", MAX_ITEMS_ON_TILE);
		return NULL;
	}

	TileItem *new_item = &tile->items[tile->items_count];
	*new_item = item;
	new_item->tile = tile;
	tile->items_count++;
	return new_item;
}

void Tile_Render(Tile *tile, SDL_Renderer *renderer) {
	TileItem *item = Tile_GetTopItem(tile);
	TileItem_Render(item, renderer);
}

