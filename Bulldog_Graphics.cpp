#include "Bulldog_Graphics.h"
#include "Enemy_Bulldog.h"

Bulldog_Graphics::Bulldog_Graphics( Game_Renderer* renderer, int startX, int startY ) : Abstract_Actor_Graphics( renderer ),
    STARTING_X( startX ),
    STARTING_Y( startY )
{
    sprite = new Sprite( renderer->LoadTexture( SPRITE_PATH ), BULLDOG_WIDTH, BULLDOG_HEIGHT );
    destination.h = BULLDOG_HEIGHT; 
    destination.w = BULLDOG_WIDTH;
    destination.x = STARTING_X;
    destination.y = STARTING_Y;
}


Bulldog_Graphics::~Bulldog_Graphics()
{
}

void Bulldog_Graphics::Update( Component_Game_Actor& bulldog, SDL_Rect camera, const float timeStep )
{
    destination.x -= camera.x;
    destination.y -= camera.y;
}