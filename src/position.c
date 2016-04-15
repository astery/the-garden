/*
 * position.c
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#include "position.h"
#include "map.h"

bool Position_IsInMapBoundaries(Position *pos, Map *map) {
	return pos->x <= MAP_SIZE && pos->y <= MAP_SIZE;
}
