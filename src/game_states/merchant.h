/*
 * menu.h
 *
 *  Created on: Apr 3, 2016
 *      Author: astery
 */

#ifndef GAME_STATES_MERCHANT_H_
#define GAME_STATES_MERCHANT_H_

#include "../game_state.h"

enum MGS_Stat {
	MGSS_HP,
	MGSS_AT,
	MGSS_DF,
	MGSS_ITEMS_COUNT
};

typedef struct {
	enum MGS_Stat current_stat;
} MerchantGSData;

void MerchantGS_HandleInput(Game *game, SDL_Event *e);
void MerchantGS_Render(Game *game, SDL_Renderer *render);
void MerchantGS_OnEnter(Game *game, GameState *from_state);
void MerchantGS_OnLeave(Game *game, GameState *from_state);

#endif /* GAME_STATES_MERCHANT_H_ */
