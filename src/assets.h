/*
 * assets.h
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#ifndef ASSETS_H_
#define ASSETS_H_

#include "image.h"
#include "map.h"

#ifdef _WIN32
#define SEP "\\"
#else
#define SEP "/"
#endif

#define IMG_PATH "." SEP "assets" SEP

Image img_menu;
Image img_map;
Image img_tutor_up;
Image img_tutor_down;
Image img_tutor_right;
Image img_tutor_left;

int AssetsLoad(SDL_Renderer *render);
void LoadMap1(Map *map);

#endif /* ASSETS_H_ */
