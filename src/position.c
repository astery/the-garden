/*
 * position.c
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#include "position.h"
#include "orientation.h"
#include "map.h"

Position Position_NextToOrientation(Position *pos, Orientation orient) {
	return Position_RelativeTo(pos, 0, 1, orient);
}

Position Position_RelativeTo(Position *pos, int x, int y, Orientation orient) {
	Position p = *pos;
	switch (orient) {
		case PO_N:
			p.x += x;
			p.y -= y;
			break;
		case PO_S:
			p.x -= x;
			p.y += y;
			break;
		case PO_W:
			p.x -= y;
			p.y -= x;
			break;
		case PO_E:
			p.x += y;
			p.y += x;
			break;
		case PO_SIZE:
			break;
	}
	return p;
}

bool Position_IsInMapBoundaries(Position *pos, Map *map) {
	return pos->x <= MAP_SIZE && pos->y <= MAP_SIZE;
}
