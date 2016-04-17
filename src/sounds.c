/*
 * sounds.c
 *
 *  Created on: 18 ���. 2016 �.
 *      Author: Vladmir
 */

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "sounds.h"
#include <stdio.h>
#include "assets.h"

void SND_PlayBackground() {
	Mix_Music *music = Mix_LoadMUS(SND_BACKGROUND);
	Mix_PlayMusic(music, -1);
}

void SND_PlayFootsteps() {
	Mix_Music *music = Mix_LoadMUS(SND_FOOTSTEPS);
	Mix_PlayMusic(music, 0);
}

void SND_PlayOpenDoor() {
	Mix_Music *music = Mix_LoadMUS(SND_OPEN_DOOR);
	Mix_PlayMusic(music, 0);
}

void SND_PlayAttack() {
	Mix_Music *music = Mix_LoadMUS(SND_ATTACK);
	Mix_PlayMusic(music, 0);
}
