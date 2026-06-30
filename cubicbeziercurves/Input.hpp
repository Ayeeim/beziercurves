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

// Clear the inputs (commonly at the end of a frame)
void Clear_input();

#endif // !INPUT
