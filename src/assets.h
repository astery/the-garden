/*
 * assets.h
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#ifndef ASSETS_H_
#define ASSETS_H_

#include "image.h"
#include "animation.h"
#include "map_typedefs.h"
#include "map.h"

#ifdef _WIN32
#define SEP "\\"
#else
#define SEP "/"
#endif

#define IMG_SCREENS_PATH "." SEP "assets" SEP "screens_assets" SEP
#define IMG_FPV_PATH "." SEP "assets" SEP "first_person_screens_assets" SEP

#define SND_PATH "." SEP "assets" SEP "sounds" SEP
#define SND_VICTORY SND_PATH "victory.mp3"
#define SND_BACKGROUND SND_PATH "day_43_mono.mp3"
#define SND_FOOTSTEPS SND_PATH "footsteps.ogg"
#define SND_OPEN_DOOR SND_PATH "door.ogg"
#define SND_ATTACK SND_PATH "attack.ogg"

Image img_menu;
Image img_map;
Image img_arrow_down_1;
Image img_arrow_down_2;
Image img_arrow_up_1;
Image img_arrow_up_2;
Image img_arrow_left_1;
Image img_arrow_left_2;
Image img_arrow_right_1;
Image img_arrow_right_2;

Image img_tutor_a;
Image img_tutor_d;

Image img_stat_hp;
Image img_stat_lv;
Image img_stat_df;
Image img_stat_op;
Image img_stat_at;
Image img_stat_gd;

Image img_fpv_bground;
Image img_front_1;
Image img_front_2;
Image img_front_3;
Image img_side_0;
Image img_side_1;
Image img_side_2;
Image img_side_3;
Image img_side_0_opened;
Image img_side_1_opened;
Image img_side_2_opened;
Image img_side_3_opened;
Image img_side_0_pixel;

Image img_door_1;
Image img_door_2;
Image img_door_3;
Image img_door_4;

Image img_knight_1_attack;
Image img_knight_1_idle;
Image img_knight_1_idle_2;
Image img_knight_1_down;
Image img_knight_2_down;
Image img_knight_3_down;
Image img_knight_1_defend;
Image img_knight_2;
Image img_knight_2_2;
Image img_knight_3;
Image img_knight_4;

Image img_win_1;
Image img_win_2;
Image img_win_3;
Image img_win_4;
Image img_win_5;
Image img_win_6;
Image img_win_7;
Image img_win_8;
Image img_win_9;
Image img_win_10;
Image img_win_11;
Image img_win_12;
Image img_win_13;
Image img_win_14;
Image img_win_15;
Image img_win_16;

Image img_game_over;

Animation anim_win;

Animation anim_knight_idle;
Animation anim_knight_2_idle;

Animation anim_arrow_down;
Animation anim_arrow_up;
Animation anim_arrow_left;
Animation anim_arrow_right;

#define GAME_MAPS_COUNT 6
Map maps[GAME_MAPS_COUNT];

int AssetsLoad(SDL_Renderer *render);
void LoadMaps(Map map[GAME_MAPS_COUNT]);
void LoadMap1(Map *map);
void LoadMap2(Map *map);
void LoadMap3(Map *map);
void LoadMap4(Map *map);
void LoadMap5(Map *map);

#endif /* ASSETS_H_ */
