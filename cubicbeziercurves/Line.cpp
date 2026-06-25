#include "Line.h"
#include "Points.hpp"

int Line::Get_brushSize() {
	return brushSize;
}

void Line::Set_brushSize(int val) {
	brushSize += val;
}

// https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham
void Line::Draw_lines(SDL_Renderer* rdr) {
	int dx = endX - startX;
	int dy = endY - startY;
	int y = startY;
	// calcul du taux d'erreur
	float e = 0.0, e1 = 0.0, e2 = 0.0;
	e1 = (float)dy / (float)dx;
	e2 = -1.0;
	int m = (endY - startY) / (endX - startX);
	// i = x
	for (int i = 0; i <= dx; i++) {
		Draw_point(rdr, startX + i, y);
		e += e1;
		if (e >= 0.5) {
			y = y + 1;
			e = e + e2;
		}
	}
}

SDL_Color Line::Get_color() {

	return color;
}

void Line::Set_color(SDL_Color* color_) {
	color.r = color_->r;
	color.g = color_->g;
	color.b = color_->b;
	color.a = color_->a;
}

Line::Line(int brushSize_, int startX_, int startY_, int endX_, int endY_, SDL_Color* color_) {
	brushSize = brushSize_;
	startX = startX_;
	startY = startY_;
	endX = endX_;
	endY = endY_;
	Set_color(color_);
	Display_anchor_points = false;
}

Line::~Line() {
}