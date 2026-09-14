#ifndef CONSTANT
#define CONSTANT

#define FPS 144
#define FRAME_TARGET_TIME (1000/FPS)

#define WIDTH 900
#define HEIGH 900


struct Vector2i {
	int x = 0;
	int y = 0;
};

struct Vector2 {
	float x = 0;
	float y = 0;
};

#endif // !CONSTANT
