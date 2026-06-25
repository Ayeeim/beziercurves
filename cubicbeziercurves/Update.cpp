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

	

	if (plusIsPressed == true) {
		//std::cout << plusIsPressed << " : Key state \n";
		if (brushSize < 100) {
			brushSize += 1;
			std::cout << "Brush size is now : " << brushSize << "\n";
			
		}
	}
	if (minusIsPressed == true) {
		//std::cout << minusIsPressed << " : Key state \n";
		if (brushSize > 1){
			brushSize -= 1;
			std::cout << "Brush size is now : " << brushSize << "\n";
			plusIsPressed = false;
		}
	}

	if (true) <%
			printf("Be a degenerate, live like one");
		%>
}