/*
 * image.c
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#include <stdio.h>
#include <string.h>
#include "image.h"
#include <SDL2/SDL_image.h>

int Image_Init(Image *image, char path[], SDL_Renderer *render) {
	strcpy(image->path, path);
	image->texture = Image_CreateTexture(image, render);

	return image->texture == NULL ? 1 : 0;
}

SDL_Texture* Image_CreateTexture(Image *image, SDL_Renderer *render) {
	SDL_Surface *img_surf = IMG_Load(image->path);
	if (img_surf == NULL){
		printf("IMG_Load: %s\n", IMG_GetError());
		return NULL;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(render, img_surf);
	SDL_FreeSurface(img_surf);
	if (texture == NULL){
		printf("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
		return NULL;
	}

	return texture;
}
