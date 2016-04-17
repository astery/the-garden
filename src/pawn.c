/*
 * pawn.c
 *
 *  Created on: Apr 14, 2016
 *      Author: astery
 */

#include "pawn.h"
#include "position.h"
#include "map.h"

void Pawn_Init(Pawn *pawn, Tile *tile, TileItem *tile_item) {
	pawn->tile = tile;
	pawn->orient = PO_N;

	if (tile_item == NULL) {
		tile_item = Tile_GetTopItem(tile);
	}

	tile_item->pawn = pawn;
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
	Position pn = Position_NextToOrientation(&p, orient);
	return pn;
}
