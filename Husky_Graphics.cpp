#include "Husky_Graphics.h"
#include "Enemy_Husky.h"

Husky_Graphics::Husky_Graphics( Game_Renderer* renderer, int startX, int startY ) : Abstract_Actor_Graphics( renderer ),
    STARTING_X( startX ),
    STARTING_Y( startY )
{
    sprite = new Sprite( renderer->LoadTexture( SPRITE_PATH ), HUSKY_WIDTH, HUSKY_HEIGHT );
    destination.h = HUSKY_HEIGHT; 
    destination.w = HUSKY_WIDTH;
    destination.x = STARTING_X;
    destination.y = STARTING_Y;
}


Husky_Graphics::~Husky_Graphics()
{
}

void Husky_Graphics::Update( Component_Game_Actor& husky, SDL_Rect camera, const float timeStep )
{
    destination.x -= camera.x;
    destination.y -= camera.y;
}
