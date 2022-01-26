#ifndef UNSTOPPABLEGAME_GAMEOBJECT_H
#define UNSTOPPABLEGAME_GAMEOBJECT_H

#include <string>
#include "SDL.h"

namespace PowderEngine
{
	struct ObjectInfo
	{
		int height;
		int width;
		std::string imagePath;
	};

	class GameObject
	{
	public:
		GameObject(SDL_Renderer* renderer, std::string& path);
		virtual ~GameObject();

		virtual void handleEvent(SDL_KeyCode keycode) = 0;
		virtual void render(SDL_Renderer* renderer) = 0;

		inline int getWidth() const
		{
			return _info.width;
		}

		inline int getHeight() const
		{
			return _info.height;
		}

		inline const std::string& getImagePath() const
		{
			return _info.imagePath;
		}


	protected:
		ObjectInfo _info{};
		SDL_Texture* _texture{};
	};
}


#endif //UNSTOPPABLEGAME_GAMEOBJECT_H
