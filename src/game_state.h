/*
 * game_state.h
 *
 *  Created on: Apr 9, 2016
 *      Author: astery
 */

#ifndef GAME_STATE_H_
#define GAME_STATE_H_

#include "game_typedefs.h"
#include "game.h"

enum GameStateName {
	GS_MENU = 0,
	GS_TUTOR,
	GS_MAP,
	GS_ITEMS_SIZE
};

struct GameState {
	GameStateName name;
	GameStateInputHandler input_handler;
	GameStateRenderer renderer;
	GameStateOnEnter on_enter;
	GameStateOnLeave on_leave;
	void *data;
};

#endif /* GAME_STATE_H_ */
