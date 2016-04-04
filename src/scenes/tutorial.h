/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef SCENES_TUTORIAL_H_
#define SCENES_TUTORIAL_H_

#include "../scene.h"
#include "../image.h"
#include "manager.h"

enum Action {
	DOWN, LEFT, RIGHT, UP
};

typedef struct {
	Scene scene;
	enum Action action;
} TutorialScene;

void TutorialScene_Init(TutorialScene *scene);
void TutorialScene_Destructor(void *scene);
void TutorialScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e);
void TutorialScene_RenderScene(void *scene, SDL_Renderer *render);

#endif /* SCENES_TUTORIAL_H_ */
