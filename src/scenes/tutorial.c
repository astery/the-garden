/*
 * tutorial.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "tutorial.h"
#include <SDL2/SDL.h>
#include "../assets.h"
#include "map.h"

void TutorialScene_Init(TutorialScene *scene) {
	Scene_Init((Scene *) scene, TutorialScene_HandleInput, TutorialScene_RenderScene, TutorialScene_Destructor);
	scene->action = DOWN;
}

void TutorialScene_Destructor(void *scene) {
	free((TutorialScene *) scene);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch"

void TutorialScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e) {
	TutorialScene *tutor = (TutorialScene *) scene;
	enum Action a = tutor->action;

	if (e->type == SDL_KEYDOWN) {
		switch(e->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			if (a == DOWN) { tutor->action = LEFT; }
			break;
		case SDL_SCANCODE_LEFT:
			if (a == LEFT) { tutor->action = RIGHT; }
			break;
		case SDL_SCANCODE_RIGHT:
			if (a == RIGHT) { tutor->action = UP; }
			break;
		case SDL_SCANCODE_UP:
			if (a == UP) {
				MapScene *map_scene = (MapScene *) malloc(sizeof *map_scene);
				MapScene_Init(map_scene);
				SceneManager_SetCurrentScene(manager, (Scene *) map_scene);
			}
			break;
		}
	}
}

#pragma GCC diagnostic pop

void TutorialScene_RenderScene(void *scene, SDL_Renderer *render) {
	switch(((TutorialScene *) scene)->action) {
	case UP:
		SDL_RenderCopy(render, img_tutor_up.texture, NULL, NULL);
		break;
	case DOWN:
		SDL_RenderCopy(render, img_tutor_down.texture, NULL, NULL);
		break;
	case LEFT:
		SDL_RenderCopy(render, img_tutor_left.texture, NULL, NULL);
		break;
	case RIGHT:
		SDL_RenderCopy(render, img_tutor_right.texture, NULL, NULL);
		break;
	}
}
