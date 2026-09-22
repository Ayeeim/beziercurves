#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Line.h"
#include "Points.hpp"


int Line::Get_brushSize() {
	return brushSize;
}

void Line::Set_brushSize(int val) {
	brushSize = val;
}

//...New
void Line::Draw_lines(SDL_Renderer* rdr) {

    std::vector<SDL_FRect> rects;
    rects.reserve(std::max(std::abs(endX-startX), std::abs(startX-startY))+1);

    // The lenght between
    int dx = endX - startX;
    //
    int dy = endY - startY;

    //
    int stepX = (dx >= 0) ? 1 : -1;
    //
    int stepY = (dy >= 0) ? 1 : -1;

    dx = std::abs(dx);
    dy = std::abs(dy);

    //
    float e = 0.0f, e2 = -1.0f;

    if (dx >= dy) {
        // ligne plutôt horizontale : x est l'axe directeur
        float e1 = (dx == 0) ? 0.0f : (float)dy / (float)dx;
        int y = startY;
        for (int i = 0; i <= dx; i++) {
            Draw_point(rdr, startX + i * stepX, y, brushSize);
            e += e1;
            if (e >= 0.5f) {
                y += stepY;
                e += e2;
            }
        }
    }
    else {
        // ligne plutôt verticale : y est l'axe directeur
        float e1 = (float)dx / (float)dy;
        int x = startX;
        for (int i = 0; i <= dy; i++) {
            Draw_point(rdr, x, startY + i * stepY, brushSize);
            e += e1;
            if (e >= 0.5f) {
                x += stepX;
                e += e2;
            }
        }
    }


    //SDL_RenderFillRects(rdr, rects.data(), rects.size());
}

/*
// https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham
void Line::Draw_lines(SDL_Renderer* rdr) {
	int dx = endX - startX;
	int dy = endY - startY;
	int y = startY;
	// calcul du taux d'erreur
	float e = 0.0, e1 = 0.0, e2 = 0.0;
	e1 = (float)dy / (float)dx;
	e2 = -1.0;
	std::cout << "DX : " << dx << ", DY : " << dy << ", Y :" << y << "\n";
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
*/

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
