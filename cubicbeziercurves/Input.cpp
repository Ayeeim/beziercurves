#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <SDL3/SDL.h>
#include "GameManager.hpp"
#include "Input.hpp"
#include "Constant.hpp"
#include <string>


// SDL number of mouse buttons 
// 0 is ignored
const int MOUSE_BUTTON_COUNT = 6;

float mouseX;
float mouseY;

bool plusIsPressed = false;
bool minusIsPressed = false;
int test = 50;

bool leftMouseButton = false;
bool rightMouseButton = false;
bool middleMouseButton = false;

bool keyDown[SDL_SCANCODE_COUNT] = {};
bool keyPressed[SDL_SCANCODE_COUNT] = {};
bool mouseButtonDown[MOUSE_BUTTON_COUNT] = {};
bool mouseButtonPressed[MOUSE_BUTTON_COUNT] = {};

// 
void test_Process_input() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_EVENT_QUIT:
			gameIsRunning = false;

			break;

		case SDL_EVENT_KEY_DOWN:
			if (!event.key.repeat) {
				keyDown[event.key.scancode] = true;
				keyPressed[event.key.scancode] = true;
				break;
			}

		case SDL_EVENT_KEY_UP:
			keyDown[event.key.scancode] = false;
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if (!event.key.repeat) {
				mouseButtonDown[event.key.scancode] = true;
				mouseButtonPressed[event.key.scancode] = true;
				break;
			}


		case SDL_EVENT_MOUSE_BUTTON_UP:
			mouseButtonDown[event.key.scancode] = false;
			break;

		default:
			break;
	}
}


void Process_input() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type){
		case SDL_EVENT_QUIT:
			gameIsRunning = false;
			break;

		case SDL_EVENT_KEY_DOWN:
			if (event.key.key == SDLK_ESCAPE) {
				printf("Exit has been made by ESC \n");
				gameIsRunning = false;
			}
			if (event.key.key == SDLK_KP_PLUS) {
				printf("Plus key is down \n");
				plusIsPressed = true;
			}
			if (event.key.key == SDLK_KP_MINUS) {
				printf("Minus key is down \n");
				minusIsPressed = true;

			}
			break;

		case SDL_EVENT_KEY_UP:
			if (event.key.key == SDLK_KP_PLUS) {
				printf("Plus key is up \n");
				plusIsPressed = false;
			}
			if (event.key.key == SDLK_KP_MINUS) {
				printf("Minus key is up \n");
				minusIsPressed = false;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				leftMouseButton = true;


				std::cout << "MOUSE BUTTON LEFT has been pressed coord :" << mouseX << " | " << mouseY << "\n";
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				rightMouseButton = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				middleMouseButton = true;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_UP:
			if (event.button.button == SDL_BUTTON_LEFT) {
				leftMouseButton = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				rightMouseButton = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				middleMouseButton = false;
			}
			break;

		default:
			break;
	}
}

void Clear_input() {
	std::fill(keyPressed, keyPressed + SDL_SCANCODE_COUNT, false);
	std::fill(mouseButtonPressed, mouseButtonPressed + MOUSE_BUTTON_COUNT, false);
}