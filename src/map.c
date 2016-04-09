/*
 * map.c
 *
 *  Created on: Apr 6, 2016
 *      Author: astery
 */

#include "map.h"
#include <stdlib.h>
#include <SDL2/SDL_pixels.h>
#include "colors.h"


void Map_Generate(Map *map) {
	srand(1239);
	map->items_count = 0;
	MapItem *item;

	int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			item = &map->items[map->items_count];
			item->type = rand() % MAP_ITEMS_SIZE;
			item->pos.x = i;
			item->pos.y = j;

			map->items_count++;
		}
	}
}

void Map_GenerateFromItemTypeArray(Map *map, MapItemType m[MAP_SIZE][MAP_SIZE]) {
	int i, j;
	MapItem *item;

	map->items_count = 0;

	for (i=0; i < MAP_SIZE; i++) {
		for (j=0; j < MAP_SIZE; j++) {
			item = &map->items[map->items_count];
			item->type=m[i][j];
			item->pos.x = j;
			item->pos.y = i;
			map->items_count++;
		}
	}
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

MapItem* Map_GetItemAtPos(Map *map, int x, int y) {
	MapItem *item;
	int i;
	for (i=0; i < map->items_count; i++) {
		item = &map->items[i];
		if (item->pos.x == x && item->pos.y == y) {
			return item;
		}
	}
	return NULL;
}

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
