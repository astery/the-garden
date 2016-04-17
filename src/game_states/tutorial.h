/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_TUTORIAL_H_
#define GAME_STATES_TUTORIAL_H_

#include "../game_state.h"

enum TGSAction {
	TGSA_UP,
	TGSA_DOWN,
	TGSA_LEFT,
	TGSA_RIGHT,
	TGSA_A,
	TGSA_ANY,
	TGSA_STATS_HP,
	TGSA_STATS_HP_BAR,
	TGSA_STATS_AT,
	TGSA_STATS_AT_BAR,
	TGSA_STATS_DF,
	TGSA_STATS_DF_BAR,
	TGSA_STATS_GD,
	TGSA_STATS_GD_BAR,
	TGSA_D
};

typedef struct {
	enum TGSAction action;
} TutorialGSData;

void TutorialGS_HandleInput(Game *game, SDL_Event *e);
void TutorialGS_Render(Game *game, SDL_Renderer *render);
void TutorialGS_OnEnter(Game *game, GameState *from_state);
void TutorialGS_OnLeave(Game *game, GameState *from_state);

#endif /* GAME_STATES_TUTORIAL_H_ */
