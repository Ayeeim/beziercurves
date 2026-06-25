#include <SDL3/SDL.h>
#include <iostream>
#include "Constant.hpp"
#include "Input.hpp"
#include "GameManager.hpp"
#include "Render.hpp"
#include "Update.hpp"
#include "Setup.hpp"

SDL_Window* win = NULL;

static bool initialize_window() {

	if (SDL_Init(0) != 1) {
		fprintf(stderr, "Error initializing SDL. [erW01]\n");
		return false;
	}

	win = SDL_CreateWindow("Bezier curves", WIDTH, HEIGH, 0); //SDL_WINDOW_RESIZABLE
	if (!win) {
		fprintf(stderr, "Error initializing SDL. [erW02]\n");
		return false;
	}
	rdr = SDL_CreateRenderer(win, NULL);
	if (!rdr) {
		fprintf(stderr, "Error initializing SDL Renderer. [erR01]\n");
		return false;
	}

	return true;
}

bool Destroy_window() {
	SDL_DestroyRenderer(rdr);					// deallocate renderer memory
	SDL_DestroyWindow(win);						// deallocate window memory
	SDL_Quit();

	return true;
}

int main(int argc, char* args[]) {

	gameIsRunning = initialize_window();
	printf("\n Programm started successfully \n");

	Setup();

	printf("Game is running : %d \n", gameIsRunning);
	while (gameIsRunning) {
		Process_input();
		Update();
		Render();
	}

	// End of program -vv

	Destroy_window();

	printf("\n Programm ended successfully \n");

	return 0;
}