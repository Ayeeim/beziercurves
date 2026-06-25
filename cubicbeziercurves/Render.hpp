#ifndef RENDER
#define RENDER

#include <SDL3/SDL.h>
#include <vector>
#include "Line.h"

extern SDL_Renderer* rdr;
extern std::vector<Line> Gyzmos;

// Render the game objects [UNUSED]
void Render();

#endif // !RENDER
