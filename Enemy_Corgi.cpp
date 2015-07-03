#include "Enemy_Corgi.h"
#include "Corgi_Graphics.h"
#include "Corgi_Physics.h"
#include "Corgi_AI.h"

Enemy_Corgi::Enemy_Corgi( Game_Renderer* renderer, int startX, int startY ) : Abstract_Game_Actor( CORGI_MAX_HEALTH, CORGI_WIDTH, CORGI_HEIGHT, MAX_CORGI_LIVES, CORGI_INIT_LIVES )
{
    eState      = ACTOR_STAND;
    graphics    = new Corgi_Graphics( renderer, startX, startY ); 
    physics     = new Corgi_Physics( renderer, *this );
    input       = new Corgi_AI();
    weapon      = new Game_Weapons( renderer );
}

Enemy_Corgi::~Enemy_Corgi()
{
    delete graphics;
    delete physics;
    delete input;

    graphics = NULL;
    physics = NULL;
    input = NULL;
}