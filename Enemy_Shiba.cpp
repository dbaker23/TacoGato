#include "Enemy_Shiba.h"
#include "Shiba_Graphics.h"
#include "Shiba_AI.h"
#include "Shiba_Physics.h"

Enemy_Shiba::Enemy_Shiba( Game_Renderer* renderer, int startX, int startY ) : Abstract_Game_Actor( SHIBA_MAX_HEALTH, SHIBA_WIDTH, SHIBA_HEIGHT, MAX_SHIBA_LIVES, SHIBA_INIT_LIVES )
{
    eState      = ACTOR_STAND;
    graphics    = new Shiba_Graphics( renderer, startX, startY ); 
    physics     = new Shiba_Physics( renderer, *this );
    input       = new Shiba_AI();
    weapon      = new Game_Weapons( renderer );
}


Enemy_Shiba::~Enemy_Shiba()
{
    delete graphics;
    delete physics;
    delete input;

    graphics = NULL;
    physics = NULL;
    input = NULL;
}
