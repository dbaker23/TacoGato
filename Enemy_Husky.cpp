#include "Enemy_Husky.h"
#include "Husky_Graphics.h"
#include "Husky_AI.h"
#include "Husky_Physics.h"

Enemy_Husky::Enemy_Husky( Game_Renderer* renderer, int startX, int startY ) : Abstract_Game_Actor( HUSKY_MAX_HEALTH, HUSKY_WIDTH, HUSKY_HEIGHT, MAX_HUSKY_LIVES, HUSKY_INIT_LIVES )
{
	eState = ACTOR_STAND;
	graphics    = new Husky_Graphics( renderer, startX, startY ); 
    physics     = new Husky_Physics( renderer, *this );
    input       = new Husky_AI();
    weapon      = new Game_Weapons( renderer );
}

Enemy_Husky::~Enemy_Husky()
{
	delete graphics;
	delete physics;
	delete input;
	
	graphics = NULL;
	physics = NULL;
	input = NULL;
}