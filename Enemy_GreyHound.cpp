#include "Enemy_GreyHound.h"
#include "GreyHound_AI.h"
#include "GreyHound_Graphics.h"
#include "GreyHound_Physics.h"


Enemy_GreyHound::Enemy_GreyHound( Game_Renderer* renderer, int startX, int startY ) : Abstract_Game_Actor( GREYHOUND_MAX_HEALTH, GREYHOUND_WIDTH, GREYHOUND_HEIGHT, MAX_GREYHOUND_LIVES, GREYHOUND_INIT_LIVES )
{
    eState = ACTOR_STAND;
    graphics    = new GreyHound_Graphics( renderer, startX, startY ); 
    physics     = new GreyHound_Physics( renderer, *this );
    input       = new GreyHound_AI();
    weapon      = new Game_Weapons( renderer );
}


Enemy_GreyHound::~Enemy_GreyHound()
{
    delete graphics;
    delete physics;
    delete input;

    graphics = NULL;
    physics = NULL;
    input = NULL;
}
