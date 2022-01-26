#include "GameObject.h"

#include <iostream>
#include "SDL_image.h"

using namespace PowderEngine;

GameObject::GameObject(SDL_Renderer* renderer, std::string& path)
{
	//Load image at specified _imagePath
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface)
	{
		std::cout << "Unable to load image " << path.c_str() << " SDL_image Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0xFF, 0xFF ) );

		//Create _texture from surface pixels
		_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (!_texture)
		{
			std::cout << "Unable to create _texture from " << path.c_str() << " SDL Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			_info.width = loadedSurface->w;
			_info.height = loadedSurface->h;
		}

		_info.imagePath = path;
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

GameObject::~GameObject()
{
	//Free texture
	if(_texture)
	{
		SDL_DestroyTexture(_texture);
		_texture = nullptr;
	}
}
