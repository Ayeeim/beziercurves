#include <iostream>
#include "Input.hpp"
#include "Points.hpp"
#include "Constant.hpp"

unsigned int lastFrameTime = 0;
float deltaTime;

void Update() {

	int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - lastFrameTime);
	if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
		SDL_Delay(timeToWait);
	}

	deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
	lastFrameTime = SDL_GetTicks();

	if (mouseButtonPressed[SDL_BUTTON_LEFT]) {
		printf("Hoooray ! \n");
		

	}

}