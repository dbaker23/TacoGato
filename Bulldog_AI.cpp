#include "Bulldog_AI.h"
#include "Component_Game_Actor.h"

Bulldog_AI::Bulldog_AI()
{
}


Bulldog_AI::~Bulldog_AI()
{
}

void Bulldog_AI::Update( Component_Game_Actor& bulldog, float timeStep )
{
    if( bulldog.GetPhysics()->GetXVel() == POSITIVE_MOVEMENT )
        bulldog.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
    else if( bulldog.GetPhysics()->GetXVel() == NEGATIVE_MOVEMENT )
        bulldog.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
    else
        bulldog.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
}