#ifndef POINTS
#define POINTS

#include <SDL3/SDL.h>

void Draw_point(SDL_Renderer* rdr, int x_, int y_);

void Draw_lines(SDL_Renderer* rdr, int startingPointX, int startingPointY, int endPointX, int endPointY);

void Draw_random_line(SDL_Renderer* rdr, int count);

extern int brushSize;

#endif // !POINTS
