#include "Engine.h"

#include <iostream>

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Get window surface
        gScreenSurface = SDL_GetWindowSurface( gWindow );
    }

    return true;
}
