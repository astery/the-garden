/*
 * menu.c
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#include "map.h"
#include <SDL2/SDL.h>
#include "../assets.h"

void MapScene_Init(MapScene *scene) {
	Scene_Init((Scene *) scene, MapScene_HandleInput, MapScene_RenderScene, MapScene_Destructor);
	scene->map = (Map*) malloc(sizeof *scene->map);
	Map_Generate(scene->map);
}

void MapScene_Destructor(void *scene) {
	MapScene *map_scene = (MapScene *) scene;
	free(map_scene->map);
	free(map_scene);
}

void MapScene_HandleInput(void *scene, SceneManager *manager, SDL_Event *e) {

}

void MapScene_RenderScene(void *scene, SDL_Renderer *render) {
	MapScene *map_scene = (MapScene *) scene;
	Map_Render(map_scene->map, render);
}
