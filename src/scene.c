/*
 * game_scene.c
 *
 *  Created on: 3 апр. 2016 г.
 *      Author: Astery
 */

#include "scene.h"

#include "assets.h"

int Scene_Init(Scene *scene, SDL_Renderer *render) {
	scene->background = &scene->backgrounds[0];
	int ret = Image_Init(scene->background, IMG_MENU, render);

	return ret;
}

void Scene_HandleInput(Scene *scene, SDL_Event e) {

}

void Scene_RenderScene(Scene *scene, SDL_Renderer *render) {
	SDL_RenderCopy(render, scene->background->texture, NULL, NULL);
}
