/*
 * map.h
 *
 *  Created on: Apr 5, 2016
 *      Author: astery
 */

#ifndef MAP_H_
#define MAP_H_

#include <stdbool.h>
#include "SDL2/SDL.h"

#define MAP_SIZE 7

enum MapItemType {
	NONE = 0,
	WALL,
	PLAYER,
	MONSTER,
	EXIT,
	MAP_ITEMS_SIZE
};

typedef enum MapItemType MapItemType;

typedef struct {
	int x;
	int y;
} Position;

typedef struct {
	Position pos;
	enum MapItemType type;
} MapItem;

typedef struct {
	MapItem items[128];
	int items_count;
} Map;

void Map_Generate(Map *map);
void Map_GenerateFromItemTypeArray(Map *map, MapItemType m[MAP_SIZE][MAP_SIZE]);
void Map_Render(Map *map, SDL_Renderer *render);
MapItem* Map_GetItemAtPos(Map *map, int x, int y);

void MapItem_Render(MapItem *item, SDL_Renderer *render);

bool Position_IsInMapBoundaries(Position *pos, Map *map);

#endif /* MAP_H_ */
