#include "Husky_AI.h"
#include "Component_Game_Actor.h"

Husky_AI::Husky_AI()
{
}


Husky_AI::~Husky_AI()
{
}

void Husky_AI::Update( Component_Game_Actor& husky, float timeStep )
{
    //randomize the husky
    int x = rand() % 30;    
     //run right
    if( x > 20 && husky.GetState() != ACTOR_JUMP ) {
        husky.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
    //run left
    } else if( x >= 10 && x < 20 && husky.GetState() != ACTOR_JUMP ) {
        husky.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
    // jump
    } else if( x >= 0 && x < 10 ) {
        husky.SetState( ACTOR_JUMP );
        husky.GetPhysics()->Jump( husky, timeStep );
    }
}
