/*
 * sounds.c
 *
 *  Created on: 18 апр. 2016 г.
 *      Author: Vladmir
 */

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "sounds.h"
#include <stdio.h>

static const char *MY_COOL_MP3 = "assets/sounds/day_43_mono.mp3";

void SND_PlayMusic() {
	int result = 0;
	int flags = MIX_INIT_MP3;

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		printf("Failed to init SDL\n");
	}

	if (flags != (result = Mix_Init(flags))) {
		printf("Could not initialize mixer (result: %d).\n", result);
		printf("Mix_Init: %s\n", Mix_GetError());
		return;
	}

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *music = Mix_LoadMUS(MY_COOL_MP3);
	Mix_PlayMusic(music, -1);

	//Mix_FreeMusic(music);
	return;
}
