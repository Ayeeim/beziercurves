#include <iostream>
#include "Points.hpp"
#include "Render.hpp"
#include "Constant.hpp"


void DrawGyzmo();

SDL_Renderer* rdr = NULL;

std::vector<Line> Gyzmos;


void Render() {
	SDL_SetRenderDrawColor(rdr, 0, 0, 0, 255);
	SDL_RenderClear(rdr); // Clear the renderer

	DrawGyzmo();

	SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);
	Draw_point(rdr, 50, 50);

	SDL_SetRenderDrawColor(rdr, 255, 0, 0, 255);
	Draw_lines(rdr, 30, 30, 100, 150);
	Draw_lines(rdr, 60, 30, 200, 60);

	SDL_RenderPresent(rdr); // Show a new renderer
}

// Draw the Gyzmos present in the vector, will be drawn in order with their parameters
void DrawGyzmo() {

	for (int i = 0; i < Gyzmos.size(); i++) {
		SDL_Color tmpColor = Gyzmos[i].Get_color();
		SDL_SetRenderDrawColor(rdr, tmpColor.r, tmpColor.g, tmpColor.b, tmpColor.a);
		Gyzmos[i].Draw_lines(rdr);
	}
}