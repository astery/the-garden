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
#include "game.h"
#include "image.h"

int main(int argc, char* argv[])
{
	Game game;
	if (Game_Init(&game, 640, 480) != 0) {
		return 1;
	}


	GameController controller;
	if (GameController_Init(&controller, game.render) != 0) {
		Game_Destroy(&game);
		return 1;
	}

	Game_RunLoop(&game, &controller);
	Game_Destroy(&game);
	return 0;
}
