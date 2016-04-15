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


struct Game {
	GameState *state;
	Map maps[GAME_MAPS_COUNT];
	int current_map_index;
	Map *current_map;
	Pawn player;
};

void Game_Init(Game *game);
void Game_Reset(Game *game);
void Game_SetCurrentMap(Game *game, int map_index);
void Game_SetCurrentState(Game *game, GameStateName state_name);
void Game_MovePawn(Game *game, Pawn *pawn, Orientation orient);
void Game_MovePlayer(Game *game, Orientation orient);
void Game_ResetPlayer(Game *game);


#endif /* GAME_H_ */
