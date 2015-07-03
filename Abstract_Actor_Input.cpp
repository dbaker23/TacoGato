#include "Abstract_Actor_Input.h"


Abstract_Actor_Input::Abstract_Actor_Input()
{
    spaceBar    = SDLK_SPACE;
    tilde       = SDLK_BACKQUOTE;
    left        = SDLK_LEFT;
    right       = SDLK_RIGHT;
    up          = SDLK_UP;
    down        = SDLK_DOWN;
    ctrl        = SDLK_LCTRL;
    w           = SDLK_w;
    a           = SDLK_a;
    s           = SDLK_s;
    d           = SDLK_d;
    n1          = SDLK_1;
    n2          = SDLK_2;
    n3          = SDLK_3;
    n4          = SDLK_4;

    mouseLeft   = false;
}


Abstract_Actor_Input::~Abstract_Actor_Input()
{
}

void Abstract_Actor_Input::HandleInput( const SDL_Event& e )
{
	//Keys are held in a boolean map, where pressed is true and not pressed is false

	//Check which keys are down
    if( e.type == SDL_KEYDOWN )
		//SDL will return the keys pressed
        keys[ e.key.keysym.sym ] = true;

	//If keys are up, set them to false
    else if( e.type == SDL_KEYUP )
        keys[ e.key.keysym.sym ] = false;

    if( e.type == SDL_MOUSEBUTTONDOWN )
        mouseLeft = true;
    else if( e.type == SDL_MOUSEBUTTONUP )
        mouseLeft = false;

}