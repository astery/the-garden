/*
 * position.h
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <stdbool.h>
#include "map_typedefs.h"

typedef struct Position Position;

struct Position {
	int x;
	int y;
};

bool Position_IsInMapBoundaries(Position *pos, Map *map);

#endif /* POSITION_H_ */
