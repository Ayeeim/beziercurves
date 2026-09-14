#ifndef RENDER
#define RENDER

#include <SDL3/SDL.h>
#include <vector>
#include "Line.h"

extern SDL_Renderer* rdr;
extern std::vector<Line> Gyzmos;
extern std::vector<Line> Lines;


// Render the game objects [UNUSED]
void Render();

#endif // !RENDER
