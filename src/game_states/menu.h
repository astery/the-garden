/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_MENU_H_
#define GAME_STATES_MENU_H_

#include "../game_state.h"

void MenuGS_HandleInput(Game *game, SDL_Event *e);
void MenuGS_Render(Game *game, SDL_Renderer *render);

#endif /* GAME_STATES_MENU_H_ */
