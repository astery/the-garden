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

#define WIDTH 640
#define HEIGHT 480
#define IMG_PATH ".\\assets\\"
#define IMG_LENA IMG_PATH "lena512.bmp"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Error");
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL){
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL){
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	char imagePath[] = IMG_LENA;
	SDL_Surface *bmp = SDL_LoadBMP(imagePath);
	if (bmp == NULL){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		printf("SDL_LoadBMP Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == NULL){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		printf("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Rect destR;
	destR.w = WIDTH / 4;
	destR.h = HEIGHT / 4;

	int i;
	for (i = 0; i < 3; ++i){
		SDL_RenderClear(ren);
		destR.x = 0;
		destR.y = 0;

		SDL_RenderCopy(ren, tex, NULL, &destR);
		SDL_RenderPresent(ren);
		SDL_Delay(1000);
	}

	return 0;
}
