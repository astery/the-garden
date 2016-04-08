/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef SCENES_MENU_H_
#define SCENES_MENU_H_

#include "../scene.h"
#include "../image.h"
#include "manager.h"

typedef struct {
	Scene scene;
} MenuScene;

void MenuScene_Init(MenuScene *scene);
void MenuScene_Destructor(void *scene);
void MenuScene_HandleInput(void *scene, Game *game, SceneManager *manager, SDL_Event *e);
void MenuScene_RenderScene(void *scene, Game *game, SDL_Renderer *render);

#endif /* SCENES_MENU_H_ */
