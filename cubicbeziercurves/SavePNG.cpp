#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include "Render.hpp"

bool savePNG = false;

void Set_SavePNG(bool val) {savePNG = val;}
bool Get_SavePNG() {return savePNG;}

void Save_Image() {
	SDL_Surface* surface = SDL_RenderReadPixels(rdr, NULL);

	std::cout << "Saved Image as a png \n";

	IMG_SavePNG(surface, "img/TestFile.png");

	SDL_DestroySurface(surface);
}