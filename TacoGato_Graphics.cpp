#include "TacoGato_Graphics.h"
#include "Component_Game_Actor.h"
#include "Taco_Gato.h"

TacoGato_Graphics::TacoGato_Graphics( Game_Renderer* renderer ) : Abstract_Actor_Graphics( renderer )
{
    //Testing shit
    sprite = new Sprite( renderer->LoadTexture( SPRITE_PATH ), 96, 96 );
    destination.h = TACO_HEIGHT;
    destination.w = TACO_HEIGHT;
    destination.x = TACO_STARTING_X;
    destination.y = TACO_STARTING_Y;
    //
}


TacoGato_Graphics::~TacoGato_Graphics()
{
}

void TacoGato_Graphics::Update( Component_Game_Actor& taco, SDL_Rect camera, const float timeStep )
{
    destination.x -= camera.x;
    destination.y -= camera.y;
}