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
	SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);
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

/*

Draw each layer one by one (line then vectors) for each layer 

Make a vector of layers

Add a deleting option (CTRL+Z) to dump the last added line(might also dump this line into another list or vector)
*/
void DrawLayer() {
	for (int i = 0; i < Lines.size(); i++) {
		SDL_Color tmpColor = Lines[i].Get_color();
		SDL_SetRenderDrawColor(rdr, tmpColor.r, tmpColor.g, tmpColor.b, tmpColor.a);
		Lines[i].Draw_lines(rdr);
	}
}