/*
 * animation.h
 *
 *  Created on: Apr 10, 2016
 *      Author: astery
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "image.h"

#define ANIMATION_MAX_STEPS 16
#define ANIMATION_STEP_TIME 500

typedef struct {
	int steps_count;
	Image *steps[ANIMATION_MAX_STEPS];
	int width;
	int height;
} Animation;

void Animation_ResetClock();
void Animation_Render(Animation *anim, SDL_Renderer *renderer, int x, int y);
int Animation_GetCurrentStep(int steps_count);
long Animation_GetClock();

#endif /* ANIMATION_H_ */
