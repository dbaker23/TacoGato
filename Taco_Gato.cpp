#include "Taco_Gato.h"
#include "TacoGato_Physics.h"
#include "TacoGato_Graphics.h"
#include "TacoGato_Input.h"

Taco_Gato::Taco_Gato( Game_Renderer* renderer ) : Abstract_Game_Actor( MAX_TACO_HEALTH, TACO_WIDTH, TACO_HEIGHT, MAX_TACO_LIVES, TACO_INIT_LIVES )
{
    graphics    = new TacoGato_Graphics( renderer );
    physics     = new TacoGato_Physics( renderer, *this );
    input       = new TacoGato_Input();
    eState      = ACTOR_RIGHT;
    weapon      = new Game_Weapons( renderer );
}

Taco_Gato::~Taco_Gato() 
{
    delete graphics;
    delete physics;
    delete input;

    graphics = NULL;
    physics = NULL;
    input = NULL;

}