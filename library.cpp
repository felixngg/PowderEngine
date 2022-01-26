#include "library.h"
#include "SDL.h"

#include <iostream>

void hello()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "Hello World!!";
    }
    SDL_Quit();
}
