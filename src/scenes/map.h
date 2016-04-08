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
#include "../map.h"

typedef struct {
	Scene scene;
	Map *map;
} MapScene;

void MapScene_Init(MapScene *scene);
void MapScene_Destructor(void *scene);
void MapScene_HandleInput(void *scene, Game *game, SceneManager *manager, SDL_Event *e);
void MapScene_RenderScene(void *scene, Game *game, SDL_Renderer *render);

#endif /* SCENES_MAP_H_ */
