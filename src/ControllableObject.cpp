#include "ControllableObject.h"

using namespace PowderEngine;

ControllableObject::ControllableObject(const PowderEngine::Coordinates2D& initPosition,
	SDL_Renderer* renderer,
	std::string& path)
	: GameObject(renderer, path)
{
	_sprites.topLeft = initPosition;
}

ControllableObject::~ControllableObject()
= default;

void ControllableObject::handleEvent(SDL_KeyCode keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		_sprites.topLeft.y -= 10;
		break;

	case SDLK_DOWN:
		_sprites.topLeft.y += 10;
		break;

	case SDLK_LEFT:
		_sprites.topLeft.x -= 10;
		break;

	case SDLK_RIGHT:
		_sprites.topLeft.x += 10;
		break;

	default:
		break;
	}
}

void ControllableObject::render(SDL_Renderer* renderer)
{
	auto totalSprite = _spritesPosition.size();

	//Set rendering space and render to screen
	SDL_Rect
		currentSprite = { _spritesPosition[_frame / totalSprite].x, _spritesPosition[_frame / totalSprite].y,
						  _sprites.width, _sprites.height };
	SDL_Rect renderQuad = { _sprites.topLeft.x, _sprites.topLeft.y, _sprites.width, _sprites.height };

	SDL_RenderCopy(renderer, _texture, &currentSprite, &renderQuad);

	_increaseFrame();
}

void ControllableObject::loadSprites(int numOfSprite, const SDL_Rect& firstSprite, int space)
{
	_sprites.height = firstSprite.h;
	_sprites.width = firstSprite.w;

	Coordinates2D position{};
	for (int i = 0; i < numOfSprite; ++i)
	{
		position = { firstSprite.x + space * i, firstSprite.y };
		_spritesPosition.push_back(position);
	}
}

void ControllableObject::_increaseFrame()
{
	auto totalSprite = _spritesPosition.size();

	++_frame;
	if (_frame / totalSprite >= totalSprite)
	{
		_frame = 0;
	}
}

