/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "map.h"

void MapGS_HandleInput(Game *game, SDL_Event *e) {

}

void MapGS_Render(Game *game, SDL_Renderer *render) {
	Map_Render(game->current_map, render);
}
