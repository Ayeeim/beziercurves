#ifndef INPUT
#define INPUT

#include <SDL3/SDL.h>

void test_Process_input();

// Process input from the user
void Process_input();

extern bool plusIsPressed;
extern bool minusIsPressed;


extern bool keyDown[SDL_SCANCODE_COUNT];
extern bool keyPressed[SDL_SCANCODE_COUNT];
extern bool mouseButtonDown[];
extern bool mouseButtonPressed[];

// Get the different posisitons of the mouse depending on states
// s-------s
// position = get the current position of the mouse 
// BTDownPosition = get the position on mouse button down 
// BTUpPosition = get the position on mouse button up 
struct MouseState
{
	struct Vector2 position;
	struct Vector2 BTDownPosition;
	struct Vector2 BTUpPosition;
} mouseState;

// Clear the inputs (commonly at the end of a frame)
void Clear_input();

#endif // !INPUT
