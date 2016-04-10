/*
 * animation.c
 *
 *  Created on: Apr 10, 2016
 *      Author: astery
 */

#include "animation.h"
#include <time.h>
#include <sys/timeb.h>


static struct timeb start_time;

void Animation_ResetClock() {
    ftime(&start_time);
}

void Animation_Render(Animation *anim, SDL_Renderer *renderer, int x, int y) {
	int step = Animation_GetCurrentStep(anim->steps_count);
	Image *t = anim->steps[step];
	SDL_Rect dest;
	dest.w = anim->width;
	dest.h = anim->height;
	dest.x = x;
	dest.y = y;
	SDL_RenderCopy(renderer, t->texture, NULL, &dest);
}

int Animation_GetCurrentStep(int steps_count) {
	long steps = (long) ((double) Animation_GetClock()) / ANIMATION_STEP_TIME;
	long current_step = steps % steps_count;
	return current_step;
}

long Animation_GetClock() {
	struct timeb current;
    ftime(&current);
    return (long) (1000.0 * (current.time - start_time.time)
      + (current.millitm - start_time.millitm));
}
