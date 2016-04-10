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
	IMG_INIT(&img_menu, "start_screen.png");
	IMG_INIT(&img_arrow_down_1, "arrow_down_1.png");
	IMG_INIT(&img_arrow_down_2, "arrow_down_2.png");
	IMG_INIT(&img_arrow_up_1, "arrow_up_1.png");
	IMG_INIT(&img_arrow_up_2, "arrow_up_2.png");
	IMG_INIT(&img_arrow_left_1, "arrow_left_1.png");
	IMG_INIT(&img_arrow_left_2, "arrow_left_2.png");
	IMG_INIT(&img_arrow_right_1, "arrow_right_1.png");
	IMG_INIT(&img_arrow_right_2, "arrow_right_2.png");

	anim_arrow_down = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_arrow_down_1,
			&img_arrow_down_2
		},
		.width = 7,
		.height = 7
	};

	anim_arrow_up = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_arrow_up_1,
			&img_arrow_up_2
		},
		.width = 7,
		.height = 7
	};

	anim_arrow_left = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_arrow_left_1,
			&img_arrow_left_2
		},
		.width = 7,
		.height = 7
	};

	anim_arrow_right = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_arrow_right_1,
			&img_arrow_right_2
		},
		.width = 7,
		.height = 7
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
