#include "Render.hpp"
#include <iostream>
#include "Points.hpp"
#include "Constant.hpp"


void DrawGyzmo();
void DrawLayer();

SDL_Renderer* rdr = NULL;

std::vector<Line> Gyzmos;
std::vector<Line> Lines;


void Render() {
	SDL_SetRenderDrawColor(rdr, 0, 0, 0, 255);
	SDL_RenderClear(rdr); // Clear the renderer

	DrawGyzmo();
	DrawLayer();
	//DrawGUI();

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

void DrawLayer() {
	for (int i = 0; i < Lines.size(); i++) {
		SDL_Color tmpColor = Lines[i].Get_color();
		SDL_SetRenderDrawColor(rdr, tmpColor.r, tmpColor.g, tmpColor.b, tmpColor.a);
		Gyzmos[i].Draw_lines(rdr);
	}
}