/*
 * game_scene.h
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <SDL2/SDL.h>
#include "image.h"

typedef void (*SceneInputHandler)(void *scene, SDL_Event e);
typedef void (*SceneRender)(void *scene, SDL_Renderer *render);

typedef struct {
	SceneInputHandler input_handler;
	SceneRender render;
} Scene;

void Scene_Init(Scene *scene, SceneInputHandler input_handler, SceneRender render);

#endif /* SCENE_H_ */
