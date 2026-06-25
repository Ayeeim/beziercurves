#include <iostream>
#include <stdio.h>
#include <SDL3/SDL.h>
#include "GameManager.hpp"
#include "Input.hpp"
#include "Constant.hpp"
#include <string>

float* mouseX;
float* mouseY;

bool plusIsPressed = false;
bool minusIsPressed = false;
int test = 50;

bool leftMouseButton = false;
bool rightMouseButton = false;
bool middleMouseButton = false;

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
				SDL_GetGlobalMouseState(mouseX, mouseY);

				
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

class Key {
	private:
		std::string name;
		bool isPressed = false;

};