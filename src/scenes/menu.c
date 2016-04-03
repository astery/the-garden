/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "menu.h"
#include <SDL2/SDL.h>
#include "../assets.h"

int MenuScene_Init(MenuScene *scene, SDL_Renderer *render) {
	Scene_Init((Scene *) scene, MenuScene_HandleInput, MenuScene_RenderScene);
	int ret = Image_Init(&scene->background, IMG_MENU, render);

	return ret;
}

void MenuScene_HandleInput(void *scene, SDL_Event e) {

}

void MenuScene_RenderScene(void *scene, SDL_Renderer *render) {
	MenuScene *menu = scene;
	SDL_RenderCopy(render, menu->background.texture, NULL, NULL);
}
