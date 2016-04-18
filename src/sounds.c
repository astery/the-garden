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

void SND_PlayVictory() {
	Mix_Music *music = Mix_LoadMUS(SND_VICTORY);
	Mix_PlayMusic(music, -1);
}

void SND_PlayFootsteps() {
	Mix_Chunk *sample = Mix_LoadWAV(SND_FOOTSTEPS);
	Mix_PlayChannel(1, sample, 0);
}

void SND_PlayOpenDoor() {
	Mix_Chunk *sample = Mix_LoadWAV(SND_OPEN_DOOR);
	Mix_PlayChannel(1, sample, 0);
}

void SND_PlayAttack() {
	Mix_Chunk *sample = Mix_LoadWAV(SND_ATTACK);
	Mix_PlayChannel(1, sample, 0);
}
