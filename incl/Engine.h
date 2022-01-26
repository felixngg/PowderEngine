#ifndef UNSTOPPABLEGAME_ENGINE_H
#define UNSTOPPABLEGAME_ENGINE_H

#include "SDL.h"

class Engine
{
public:
	Engine();
	~Engine();

	bool init();

private:
	SDL_Window* _sdlWindow;
	SDL_Renderer* _sdlRenderer;
};

#endif //UNSTOPPABLEGAME_ENGINE_H
