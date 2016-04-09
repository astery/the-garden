/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_MAP_H_
#define GAME_STATES_MAP_H_

#include "../game.h"

void MapGS_HandleInput(Game *game, SDL_Event *e);
void MapGS_Render(Game *game, SDL_Renderer *render);

#endif /* GAME_STATES_MAP_H_ */
