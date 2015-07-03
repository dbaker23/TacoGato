#pragma once
#include <SDL.h>
#include <stdio.h>

#define DEFAULT_WINDOW_HEIGHT 720
#define DEFAULT_WINDOW_WIDTH  1080
#define GAME_NAME             "Taco Gato"

//Holds all the information pertaining just to the windows itself, Parent to Game_Renderer class
class Game_Window
{
public:
    /*=====================================================
    *Constructor: Setup the game window with default 480p resolution

    *Parameters:          
    =======================================================*/
    Game_Window();

    /*=====================================================
    *Overloaded Constructor: User-defined values for screen witdth, height, and other options

    *Parameters: 
            height: screen height resolution
            width: screen width resolution
            userFlags: window flags such as fullscreen or fit-to-screen and stuff
    =======================================================*/
    Game_Window( const int height, const int width, const int userFlags );

    //Destructor
    ~Game_Window();

    const int   GetScreenHeight() { return screenHeight; }
    const int   GetScreenWidth()  { return screenWidth;  }
    const char* GetGameName()     { return gameName; }
    Uint32      GetFlags()        { return flags; }

private:
    const int   screenHeight;   // Screen height
    const int   screenWidth;    // screen width
    const char* gameName;       // Our game name for the window's header
    Uint32      flags;          // FLags for our window: fullscreen, resizeable, etc

protected:
    SDL_Window* window;         // The window that will be updated int he game loop
};

