#ifndef UNSTOPPABLEGAME_CONTROLLABLEOBJECT_H
#define UNSTOPPABLEGAME_CONTROLLABLEOBJECT_H

#include <vector>
#include "GameObject.h"
#include "CommonDefine.h"

namespace PowderEngine
{
	class ControllableObject final : GameObject
	{
	public:
		ControllableObject(const Coordinates2D& initPosition, SDL_Renderer* renderer, std::string& path);
		~ControllableObject() final;

		void handleEvent(SDL_KeyCode keycode) override;
		void render(SDL_Renderer* renderer) override;
		void loadSprites(int numOfSprite, const SDL_Rect& firstSprite, int space);

	private:
		Rectangle _sprites{};
		std::vector<Coordinates2D> _spritesPosition{};
		int _frame{};

		void _increaseFrame();
	};
}


#endif //UNSTOPPABLEGAME_CONTROLLABLEOBJECT_H
