/*
 * image.h
 *
 *  Created on: 3 апр. 2016 г.
 *      Author: Astery
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL2/SDL.h>

#define PATH_MAX_LEN 100

typedef struct {
	char path[PATH_MAX_LEN];
	SDL_Texture *texture;
} Image;

int Image_Init(Image *image, char path[], SDL_Renderer *render);
SDL_Texture* Image_CreateTexture(Image *image, SDL_Renderer *render);

#endif /* IMAGE_H_ */
