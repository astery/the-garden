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

	IMG_INIT(IMG_FPV_PATH, &img_win_1, "win-1.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_2, "win-2.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_3, "win-3.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_4, "win-4.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_5, "win-5.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_6, "win-6.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_7, "win-7.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_8, "win-8.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_9, "win-9.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_10, "win-10.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_11, "win-11.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_12, "win-12.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_13, "win-13.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_14, "win-14.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_15, "win-15.png");
	IMG_INIT(IMG_FPV_PATH, &img_win_16, "win-16.png");

	IMG_INIT(IMG_FPV_PATH, &img_game_over, "gameover.png");

	anim_win = (Animation) {
		.steps_count = 16,
		.steps = {
			&img_win_1,
			&img_win_2,
			&img_win_3,
			&img_win_4,
			&img_win_5,
			&img_win_6,
			&img_win_7,
			&img_win_8,
			&img_win_9,
			&img_win_10,
			&img_win_11,
			&img_win_12,
			&img_win_13,
			&img_win_14,
			&img_win_15,
			&img_win_16,
		},
		.width = 7,
		.height = 7
	};

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
	LoadMap3(&maps[2]);
	LoadMap4(&maps[3]);
	LoadMap5(&maps[4]);

	return ret;
}

#define N NONE
#define W WALL
#define P PLAYER
#define M MONSTER
#define E EXIT

Pawn map1_pawns[] = {
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 10, .def = 0, .gold = 2 }
};

Pawn map2_pawns[] = {
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 1, .def = 0, .gold = 1 },
		{ .type = PT_MONSTER, .health = 1, .atk = 1, .def = 1, .gold = 1 },
		{ .type = PT_MONSTER, .health = 2, .atk = 1, .def = 0, .gold = 1 }
};

Pawn map3_pawns[] = {
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 2, .def = 1, .gold = 1 },
		{ .type = PT_MONSTER, .health = 2, .atk = 3, .def = 0, .gold = 1 },
		{ .type = PT_MONSTER, .health = 2, .atk = 2, .def = 1, .gold = 1 },
		{ .type = PT_MONSTER, .health = 3, .atk = 2, .def = 1, .gold = 1 }
};

Pawn map4_pawns[] = {
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 3, .def = 0, .gold = 1 },
		{ .type = PT_MONSTER, .health = 4, .atk = 4, .def = 1, .gold = 1 },
		{ .type = PT_MONSTER, .health = 2, .atk = 3, .def = 0, .gold = 1 },
		{ .type = PT_MONSTER, .health = 3, .atk = 5, .def = 1, .gold = 2 },
		{ .type = PT_MONSTER, .health = 2, .atk = 3, .def = 0, .gold = 1 },
		{ .type = PT_MONSTER, .health = 6, .atk = 3, .def = 2, .gold = 3 },
		{ .type = PT_MONSTER, .health = 3, .atk = 4, .def = 2, .gold = 1 },
		{ .type = PT_MONSTER, .health = 4, .atk = 2, .def = 0, .gold = 2 },
		{ .type = PT_MONSTER, .health = 1, .atk = 3, .def = 3, .gold = 1 },
		{ .type = PT_MONSTER, .health = 1, .atk = 6, .def = 0, .gold = 3 }
};

Pawn map5_pawns[] = {
		{ .type = PT_PLAYER, .health = 3, .atk = 1, .def = 0 },
		{ .type = PT_MONSTER, .health = 2, .atk = 1, .def = 0, .gold = 1 },
		{ .type = PT_MONSTER, .health = 3, .atk = 2, .def = 1, .gold = 1 },
		{ .type = PT_MONSTER, .health = 4, .atk = 3, .def = 2, .gold = 1 },
		{ .type = PT_MONSTER, .health = 5, .atk = 4, .def = 3, .gold = 1 },
		{ .type = PT_MONSTER, .health = 6, .atk = 5, .def = 4, .gold = 1 }
};

void LoadMap1(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ W, W, W, W, W, W, W },
			{ W, N, N, N, M, N, W },
			{ W, N, W, W, W, N, W },
			{ W, N, W, W, W, N, W },
			{ W, N, W, E, N, N, W },
			{ W, P, W, W, W, W, W },
			{ W, W, W, W, W, W, W },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map1_pawns[0], &map->tiles[4][1], NULL);
	Pawn_Init(&map1_pawns[1], &map->tiles[3][4], NULL);
}

void LoadMap2(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ W, W, W, W, W, W, W },
			{ W, N, N, M, N, M, W },
			{ W, N, W, W, W, N, W },
			{ W, N, N, M, W, N, W },
			{ W, N, W, N, W, N, W },
			{ W, P, W, N, E, N, W },
			{ W, W, W, W, W, W, W },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map2_pawns[0], &map->tiles[3][1], NULL);
	Pawn_Init(&map2_pawns[1], &map->tiles[5][1], NULL);
	Pawn_Init(&map2_pawns[2], &map->tiles[3][3], NULL);
	Pawn_Init(&map2_pawns[3], &map->tiles[4][5], NULL);
}

void LoadMap3(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ E, W, W, W, N, N, M },
			{ N, W, M, N, N, W, N },
			{ N, N, N, W, M, N, N },
			{ W, W, W, W, N, W, N },
			{ N, N, N, N, N, W, N },
			{ N, W, N, W, W, W, N },
			{ P, W, N, N, N, N, M },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map3_pawns[0], &map->tiles[6][0], NULL);
	Pawn_Init(&map3_pawns[1], &map->tiles[2][1], NULL);
	Pawn_Init(&map3_pawns[2], &map->tiles[4][2], NULL);
	Pawn_Init(&map3_pawns[3], &map->tiles[6][6], NULL);
	Pawn_Init(&map3_pawns[4], &map->tiles[0][0], NULL);
}

void LoadMap4(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ N, M, N, M, N, M, E },
			{ N, W, N, W, N, W, N },
			{ N, M, N, M, N, N, N },
			{ N, W, N, W, N, W, M },
			{ M, N, N, M, N, N, N },
			{ N, W, N, W, N, W, M },
			{ P, N, N, M, N, N, N },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map4_pawns[0], &map->tiles[1][0], NULL);
	Pawn_Init(&map4_pawns[1], &map->tiles[3][0], NULL);
	Pawn_Init(&map4_pawns[2], &map->tiles[5][0], NULL);
	Pawn_Init(&map4_pawns[3], &map->tiles[1][2], NULL);
	Pawn_Init(&map4_pawns[4], &map->tiles[3][2], NULL);
	Pawn_Init(&map4_pawns[5], &map->tiles[6][3], NULL);
	Pawn_Init(&map4_pawns[6], &map->tiles[0][4], NULL);
	Pawn_Init(&map4_pawns[7], &map->tiles[3][4], NULL);
	Pawn_Init(&map4_pawns[8], &map->tiles[6][5], NULL);
	Pawn_Init(&map4_pawns[9], &map->tiles[3][6], NULL);
	Pawn_Init(&map4_pawns[10], &map->tiles[6][6], NULL);
}

void LoadMap5(Map *map) {
	Map_Init(map);
	MapSlice m;
	m = (MapSlice) {
		.tiles[0] =
			{ M, N, N, N, N, N, M },
			{ N, W, W, W, W, W, N },
			{ N, W, M, N, E, W, N },
			{ N, W, N, W, W, W, N },
			{ N, W, N, W, W, W, N },
			{ N, W, M, N, N, N, M },
			{ P, W, W, W, W, W, W },
	};
	Map_AppendFromItemTypeArray(map, m);
	Pawn_Init(&map5_pawns[0], &map->tiles[0][0], NULL);
	Pawn_Init(&map5_pawns[1], &map->tiles[6][0], NULL);
	Pawn_Init(&map5_pawns[2], &map->tiles[6][5], NULL);
	Pawn_Init(&map5_pawns[3], &map->tiles[2][5], NULL);
	Pawn_Init(&map5_pawns[4], &map->tiles[2][2], NULL);
	Pawn_Init(&map5_pawns[5], &map->tiles[4][2], NULL);
}

void LoadMaps(Map maps_dest[GAME_MAPS_COUNT]) {
	int i;
	Map *map;

	for (i=0; i < GAME_MAPS_COUNT; i++) {
		map = &maps_dest[i];
		*map = maps[i];
	}
}
