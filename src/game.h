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

typedef enum {
	OUP, ODOWN, OLEFT, ORIGHT
} Orientation;

typedef struct {
	MapItem *pos;
	Orientation orient;
} Player;

struct Game {
	GameState *state;
	Map maps[1];
	Map *current_map;
	Player player;
};

void Game_Init(Game *game);
void Game_SetCurrentState(Game *game, GameStateName state_name);

#endif /* GAME_H_ */
