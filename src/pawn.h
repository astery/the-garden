/*
 * pawn.h
 *
 *  Created on: Apr 14, 2016
 *      Author: astery
 */

#ifndef PAWN_H_
#define PAWN_H_

#include "map_typedefs.h"
#include "position.h"
#include "orientation.h"

typedef enum {
	PT_PLAYER = 0,
	PT_MONSTER,
	PT_SIZE
} PawnType;

typedef struct {
	PawnType type;
	Tile *tile;
	Orientation orient;
	int health;
	int atk;
	int def;
} Pawn;

void Pawn_Init(Pawn *pawn, Tile *tile, TileItem *item);
void Pawn_MoveTo(Pawn *pawn, Map *map, Position *pos);
void Pawn_MoveToTile(Pawn *pawn, Tile *tile);
Position Pawn_PeekMove(Pawn *pawn, Orientation orient);

#endif /* PAWN_H_ */
