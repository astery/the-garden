/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "menu.h"
#include <SDL2/SDL.h>
#include "../assets.h"
#include "map.h"

void MenuScene_Init(MenuScene *scene) {
	Scene_Init((Scene *) scene, MenuScene_HandleInput, MenuScene_RenderScene, MenuScene_Destructor);
}

void MenuScene_Destructor(void *scene) {
	free((MenuScene *) scene);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void MenuScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e) {
	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_SPACE:
			printf("space@!");
			break;
		case SDL_SCANCODE_RETURN:
			;
			MapScene *map_scene = (MapScene *) malloc(sizeof *map_scene);
			MapScene_Init(map_scene);
			SceneManager_SetCurrentScene(manager, (Scene *) map_scene);
			break;
		}
	}
}

#pragma GCC diagnostic pop

void MenuScene_RenderScene(void *scene, SDL_Renderer *render) {
	SDL_RenderCopy(render, img_menu.texture, NULL, NULL);
}
