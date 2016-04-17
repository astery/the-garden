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
#include "game.h"
#include "game_states/menu.h"
#include "sounds.h"

int main(int argc, char* argv[])
{
	Application app;
	if (Application_Init(&app, 320, 320) != 0) {
		return 1;
	}

	if (AssetsLoad(app.renderer) != 0) {
		Application_Destroy(&app);
		return 1;
	}

	Game game;
	Game_Init(&game);
	SND_PlayMusic();

	Application_RunLoop(&app, &game);
	Application_Destroy(&app);
	return 0;
}
