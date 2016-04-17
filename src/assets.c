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

	IMG_INIT(IMG_FPV_PATH, &img_stat_hp, "stat-hp.png");
	IMG_INIT(IMG_FPV_PATH, &img_stat_lv, "stat-lv.png");
	IMG_INIT(IMG_FPV_PATH, &img_stat_df, "stat-df.png");
	IMG_INIT(IMG_FPV_PATH, &img_stat_op, "stat-op.png");
	IMG_INIT(IMG_FPV_PATH, &img_stat_at, "stat-at.png");
	IMG_INIT(IMG_FPV_PATH, &img_stat_gd, "stat-gd.png");

	IMG_INIT(IMG_FPV_PATH, &img_tutor_a, "tutor-a.png");
	IMG_INIT(IMG_FPV_PATH, &img_tutor_d, "tutor-d.png");

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

	IMG_INIT(IMG_FPV_PATH, &img_knight_1_attack, "bknight-1-attack.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_idle, "bknight-1-idle.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_idle_2, "bknight-1-idle-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_down, "bknight-1-down.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_2_down, "bknight-2-down.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_3_down, "bknight-3-down.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_1_defend, "bknight-1-defend.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_2, "bknight-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_2_2, "bknight-2-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_3, "bknight-3.png");
	IMG_INIT(IMG_FPV_PATH, &img_knight_4, "bknight-4.png");

	anim_knight_idle = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_knight_1_idle,
			&img_knight_1_idle_2
		},
		.width = 7,
		.height = 7
	};

	anim_knight_2_idle = (Animation) {
		.steps_count = 2,
		.steps = {
			&img_knight_2,
			&img_knight_2_2
		},
		.width = 7,
		.height = 7
	};

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
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 1, .def = 0, .gold = 1 }
};

Pawn map2_pawns[] = {
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 1, .def = 0, .gold = 1 }
};

void LoadMap1(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ N, W, M, W, N, N, N },
			{ N, W, N, W, W, W, N },
			{ N, W, N, N, N, W, N },
			{ N, W, N, W, N, W, N },
			{ N, W, P, W, E, W, N },
			{ N, W, W, W, W, W, N },
			{ N, N, N, N, N, N, N },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map1_pawns[0], &map->tiles[2][4], NULL);
	Pawn_Init(&map1_pawns[1], &map->tiles[2][0], NULL);
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
	Pawn_Init(&map2_pawns[0], &map->tiles[2][4], NULL);
	Pawn_Init(&map2_pawns[1], &map->tiles[3][2], NULL);
}

void LoadMaps(Map maps_dest[GAME_MAPS_COUNT]) {
	int i;
	Map *map;

	for (i=0; i < GAME_MAPS_COUNT; i++) {
		map = &maps_dest[i];
		*map = maps[i];
	}
}
