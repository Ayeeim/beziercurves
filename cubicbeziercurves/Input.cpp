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

			// Escape is my leaving key
			if (event.key.key == SDLK_ESCAPE) {
				printf("Exit has been made by ESC \n");
				gameIsRunning = false;
			}

			if (!event.key.repeat) {
				keyDown[event.key.scancode] = true;
				keyPressed[event.key.scancode] = true;
				printf("\"%d\" Key was pressed ! \n", event.key.key);
			}
			break;

		case SDL_EVENT_KEY_UP:
			keyDown[event.key.scancode] = false;
			printf("\"%d\" Key was released ! \n", event.key.key);
			break;



		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if (!event.key.repeat) {
				mouseButtonDown[event.button.button] = true;
				mouseButtonPressed[event.button.button] = true;
				printf("\"%d\" Mouse button was pressed ! \n", event.button.button);
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_UP:
			mouseButtonDown[event.button.button] = false;
			printf("\"%d\" Mouse button was released ! \n", event.button.button);
			break;

		default:
			break;
	}
}

void Clear_input() {
	std::fill(keyPressed, keyPressed + SDL_SCANCODE_COUNT, false);
	std::fill(mouseButtonPressed, mouseButtonPressed + MOUSE_BUTTON_COUNT, false);
}


// init keys ?
// create an object for each keys children of a class keys
// Add all keys to an array
// create method isPressed and isDown