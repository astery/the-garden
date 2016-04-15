/*
 * map.c
 *
 *  Created on: Apr 6, 2016
 *      Author: astery
 */

#include "map.h"
#include <stdlib.h>
#include "colors.h"

int MapItem_CompareByType(const void* a, const void* b) {
	 MapItem ia = *((MapItem*) a);
	 MapItem ib = *((MapItem*) b);

	 if (ia.type == ib.type) return 0;
	 else if (ia.type < ib.type) return -1;
	 else return 1;
}

void Map_Init(Map *map) {
	map->items_count = 0;
	MapItem *item;

	int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			item = &map->items[map->items_count];
			item->type = NONE;
			item->pos.x = i;
			item->pos.y = j;

			map->items_count++;
		}
	}
}

void Map_SortByType(Map *map) {
	qsort(map->items, map->items_count, sizeof(MapItem), MapItem_CompareByType);
}

void Map_AppendFromItemTypeArray(Map *map, MapSlice slice) {
	int i, j;
	MapItem *item;

	for (i=0; i < MAP_SIZE; i++) {
		for (j=0; j < MAP_SIZE; j++) {
			MapItemType type = slice.slice[i][j];
			if (type == NONE) {
				continue;
			}
			item = &map->items[map->items_count];
			item->type=type;
			item->pos.x = j;
			item->pos.y = i;
			map->items_count++;
		}
	}

	Map_SortByType(map);
}

void Map_Render(Map *map, SDL_Renderer *render) {
	SDL_SetRenderDrawColor(render, 0xf, 0xf, 0xf, 0xf);
	SDL_RenderClear(render);
	int i;
	for (i=0; i < map->items_count; i++) {
		MapItem_Render(&map->items[i], render);
	}
	return;
}

MapItem* Map_GetFirstItemAtPos(Map *map, int x, int y) {
	MapItem *item;
	int i;
	for (i=map->items_count - 1; i >= 0; i--) {
		item = &map->items[i];
		if (item->pos.x == x && item->pos.y == y) {
			return item;
		}
	}
	return NULL;
}

MapItem* Map_IsWallAtPos(Map *mp, int x, int y) {

}

Position* Map_GetNearestWall(Map *map, int x, int y, Orientation o)

void MapItem_Render(MapItem *item, SDL_Renderer *render) {
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
	SDL_SetRenderDrawColor(render, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawPoint(render, item->pos.x, item->pos.y);
}

bool Position_IsInMapBoundaries(Position *pos, Map *map) {
	return pos->x <= MAP_SIZE && pos->y <= MAP_SIZE;
}
