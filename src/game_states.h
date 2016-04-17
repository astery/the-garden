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
#include "game_states/fpv.h"
#include "game_states/fight.h"
#include "game_states/stats.h"
#include "game_states/merchant.h"
#include "game_states/win.h"

GameState g_game_states[] = {
		{GS_MENU, MenuGS_HandleInput, MenuGS_Render},
		{GS_TUTOR, TutorialGS_HandleInput, TutorialGS_Render, TutorialGS_OnEnter, TutorialGS_OnLeave},
		{GS_MAP, MapGS_HandleInput, MapGS_Render},
		{GS_FPV, FPVGS_HandleInput, FPVGS_Render},
		{GS_FIGHT, FightGS_HandleInput, FightGS_Render},
		{GS_STATS, StatsGS_HandleInput, StatsGS_Render},
		{GS_MERCHANT, MerchantGS_HandleInput, MerchantGS_Render, MerchantGS_OnEnter, MerchantGS_OnLeave},
		{GS_WIN, WinGS_HandleInput, WinGS_Render},
};

#endif /* GAME_STATES_H_ */
