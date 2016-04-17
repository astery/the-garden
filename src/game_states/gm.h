/*
 * fight.h
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_GM_H_
#define GAME_STATES_GM_H_

#include "../game.h"

void GMGS_HandleInput(Game *game, SDL_Event *e);
void GMGS_Render(Game *game, SDL_Renderer *render);
void GMGS_OnEnter(Game *game, GameState *from_state);
void GMGS_OnLeave(Game *game, GameState *from_state);

#endif /* GAME_STATES_GM_H_ */
