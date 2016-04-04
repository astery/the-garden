/*
 * assets.c
 *
 *  Created on: Apr 5, 2016
 *      Author: astery
 */

#include "assets.h"

#define IMG_INIT(var, res) ret = Image_Init(var, IMG_PATH res, render);\
	if (ret != 0) return ret;

int AssetsLoad(SDL_Renderer *render) {
	int ret;
	IMG_INIT(&img_menu, "menu.bmp");
	IMG_INIT(&img_map, "walk.bmp");

	return ret;
}
