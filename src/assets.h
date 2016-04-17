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
Image img_knight_1_down;
Image img_knight_1_defend;
Image img_knight_2;
Image img_knight_3;

Animation anim_arrow_down;
Animation anim_arrow_up;
Animation anim_arrow_left;
Animation anim_arrow_right;

#define GAME_MAPS_COUNT 3
Map maps[GAME_MAPS_COUNT];

int AssetsLoad(SDL_Renderer *render);
void LoadMaps(Map map[GAME_MAPS_COUNT]);
void LoadMap1(Map *map);
void LoadMap2(Map *map);

#endif /* ASSETS_H_ */
