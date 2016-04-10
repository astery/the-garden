/*
 * game.h
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#ifndef GAME_H_
#define GAME_H_

#include "game_typedefs.h"
#include "game_state.h"
#include "map.h"
#include "assets.h"

typedef enum Orientation Orientation;
typedef enum PawnType PawnType;
typedef struct Pawn Pawn;

enum Orientation {
	PO_N = 0, PO_S, PO_W, PO_E, PO_SIZE
};

enum PawnType {
	PT_PLAYER = 0,
	PT_MONSTER,
	PT_SIZE
};

struct Pawn {
	PawnType type;
	Position *pos;
	Orientation orient;
};

struct Game {
	GameState *state;
	Map maps[GAME_MAPS_COUNT];
	int current_map_index;
	Map *current_map;
	Pawn player;
};

void Game_Init(Game *game);
void Game_SetCurrentMap(Game *game, int map_index);
void Game_SetCurrentState(Game *game, GameStateName state_name);
void Game_MovePawn(Game *game, Pawn *pawn, Orientation orient);
void Game_MovePlayer(Game *game, Orientation orient);

Position Pawn_PeekMove(Pawn *pawn, Orientation orient);
//void Pawn_RotateLeft(Pawn *pawn);
//void Pawn_RotateRight(Pawn *pawn);
//void Pawn_MoveForward(Pawn *pawn);
//void Pawn_MoveBackward(Pawn *pawn);


#endif /* GAME_H_ */
