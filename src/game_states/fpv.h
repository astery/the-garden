/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_FPV_H_
#define GAME_STATES_FPV_H_

#include "../game.h"

void FPVGS_HandleInput(Game *game, SDL_Event *e);
void FPVGS_Render(Game *game, SDL_Renderer *render);

#endif /* GAME_STATES_FPV_H_ */
