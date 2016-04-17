/*
 * map.h
 *
 *  Created on: Apr 5, 2016
 *      Author: astery
 */

#ifndef MAP_H_
#define MAP_H_

#include "SDL2/SDL.h"
#include <stdbool.h>
#include "map_typedefs.h"
#include "tile_item.h"
#include "tile.h"
#include "pawn.h"

#define MAP_SIZE 7

struct Map {
	Tile tiles[MAP_SIZE][MAP_SIZE];
	TileItem border;
};

struct MapSlice {
	TileItemType tiles[MAP_SIZE][MAP_SIZE];
};

void Map_Init(Map *map);
void Map_AppendFromItemTypeArray(Map *map, MapSlice slice);
void Map_Render(Map *map, SDL_Renderer *render);
TileItem* Map_GetTopItemAt(Map *map, int x, int y);
TileItem* Map_GetTopItemAtPos(Map *map, Position pos);
bool Map_IsWallAtPos(Map *map, Position pos);
int Map_GetFrontWallDistance(Map *map, Position *pos, Orientation orient);

#endif /* MAP_H_ */
