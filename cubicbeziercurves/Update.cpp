#include <iostream>
#include <SDL3/SDL.h>
#include "Input.hpp"
#include "Constant.hpp"
#include "Render.hpp"

unsigned int lastFrameTime = 0;
float deltaTime;

struct Vector2 firstPoint;
struct Vector2 secondPoint;
bool firstPointSet = false;

SDL_Color WHITE = { 255, 255, 255, 255 };
SDL_Color RED = { 255, 0, 0, 255 };

int brushSize = 1;

void Line_tool();

void Update() {

	int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - lastFrameTime);
	if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
		SDL_Delay(timeToWait);
	}

	deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
	lastFrameTime = SDL_GetTicks();

	/*
	
	*/
	if (keyDown[SDL_SCANCODE_KP_PLUS]) {
		std::cout << "plus key was pressed !!!!";
		brushSize++;
	}

	Line_tool();

}

/*

*/
void Line_tool() {
	if (mouseButtonPressed[SDL_BUTTON_LEFT]) {
		printf("Hoooray ! \n");

		std::cout << "mouseState.BTDownPosition x : " << mouseState.BTDownPosition.x << ", y : " << mouseState.BTDownPosition.y << "\n";

		if (firstPointSet == false) {
			firstPoint = mouseState.BTDownPosition;

			firstPointSet = true;
		}
		else {
			secondPoint = mouseState.BTDownPosition;
			firstPointSet = false;

			printf("Line was drawn with the mouse");

			Lines.push_back(Line(brushSize, firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y, &RED));
		}
	}
}