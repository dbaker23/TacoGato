#include <SDL.h>
#include "Main_Loop.h"

int main( int argc, char* args[] )
{
    //Initialize SDL2
    SDL_Init( SDL_INIT_EVERYTHING );
	//Init the font and SDL font stuff
    TTF_Init();
    Main_Loop mainLoop;
	//Run the program
    mainLoop.Run();
    return 0;
}