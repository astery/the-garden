/*
 * position.c
 *
 *  Created on: Apr 15, 2016
 *      Author: astery
 */

#include "position.h"
#include "map.h"

Position Position_NextToOrientation(Position *pos, Orientation orient) {
	Position p = *pos;
	switch (orient) {
		case PO_N:
			p.y--;
			break;
		case PO_S:
			p.y++;
			break;
		case PO_W:
			p.x--;
			break;
		case PO_E:
			p.x++;
			break;
		case PO_SIZE:
			break;
	}
	return p;
}

Position Position_RelativeTo(Position *pos, int x, int y) {
	Position p = *pos;
	p.x += x;
	p.y += y;
	return p;
}

bool Position_IsInMapBoundaries(Position *pos, Map *map) {
	return pos->x <= MAP_SIZE && pos->y <= MAP_SIZE;
}
