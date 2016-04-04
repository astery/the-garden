/*
 * manager.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "manager.h"


void SceneManager_Init(SceneManager *manager, Scene *init_scene) {
	manager->current_scene = init_scene;
}

void SceneManager_SetCurrentScene(SceneManager *manager, Scene *scene) {
	manager->current_scene->destructor(manager->current_scene);
	manager->current_scene = scene;
}
