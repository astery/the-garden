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
			item->x = i;
			item->y = j;

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
			item->x = i;
			item->y = j;
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

void MapItem_Render(MapItem *item, SDL_Renderer *render) {
	SDL_Color *c;
	switch (item->type) {
	case WALL:
		c = &color_green;
		break;
	case PLAYER:
		c = &color_blue;
		break;
	case MONSTER:
		c = &color_red;
		break;
	case EXIT:
		c = &color_orange;
		break;
	default:
		c = &color_gray;
	}
	SDL_SetRenderDrawColor(render, c->r, c->g, c->b, 0xFF);
	SDL_RenderDrawPoint(render, item->x, item->y);
}
