#include "Engine.h"

#include <iostream>
#include "SDL_image.h"

using namespace PowderEngine;

Engine::Engine() = default;

Engine::~Engine()
{
	for (auto t : _controllableObjects)
	{
		delete t;
	}
	_controllableObjects.clear();

	// Destroy window
	SDL_DestroyRenderer(_sdlRenderer);
	SDL_DestroyWindow(_sdlWindow);
	_sdlWindow = nullptr;
	_sdlRenderer = nullptr;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool Engine::init(int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init False! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Create window
	_sdlWindow = SDL_CreateWindow("PowderEngine Test",
								  SDL_WINDOWPOS_UNDEFINED,
								  SDL_WINDOWPOS_UNDEFINED,
								  width,
								  height,
								  SDL_WINDOW_SHOWN);

	if (_sdlWindow == nullptr)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		_w = width;
		_h = height;
		// Get window surface
		_sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (_sdlRenderer == nullptr)
		{
			std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		else
		{
			// Initialize renderer color
			SDL_SetRenderDrawColor(_sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			// Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
				return false;
			}
		}
	}

	std::string path = "Idle.png";
	addTexture(path, 10, {73, 69, 48, 54}, 180);

	gameLoop();

	return true;
}

void Engine::gameLoop()
{
	SDL_Event e;
	// While application is running
	while (!_stoppable)
	{
		// Handle events on queue
		handleEvent(&e);
		_render();
	}
}

bool Engine::addTexture(std::string &path, int numOfSheet, const SDL_Rect &firstSprite, int space)
{
	auto engineTexture = new PowderEngine::ControllableObject({_w / 2, _h / 2}, _sdlRenderer, path);

	engineTexture->loadSprites(numOfSheet, firstSprite, space);
	_controllableObjects.push_back(engineTexture);
	return true;
}

void Engine::_render()
{
	// Clear screen
	SDL_SetRenderDrawColor(_sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_sdlRenderer);

	// Render _texture to screen
	_controllableObjects[0]->render(_sdlRenderer);

	// Update screen
	SDL_RenderPresent(_sdlRenderer);
}

bool Engine::removeTexture(std::string &path)
{
	/*for(auto texture : _availTexture)
	{
		if(texture->getImagePath() == path)
		{

		}
	}*/

	return false;
}

void Engine::handleEvent(SDL_Event *event)
{
	while (SDL_PollEvent(event) != 0)
	{
		// User requests quit
		switch (event->type)
		{
		case SDL_QUIT:
			_stoppable = true;
			break;
		case SDL_KEYDOWN:
		{
			_controllableObjects[0]->handleEvent(static_cast<SDL_KeyCode>(event->key.keysym.sym));
		}
		break;
		default:
			break;
		}
	}
}
