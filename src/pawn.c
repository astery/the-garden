/*
 * pawn.c
 *
 *  Created on: Apr 14, 2016
 *      Author: astery
 */

#include "pawn.h"
#include "position.h"
#include "map.h"

void Pawn_Init(Pawn *pawn, Tile *tile) {
	pawn->tile = tile;
	pawn->orient = PO_N;
}

void Pawn_MoveTo(Pawn *pawn, Map *map, Position *pos) {
	Pawn_MoveToTile(pawn, &map->tiles[pos->x][pos->y]);
}

void Pawn_MoveToTile(Pawn *pawn, Tile *tile) {
	// TODO: it's so fragile
	TileItem *tile_item_to_move = Tile_GetTopItem(pawn->tile);
	TileItem_MoveItem(tile_item_to_move, pawn->tile, tile);
	pawn->tile = tile;
}

Position Pawn_PeekMove(Pawn *pawn, Orientation orient) {
	Position p = pawn->tile->pos;
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
