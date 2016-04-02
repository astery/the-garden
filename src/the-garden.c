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

#define IMG_PATH ".\\assets\\"
#define IMG_LENA IMG_PATH "lena512.bmp"


int SDL_main(int argc, char* argv[])
{
	Game game;
	if (Game_Init(&game, 640, 480) != 0) {
		return 1;
	}

	SDL_Renderer *ren = game.render;

	char imagePath[] = IMG_LENA;
	SDL_Surface *bmp = SDL_LoadBMP(imagePath);
	if (bmp == NULL){
		printf("SDL_LoadBMP Error: %s", SDL_GetError());
		Game_Destroy(&game);
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == NULL){
		printf("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
		Game_Destroy(&game);
		return 1;
	}

	SDL_Rect destR;
	destR.w = game.screen_width / 4;
	destR.h = game.screen_height / 4;

	int i;
	for (i = 0; i < 3; ++i){
		SDL_RenderClear(ren);
		destR.x = 0;
		destR.y = 0;

		SDL_RenderCopy(ren, tex, NULL, &destR);
		SDL_RenderPresent(ren);
		SDL_Delay(1000);
	}

	Game_Destroy(&game);
	return 0;
}
