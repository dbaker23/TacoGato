#include "Enemy_Bulldog.h"
#include "Bulldog_AI.h"
#include "Bulldog_Graphics.h"
#include "Bulldog_Physics.h"

Enemy_Bulldog::Enemy_Bulldog( Game_Renderer* renderer, int startX, int startY ) : Abstract_Game_Actor( BULLDOG_MAX_HEALTH, BULLDOG_WIDTH, BULLDOG_HEIGHT, MAX_BULLDOG_LIVES, BULLDOG_INIT_LIVES )
{
    eState      = ACTOR_STAND;
    graphics    = new Bulldog_Graphics( renderer, startX, startY ); 
    physics     = new Bulldog_Physics( renderer, *this );
    input       = new Bulldog_AI();
    weapon      = new Game_Weapons( renderer );
}


Enemy_Bulldog::~Enemy_Bulldog()
{
    delete graphics;
    delete physics;
    delete input;

    graphics = NULL;
    physics = NULL;
    input = NULL;
}
