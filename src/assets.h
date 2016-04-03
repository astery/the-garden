/*
 * assets.h
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: Astery
 */

#ifndef ASSETS_H_
#define ASSETS_H_

#ifdef _WIN32
#define SEP "\\"
#else
#define SEP "/"
#endif

#define IMG_PATH "." SEP "assets" SEP
#define IMG_MENU IMG_PATH "menu.bmp"
#define IMG_GAME_OVER IMG_PATH "game_over.bmp"
#define IMG_FIGHT IMG_PATH "fight.bmp"
#define IMG_WALK IMG_PATH "walk.bmp"

#endif /* ASSETS_H_ */
