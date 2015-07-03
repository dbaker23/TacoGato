#include "Corgi_AI.h"
#include "Component_Game_Actor.h"

Corgi_AI::Corgi_AI()
{
}


Corgi_AI::~Corgi_AI()
{
}

void Corgi_AI::Update( Component_Game_Actor& corgi, float timeStep )
{
    if( corgi.GetPhysics()->GetXVel() == POSITIVE_MOVEMENT )
        corgi.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
    else if( corgi.GetPhysics()->GetXVel() == NEGATIVE_MOVEMENT )
        corgi.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
    else
        corgi.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
}
