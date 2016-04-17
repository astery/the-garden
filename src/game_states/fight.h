/*
 * fight.h
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_FIGHT_H_
#define GAME_STATES_FIGHT_H_

#include "../game.h"

enum FightGS_Stats {
	ST_HP = 0,
	ST_AT,
	ST_DF,
	ST_GD,
	ST_LV,
	ST_OP
};

void FightGS_HandleInput(Game *game, SDL_Event *e);
void FightGS_Render(Game *game, SDL_Renderer *render);
void FightGS_OnEnter(Game *game, GameState *from_state);
void FightGS_OnLeave(Game *game, GameState *from_state);
void FightGS_RenderHUD(Game *game, SDL_Renderer *renderer);

#endif /* GAME_STATES_FIGHT_H_ */
