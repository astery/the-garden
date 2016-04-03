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
#include "image.h"
#include "scenes/menu.h"

int main(int argc, char* argv[])
{
	Application app;
	if (Application_Init(&app, 640, 480) != 0) {
		return 1;
	}

	MenuScene menu_scene;
	if (MenuScene_Init(&menu_scene, app.render) != 0) {
		Application_Destroy(&app);
		return 1;
	}

	Application_RunLoop(&app, (Scene *) &menu_scene);
	Application_Destroy(&app);
	return 0;
}
