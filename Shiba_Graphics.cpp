#include "Shiba_Graphics.h"
#include "Enemy_Shiba.h"

Shiba_Graphics::Shiba_Graphics( Game_Renderer* renderer, int startX, int startY ) : Abstract_Actor_Graphics( renderer ),
    STARTING_X( startX ),
    STARTING_Y( startY )
{
    sprite = new Sprite( renderer->LoadTexture( SPRITE_PATH ), SHIBA_WIDTH, SHIBA_HEIGHT );
    destination.h = SHIBA_HEIGHT; 
    destination.w = SHIBA_WIDTH;
    destination.x = STARTING_X;
    destination.y = STARTING_Y;
}


Shiba_Graphics::~Shiba_Graphics(void)
{
}

void Shiba_Graphics::Update( Component_Game_Actor& corgi, SDL_Rect camera, const float timeStep )
{
    destination.x -= camera.x;
    destination.y -= camera.y;
}