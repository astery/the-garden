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
#include "map.h"

#ifdef _WIN32
#define SEP "\\"
#else
#define SEP "/"
#endif

#define IMG_PATH "." SEP "passets" SEP

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

Animation anim_arrow_down;
Animation anim_arrow_up;
Animation anim_arrow_left;
Animation anim_arrow_right;

int AssetsLoad(SDL_Renderer *render);
void LoadMap1(Map *map);

#endif /* ASSETS_H_ */
