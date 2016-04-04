/*
 * game_scene.c
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#include "scene.h"

#include "assets.h"

void Scene_Init(Scene *scene, SceneInputHandler input_handler, SceneRender render, SceneDestructor destructor) {
	scene->input_handler = input_handler;
	scene->render = render;
	scene->destructor = destructor;
}
