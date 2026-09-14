//#ifndef LINE
//#define LINE
//
//#include<SDL3/SDL.h>
//
//class Circle
//{
//private:
//	int brushSize;
//	//Starting and end coordinates
//	int startX, startY, endX, endY;
//	// Color of the line by [r,g,b,a]
//	SDL_Color color;
//
//	bool Display_anchor_points;
//
//public:
//
//	// Getters/Setters ---vv
//	int Get_brushSize();
//	void Set_brushSize(int val);
//
//	SDL_Color Get_color();
//	void Set_color(SDL_Color* color_);
//
//	// Draw a line starting from a point to another point
//	// Based on Bresenham algorithm (not the optimized one)
//	// https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham
//	void Draw_lines(SDL_Renderer* rdr);
//
//	// Constructor/Destructor
//	Line(int brushSize_, int startX_, int startY_, int endX_, int endY_, SDL_Color* color_);
//	~Line();
//
//};
//
//#endif // !LINE
//
//
//
///*
//
//https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
//
//*/