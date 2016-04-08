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
#include "assets.h"
#include "scenes/manager.h"
#include "scenes/menu.h"
#include "game.h"

int main(int argc, char* argv[])
{
	Application app;
	if (Application_Init(&app, 320, 320, 7, 7) != 0) {
		return 1;
	}

	if (AssetsLoad(app.render) != 0) {
		Application_Destroy(&app);
		return 1;
	}

	Game game;
	Game_Init(&game);

	MenuScene *menu_scene = malloc(sizeof *menu_scene);
	MenuScene_Init(menu_scene);

	SceneManager scene_manager;
	SceneManager_Init(&scene_manager, (Scene *) menu_scene);

	Application_RunLoop(&app, &scene_manager, &game);
	Application_Destroy(&app);
	return 0;
}
