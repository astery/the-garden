/*
 * game_scene.h
 *
 *  Created on: 3 апр. 2016 г.
 *      Author: Astery
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <SDL2/SDL.h>
#include "image.h"

typedef struct {
	Image backgrounds[1];
	Image *background;
} Scene;

int Scene_Init(Scene *scene, SDL_Renderer *render);
void Scene_HandleInput(Scene *scene, SDL_Event e);
void Scene_RenderScene(Scene *scene, SDL_Renderer *render);

#endif /* SCENE_H_ */
