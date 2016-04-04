/*
 * game_scene.h
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <SDL2/SDL.h>

#include "scene_typedefs.h"
#include "scenes/manager.h"

typedef void (*SceneInputHandler)(void *scene, SceneManager *manager, SDL_Event *e);
typedef void (*SceneRender)(void *scene, SDL_Renderer *render);

struct Scene {
	SceneInputHandler input_handler;
	SceneRender render;
};

void Scene_Init(Scene *scene, SceneInputHandler input_handler, SceneRender render);

#endif /* SCENE_H_ */
