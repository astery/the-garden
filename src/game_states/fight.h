/*
 * fight.h
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_FIGHT_H_
#define GAME_STATES_FIGHT_H_

#include "../game.h"

void FightGS_HandleInput(Game *game, SDL_Event *e);
void FightGS_Render(Game *game, SDL_Renderer *render);

#endif /* GAME_STATES_FIGHT_H_ */
