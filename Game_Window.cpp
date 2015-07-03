#include "Game_Window.h"


//Default
Game_Window::Game_Window() :
    screenHeight( DEFAULT_WINDOW_HEIGHT ),
    screenWidth( DEFAULT_WINDOW_WIDTH )
{
    flags = SDL_WINDOW_SHOWN;
    gameName = GAME_NAME;
    window = SDL_CreateWindow( gameName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags );
    
    if( window == NULL ) 
    {
        printf( "Window uninitialized, Error: %s\n", SDL_GetError() );
    }
}

//Overloaded
Game_Window::Game_Window( const int height, const int width, const int userFlags ) :
    screenHeight( height ),
    screenWidth( width )
{
    gameName = GAME_NAME;
    window = SDL_CreateWindow( gameName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, userFlags );
    
    if( window == NULL ) 
    {
        printf( "Window uninitialized, Error: %s\n", SDL_GetError() );
    }
}

//Destructor
Game_Window::~Game_Window()
{
    SDL_DestroyWindow( window );
    window = NULL;
}