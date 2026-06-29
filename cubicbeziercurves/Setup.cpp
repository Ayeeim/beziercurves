#include "Setup.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Render.hpp"
#include "Constant.hpp"

// Start Prototype : 
void Draw_random_line_setup(int count, SDL_Color* color);
// End Prototype


void Setup() {

	if (true) <%
		printf("Be a degenerate, live like one");
	%>

	// Get a different random number each time the program runs
	srand(int(time(0)));

	SDL_Color RED = { 255, 0, 0, 255 };
	SDL_Color GREEN = { 0, 255, 0, 255 };
	SDL_Color BLUE = { 0, 0, 255, 255 };

	Gyzmos.push_back(Line(10, 10, 10, 100, 180, &BLUE));

	Draw_random_line_setup(100, &GREEN);
}


void Draw_random_line_setup(int count, SDL_Color * color) {
	for (int i = 0; i < count; i++) {

		// Generate a random number for points A and B
		int randomStartX = rand() % WIDTH;
		int randomStartY = rand() % HEIGH;
		int randomEndX = rand() % WIDTH;
		int randomEndY = rand() % HEIGH;

		printf("Valeur de X (fin début) : %d et %d \n valeurs de Y (fin et debut) : %d et %d \n", randomStartX, randomEndX, randomStartY, randomEndY);
		Gyzmos.push_back(Line(1, randomStartX, randomStartY, randomEndX, randomEndY, color));
	}
}