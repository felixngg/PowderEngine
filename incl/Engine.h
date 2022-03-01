#ifndef UNSTOPPABLEGAME_ENGINE_H
#define UNSTOPPABLEGAME_ENGINE_H

#include "SDL.h"
#include "ControllableObject.h"
#include <string>
#include <vector>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

namespace PowderEngine
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		bool init(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
		bool addTexture(std::string &path, int numOfSprite, const SDL_Rect &firstSprite, int space);
		bool removeTexture(std::string &path);
		void gameLoop();
		void handleEvent(SDL_Event *event);

	private:
		SDL_Window *_sdlWindow{};
		SDL_Renderer *_sdlRenderer{};
		std::vector<PowderEngine::ControllableObject *> _controllableObjects;
		int _w{};
		int _h{};
		bool _stoppable{false};

		void _render();
	};
}

#endif // UNSTOPPABLEGAME_ENGINE_H
