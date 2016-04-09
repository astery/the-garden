/*
 * game_states.h
 *
 *  Created on: Apr 9, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_H_
#define GAME_STATES_H_

#include "game_state.h"
#include "game_states/menu.h"
#include "game_states/tutorial.h"
#include "game_states/map.h"

GameState g_game_states[] = {
		{GS_MENU, MenuGS_HandleInput, MenuGS_Render},
		{GS_TUTOR, TutorialGS_HandleInput, TutorialGS_Render, TutorialGS_OnEnter, TutorialGS_OnLeave},
		{GS_MAP, MapGS_HandleInput, MapGS_Render},
};

#endif /* GAME_STATES_H_ */
