/*
 * fight.h
 *
 *  Created on: Apr 11, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_WIN_H_
#define GAME_STATES_WIN_H_

#include "../game.h"

void WinGS_HandleInput(Game *game, SDL_Event *e);
void WinGS_Render(Game *game, SDL_Renderer *render);
void WinGS_OnEnter(Game *game, GameState *from_state);
void WinGS_OnLeave(Game *game, GameState *from_state);

#endif /* GAME_STATES_WIN_H_ */
