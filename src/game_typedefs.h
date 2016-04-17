/*
 * scene_common.h
 *
 *  Created on: Apr 4, 2016
 *      Author: astery
 */

#ifndef GAME_TYPEDEFS_H_
#define GAME_TYPEDEFS_H_

#include <SDL2/SDL.h>

typedef struct GameState GameState;
typedef struct Game Game;
typedef enum GameStateName GameStateName;
typedef enum FightGS_Stats FightGS_Stats;

typedef void (*GameStateInputHandler)(Game *game, SDL_Event *e);
typedef void (*GameStateRenderer)(Game *game, SDL_Renderer *renderer);
typedef void (*GameStateOnEnter)(Game *game, GameState *from_state);
typedef void (*GameStateOnLeave)(Game *game, GameState *from_state);

#endif /* GAME_TYPEDEFS_H_ */
