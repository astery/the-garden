/*
 * game.h
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#ifndef GAME_H_
#define GAME_H_

#include "game_typedefs.h"
#include <stdbool.h>
#include "game_state.h"
#include "map.h"
#include "assets.h"


struct Game {
	GameState *state;
	Map maps[GAME_MAPS_COUNT];
	int current_map_index;
	Map *current_map;
	Pawn player;

	GameStateName prev_state;
	Pawn *last_monster;
	bool show_hud;
	bool defeat_enemy_on_this_step;
};

void Game_Init(Game *game);
void Game_Reset(Game *game);
void Game_SetCurrentMap(Game *game, int map_index);
void Game_SetCurrentState(Game *game, GameStateName state_name);
void Game_MovePawn(Game *game, Pawn *pawn, Orientation orient);
void Game_MovePlayer(Game *game, Orientation orient);
void Game_ResetPlayer(Game *game);
void Game_PawnHitPawn(Game *game, Pawn *att, Pawn *rec);
bool Game_IsMonsterNearPlayer(Game *game);
void Game_StepInDoor(Game *game);
void Game_MoveToNextMap(Game *game);


#endif /* GAME_H_ */
