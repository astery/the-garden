/*
 * game.h
 *
 *  Created on: 2 апр. 2016 г.
 *      Author: Astery
 */

#ifndef GAME_H_
#define GAME_H_

typedef struct {
	SDL_Window *window;
	SDL_Renderer *render;
	int screen_width;
	int screen_height;
} Game;

int Game_Init(Game *game, int screen_width, int screen_height);
void Game_Destroy(Game *game);

#endif /* GAME_H_ */
