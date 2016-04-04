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
	IMG_INIT(&img_menu, "anim" SEP "screens0000.png");
	IMG_INIT(&img_map, "anim" SEP "screens0014.png");
	IMG_INIT(&img_tutor_up, "anim" SEP "screens0002.png");
	IMG_INIT(&img_tutor_down, "anim" SEP "screens0003.png");
	IMG_INIT(&img_tutor_right, "anim" SEP "screens0004.png");
	IMG_INIT(&img_tutor_left, "anim" SEP "screens0005.png");

	return ret;
}
