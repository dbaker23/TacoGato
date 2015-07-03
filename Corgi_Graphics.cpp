#include "Corgi_Graphics.h"
#include "Enemy_Corgi.h"

Corgi_Graphics::Corgi_Graphics( Game_Renderer* renderer, int startX, int startY ) : Abstract_Actor_Graphics( renderer ),
    STARTING_X( startX ),
    STARTING_Y( startY )
{
    sprite = new Sprite( renderer->LoadTexture( SPRITE_PATH ), CORGI_WIDTH, CORGI_HEIGHT );
    destination.h = CORGI_HEIGHT; 
    destination.w = CORGI_WIDTH;
    destination.x = STARTING_X;
    destination.y = STARTING_Y;
}


Corgi_Graphics::~Corgi_Graphics()
{
}

void Corgi_Graphics::Update( Component_Game_Actor& corgi, SDL_Rect camera, const float timeStep )
{
    destination.x -= camera.x;
    destination.y -= camera.y;
}