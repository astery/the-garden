/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef SCENES_MAP_H_
#define SCENES_MAP_H_

#include "../scene.h"
#include "../image.h"

typedef struct {
	Scene scene;
	Image background;
} MapScene;

int MapScene_Init(MapScene *scene, SDL_Renderer *render);
void MapScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e);
void MapScene_RenderScene(void *scene, SDL_Renderer *render);

#endif /* SCENES_MAP_H_ */
