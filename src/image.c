/*
 * image.c
 *
 *  Created on: 3 апр. 2016 г.
 *      Author: Astery
 */

#include <stdio.h>
#include <string.h>
#include "image.h"

int Image_Init(Image *image, char path[], SDL_Renderer *render) {
	strcpy(image->path, path);
	image->texture = Image_CreateTexture(image, render);

	return image->texture == NULL ? 1 : 0;
}

SDL_Texture* Image_CreateTexture(Image *image, SDL_Renderer *render) {
	SDL_Surface *bmp = SDL_LoadBMP(image->path);
	if (bmp == NULL){
		printf("SDL_LoadBMP Error: %s", SDL_GetError());
		return NULL;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(render, bmp);
	SDL_FreeSurface(bmp);
	if (texture == NULL){
		printf("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
		return NULL;
	}

	return texture;
}
