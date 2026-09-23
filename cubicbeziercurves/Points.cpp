#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include "Constant.hpp"
#include "Line.h"
#include "Render.hpp"
 
std::vector<Vector2i> pointList;

void Draw_point(SDL_Renderer* rdr, int x_, int y_, int brushSize) {
	SDL_FRect rectPoint;

	rectPoint.h = brushSize;
	rectPoint.w = brushSize;
	rectPoint.x = x_;
	rectPoint.y = y_;

	SDL_RenderFillRect(rdr, &rectPoint);
}

void Add_points(std::vector<SDL_FRect> &rects, int x_, int y_, int brushSize) {
	SDL_FRect rectPoint;

	rectPoint.h = brushSize;
	rectPoint.w = brushSize;
	rectPoint.x = x_;
	rectPoint.y = y_;

	rects.push_back(rectPoint);
}