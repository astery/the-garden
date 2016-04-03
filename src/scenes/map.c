/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "map.h"
#include <SDL2/SDL.h>
#include "../assets.h"

int MapScene_Init(MapScene *scene, SDL_Renderer *render) {
	Scene_Init((Scene *) scene, MapScene_HandleInput, MapScene_RenderScene);
	int ret = Image_Init(&scene->background, IMG_MAP, render);

	return ret;
}

void MapScene_HandleInput(void *scene, SDL_Event e) {

}

void MapScene_RenderScene(void *scene, SDL_Renderer *render) {
	MapScene *menu = scene;
	SDL_RenderCopy(render, menu->background.texture, NULL, NULL);
}
