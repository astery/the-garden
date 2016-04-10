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
	IMG_INIT(&img_menu, "title.png");
	IMG_INIT(&img_arrow_down_1, "arrow_down_1.png");
	IMG_INIT(&img_arrow_down_2, "arrow_down_2.png");
	IMG_INIT(&img_tutor_up, "arrow_up_1.png");
	IMG_INIT(&img_tutor_down, "arrow_down_1.png");
	IMG_INIT(&img_tutor_right, "arrow_right_1.png");
	IMG_INIT(&img_tutor_left, "arrow_left_1.png");

	anim_arrow_down = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_arrow_down_1,
			&img_arrow_down_2
		},
		.width = 5,
		.height = 6
	};

	return ret;
}

#define N NONE
#define W WALL
#define P PLAYER
#define M MONSTER
#define E EXIT

void LoadMap1(Map *map) {
	MapItemType m[MAP_SIZE][MAP_SIZE] = {
			{ N, N, N, N, N, N, N },
			{ N, W, W, W, W, W, N },
			{ N, W, N, N, N, W, N },
			{ N, W, N, W, N, W, N },
			{ N, W, P, W, E, W, N },
			{ N, W, W, W, W, W, N },
			{ N, N, N, N, N, N, N },
	};
	Map_GenerateFromItemTypeArray(map, m);
}
