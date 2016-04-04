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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void MenuScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e) {
	if (e->type == SDL_KEYDOWN){
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_SPACE:
			printf("space@!");
			break;
		case SDL_SCANCODE_RETURN:
			printf("return#!");
			break;
		}
	}
}

#pragma GCC diagnostic pop

void MenuScene_RenderScene(void *scene, SDL_Renderer *render) {
	MenuScene *menu = scene;
	SDL_RenderCopy(render, menu->background.texture, NULL, NULL);
}
