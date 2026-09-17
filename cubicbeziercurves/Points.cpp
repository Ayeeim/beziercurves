#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include "Constant.hpp"
#include "Line.h"
#include "Render.hpp"
 
std::vector<Vector2i> pointList;


// Draw a point to the set coordinate
void Draw_point(SDL_Renderer* rdr, int x_, int y_, int brushSize) {
	SDL_FRect rectPoint;

	rectPoint.h = brushSize;
	rectPoint.w = brushSize;
	rectPoint.x = x_;
	rectPoint.y = y_;

	SDL_RenderFillRect(rdr, &rectPoint);
}

/*
[UNUSED]
*/
void AddPoint(Vector2i point) {
	// si < 2
	// Ajouter point

	// si égal à 2 
	// vider
	// + dessiner

	if (pointList.size() < 2) {
		pointList.push_back(point);
	}

	if (pointList.size() == 2) {
		printf("Draw Line \n");
		
		pointList.clear();
	}
}