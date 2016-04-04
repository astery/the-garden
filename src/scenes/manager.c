/*
 * manager.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "manager.h"


void SceneManager_Init(SceneManager *manager) {

}

void SceneManager_SetCurrentScene(SceneManager *manager, Scene *scene) {
	manager->current_scene = scene;
}
