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

	IMG_INIT(IMG_FPV_PATH, &img_fpv_bground, "background.png");
	IMG_INIT(IMG_FPV_PATH, &img_front_1, "front-1.png");
	IMG_INIT(IMG_FPV_PATH, &img_front_2, "front-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_front_3, "front-3.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_0, "side-0.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_1, "side-1.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_2, "side-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_3, "side-3.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_0_opened, "side-0-opened.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_1_opened, "side-1-opened.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_2_opened, "side-2-opened.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_3_opened, "side-3-opened.png");
	IMG_INIT(IMG_FPV_PATH, &img_side_0_pixel, "side-0-pixel.png");

	IMG_INIT(IMG_FPV_PATH, &img_door_1, "door-1.png");
	IMG_INIT(IMG_FPV_PATH, &img_door_2, "door-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_door_3, "door-3.png");
	IMG_INIT(IMG_FPV_PATH, &img_door_4, "door-4.png");

	IMG_INIT(IMG_FPV_PATH, &img_knight_1_attack, "knight-1-attack.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_idle, "knight-1-idle.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_down, "knight-1-down.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_defend, "knight-1-defend.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_2, "knight-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_3, "knight-3.png");

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
			{ N, W, E, W, N, N, N },
			{ N, W, N, W, W, W, N },
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
