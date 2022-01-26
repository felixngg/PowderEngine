#ifndef UNSTOPPABLEGAME_COMMONDEFINE_H
#define UNSTOPPABLEGAME_COMMONDEFINE_H

#include <cstdint>

namespace PowderEngine
{
	struct Coordinates2D
	{
		int x;
		int y;
	};

	struct Rectangle
	{
		int width;
		int height;
		Coordinates2D topLeft;
	};
}

#endif //UNSTOPPABLEGAME_COMMONDEFINE_H
