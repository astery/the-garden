/*
 * game.h
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#ifndef GAME_H_
#define GAME_H_

#include "map.h"

typedef enum {
	OUP, ODOWN, OLEFT, ORIGHT
} Orientation;

typedef struct {
	MapItem *pos;
	Orientation orient;
} Player;

typedef struct {
	Map maps[1];
	Map *current_map;
	Player *player;
} Game;

void Game_Init(Game *game);

#endif /* GAME_H_ */
