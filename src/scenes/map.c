/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "map.h"
#include <SDL2/SDL.h>
#include "../assets.h"

void MapScene_Init(MapScene *scene) {
	Scene_Init((Scene *) scene, MapScene_HandleInput, MapScene_RenderScene, MapScene_Destructor);
}

void MapScene_Destructor(void *scene) {
	free((MapScene *) scene);
}

void MapScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e) {

}

void MapScene_RenderScene(void *scene, SDL_Renderer *render) {
	SDL_RenderCopy(render, img_map.texture, NULL, NULL);
}
