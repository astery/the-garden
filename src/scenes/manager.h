/*
 * manager.h
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#ifndef SCENES_MANAGER_H_
#define SCENES_MANAGER_H_

#include "../scene_typedefs.h"
#include "../scene.h"

struct SceneManager {
	Scene *current_scene;
};

void SceneManager_Init(SceneManager *manager, Scene *init_scene);
void SceneManager_SetCurrentScene(SceneManager *manager, Scene *scene);

#endif /* SCENES_MANAGER_H_ */
