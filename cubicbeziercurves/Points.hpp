#ifndef POINTS
#define POINTS

#include <SDL3/SDL.h>

/// <summary>
/// Old func to draw points, Inneficient too much RAM used
/// </summary>
/// <param name="rdr"></param>
/// <param name="x_"></param>
/// <param name="y_"></param>
/// <param name="brushSize"></param>
void Draw_point(SDL_Renderer* rdr, int x_, int y_, int brushSize);


/// <summary>
/// Add a points to the rects
/// </summary>
/// <param name="rects">vector of rects</param>
/// <param name="x_">X axis</param>
/// <param name="y_">Y axis</param>
/// <param name="brushSize">size of the brush, will mostly be 1</param>
void Add_points(std::vector<SDL_FRect>& rects, int x_, int y_, int brushSize);

#endif // !POINTS
