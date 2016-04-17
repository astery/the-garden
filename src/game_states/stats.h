/*
 * fight.h
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_STATS_H_
#define GAME_STATES_STATS_H_

#include "../game.h"

void StatsGS_HandleInput(Game *game, SDL_Event *e);
void StatsGS_Render(Game *game, SDL_Renderer *render);
void StatsGS_OnEnter(Game *game, GameState *from_state);
void StatsGS_OnLeave(Game *game, GameState *from_state);

#endif /* GAME_STATES_STATS_H_ */
