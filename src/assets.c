/*
 * assets.c
 *
 *  Created on: Apr 5, 2016
 *      Author: astery
 */

#include "assets.h"

#define IMG_INIT(path, var, res) ret = Image_Init(var, path res, render);\
	if (ret != 0) return ret;

int AssetsLoad(SDL_Renderer *render) {
	int ret;
	IMG_INIT(IMG_SCREENS_PATH, &img_menu, "start_screen.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_down_1, "arrow_down_1.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_down_2, "arrow_down_2.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_up_1, "arrow_up_1.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_up_2, "arrow_up_2.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_left_1, "arrow_left_1.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_left_2, "arrow_left_2.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_right_1, "arrow_right_1.png");
	IMG_INIT(IMG_SCREENS_PATH, &img_arrow_right_2, "arrow_right_2.png");

	IMG_INIT(IMG_FPV_PATH, &img_front_1_side_0, "front-1_side-0.png");

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

	LoadMap1(&maps[0]);
	LoadMap2(&maps[1]);

	return ret;
}

#define N NONE
#define W WALL
#define P PLAYER
#define M MONSTER
#define E EXIT

Pawn map1_pawns[] = {
		{ .type = PT_PLAYER, .health = 1, .atk = 1, .def = 0 }
};

Pawn map2_pawns[] = {
		{ .type = PT_PLAYER, .health = 1, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 1, .atk = 1, .def = 0 }
};

void LoadMap1(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ N, N, N, N, N, N, N },
			{ N, W, W, W, W, W, N },
			{ N, W, N, N, N, W, N },
			{ N, W, N, W, N, W, N },
			{ N, W, P, W, E, W, N },
			{ N, W, W, W, W, W, N },
			{ N, N, N, N, N, N, N },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map1_pawns[0], &map->tiles[2][4]);
}

void LoadMap2(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ N, N, N, N, N, N, N },
			{ N, W, W, W, W, W, N },
			{ N, W, N, M, N, W, N },
			{ N, W, N, W, N, W, N },
			{ N, W, P, W, E, W, N },
			{ N, W, W, W, W, W, N },
			{ N, N, N, N, N, N, N },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map2_pawns[0], &map->tiles[2][4]);
	Pawn_Init(&map2_pawns[1], &map->tiles[4][4]);
}

void LoadMaps(Map maps_dest[GAME_MAPS_COUNT]) {
	int i;
	Map *map;

	for (i=0; i < GAME_MAPS_COUNT; i++) {
		map = &maps_dest[i];
		*map = maps[i];
	}
}
