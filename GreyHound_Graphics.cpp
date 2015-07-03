#include "GreyHound_Graphics.h"
#include "Enemy_GreyHound.h"

GreyHound_Graphics::GreyHound_Graphics( Game_Renderer* renderer, int startX, int startY ) : Abstract_Actor_Graphics( renderer ),
    STARTING_X( startX ),
    STARTING_Y( startY )
{
    sprite = new Sprite( renderer->LoadTexture( SPRITE_PATH ), GREYHOUND_WIDTH, GREYHOUND_HEIGHT );
    destination.h = GREYHOUND_HEIGHT; 
    destination.w = GREYHOUND_WIDTH;
    destination.x = STARTING_X;
    destination.y = STARTING_Y;
}


GreyHound_Graphics::~GreyHound_Graphics()
{
}

void GreyHound_Graphics::Update( Component_Game_Actor& greyHound, SDL_Rect camera, const float timeStep )
{
    destination.x -= camera.x;
    destination.y -= camera.y;
}
