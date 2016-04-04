/*
 ============================================================================
 Name        : the-garden.c
 Author      : Astery & Z
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "application.h"
#include "scenes/manager.h"
#include "scenes/menu.h"

int main(int argc, char* argv[])
{
	Application app;
	if (Application_Init(&app, 640, 480) != 0) {
		return 1;
	}

	SceneManager scene_manager;
	SceneManager_Init(&scene_manager);

	MenuScene menu_scene;
	if (MenuScene_Init(&menu_scene, app.render) != 0) {
		Application_Destroy(&app);
		return 1;
	}

	SceneManager_SetCurrentScene(&scene_manager, (Scene *) &menu_scene);

	Application_RunLoop(&app, &scene_manager);
	Application_Destroy(&app);
	return 0;
}
