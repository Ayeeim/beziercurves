#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include "Constant.hpp"
#include "Line.h"
 
std::vector<Line> line;
int points{ 2 };

// Draw a point to the set coordinate
void Draw_point(SDL_Renderer* rdr, int x_, int y_) {
	SDL_FRect rectPoint;

	rectPoint.h = 1;
	rectPoint.w = 1;
	rectPoint.x = x_;
	rectPoint.y = y_;

	// Draws Left and Right wall
	SDL_RenderFillRect(rdr, &rectPoint);
}

// https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham
void Draw_lines(SDL_Renderer* rdr, int startingPointX, int startingPointY, int endPointX, int endPointY) {

	int dx = endPointX - startingPointX;
	int dy = endPointY - startingPointY;

	int y = startingPointY;

	// calcul du taux d'erreur
	float e=0.0, e1 =0.0, e2 =0.0;
	e1 = (float)dy / (float)dx;
	e2 = -1.0;

	//int m = (endPointY - startingPointY) / (endPointX - startingPointX);

	// i = x
	for (int i = 0; i <= dx; i++) {

		Draw_point(rdr, startingPointX + i, y);
		e += e1;
		if (e >= 0.5) {
			y = y + 1;
			e = e + e2;
		}
	}
}

//void Add_point(float x, float y) {
//	
//}

//procédure tracerSegment(entier x1, entier y1, entier x2, entier y2) est
//déclarer entier x, y, dx, dy;
//déclarer rationnel e, e(1, 0), e(0, 1);  // valeur d’erreur et incréments
//dy <- y2 - y1;
//dx <- x2 - x1;

//y <- y1;  // rangée initiale
//e <- 0, 0;  // valeur d’erreur initiale
//e(1, 0) <- dy / dx;
//e(0, 1) <- - 1.0;

//pour x variant de x1 jusqu’à x2 par incrément de 1 faire
//tracerPixel(x, y);
//si(e <-  e + e(1, 0)) >= 0, 5 alors  // erreur pour le pixel suivant de même rangée
//y <-  y + 1;  // choisir plutôt le pixel suivant dans la rangée supérieure
//e <-  e + e(0, 1);  // ajuste l’erreur commise dans cette nouvelle rangée
//fin si;
//fin pour;
//fin procédure;



// correct : 


//procédure tracerSegment(entier x1, entier y1, entier x2, entier y2) est
//déclarer entier x, y, dx, dy;
//déclarer entier e; // valeur d’erreur
//déclarer entier e(1, 0), e(0, 1);  // incréments
//
//dy <- y2 - y1;
//dx <- x2 - x1;
//y <- y1;  // rangée initiale
//e <- - dx;  // valeur d’erreur initiale
//e(1, 0) <-  dy × 2;
//e(0, 1) <- - dx × 2;
//
//pour x variant de x1 jusqu’à x2 par incrément  de 1 faire
//tracerPixel(x, y);
//si(e <- e + e(1, 0)) >= 0 alors  // erreur pour le pixel suivant de même rangée
//y <- y + 1;  // choisir plutôt le pixel suivant dans la rangée supérieure
//e <- e + e(0, 1);  // ajuste l’erreur commise dans cette nouvelle rangée
//fin si;
//fin pour;
//
//fin procédure;