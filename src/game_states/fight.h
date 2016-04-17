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
void FightGS_RenderStats(FightGS_Stats stat, Game *game, SDL_Renderer *renderer);

#endif /* GAME_STATES_FIGHT_H_ */
