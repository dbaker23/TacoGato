#include "GreyHound_AI.h"
#include "Component_Game_Actor.h"

GreyHound_AI::GreyHound_AI()
{
}


GreyHound_AI::~GreyHound_AI()
{
}

void GreyHound_AI::Update( Component_Game_Actor& hound, float timeStep )
{
    if( hound.GetState() == ACTOR_STAND )
        hound.GetPhysics()->Jump( hound, timeStep );
}
