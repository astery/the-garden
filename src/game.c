/*
 * game.c
 *
 *  Created on: Apr 8, 2016
 *      Author: astery
 */

#include "game.h"
#include "assets.h"

void Game_Init(Game *game) {
	LoadMap1(&game->maps[0]);
	game->current_map = &game->maps[0];

	MapItem *item;
	int i;
	for (i=0; i < game->current_map->items_count; i++) {
		item = &game->current_map->items[i];
		if (item->type == PLAYER) {
			game->player->pos = item;
		}
	}

	if (game->player == NULL) {
		printf("Game: current map has no player");
	}

	game->player->orient = OUP;
}
