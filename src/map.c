/*
 * map.c
 *
 *  Created on: Apr 6, 2016
 *      Author: astery
 */

#include "map.h"
#include <stdlib.h>
#include "colors.h"
#include "position.h"

void Map_Init(Map *map) {
	int i, j;
	Tile *tile;

	for (i=0; i < MAP_SIZE; i++) {
		for (j=0; j < MAP_SIZE; j++) {
			tile = &map->tiles[i][j];
			// TODO: Tile_Init
			tile->pos.x = i;
			tile->pos.y = j;
			tile->items_count = 0;
			tile->default_item.tile = tile;
			tile->default_item.type = NONE;
		}
	}
}

void Map_AppendFromItemTypeArray(Map *map, MapSlice slice) {
	int i, j;
	Tile *tile;

	for (i=0; i < MAP_SIZE; i++) {
		for (j=0; j < MAP_SIZE; j++) {
			TileItemType type = slice.tiles[j][i];
			if (type == NONE) {
				continue;
			}
			tile = &map->tiles[i][j];
			TileItem *item = &tile->items[tile->items_count];
			item->type = type;
			item->tile = tile;
			tile->items_count++;
		}
	}
}

void Map_Render(Map *map, SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0xf, 0xf, 0xf, 0xf);
	SDL_RenderClear(renderer);
	int i, j;
	for (i=0; i < MAP_SIZE; i++) {
		for (j=0; j < MAP_SIZE; j++) {
			Tile_Render(&map->tiles[i][j], renderer);
		}
	}
	return;
}

TileItem* Map_GetTopItemAt(Map *map, int x, int y) {
	Tile *tile = &map->tiles[x][y];
	return Tile_GetTopItem(tile);
}

TileItem* Map_GetTopItemAtPos(Map *map, Position pos) {
	return Map_GetTopItemAt(map, pos.x, pos.y);
}

TileItem* Map_IsWallAtPos(Map *map, int x, int y) {
	return NULL;
}

int Map_GetFrontWallDistance(Map *map, Position *pos, Orientation orient) {
	int dist = 0;
	Position p_next = *pos;
	do {
		dist++;
		p_next = Position_NextToOrientation(&p_next, orient);
		// TODO: traverse all
		TileItem *item = Map_GetTopItemAtPos(map, p_next);
		if (item->type == WALL) {
			return dist;
		}
	} while (Position_IsInMapBoundaries(&p_next, map));
	return dist;
}

Position* Map_GetNearestWall(Map *map, int x, int y, Orientation o) {
	return NULL;
}

