#include "Shiba_AI.h"
#include "Abstract_Game_Actor.h"

#define TIME_PLUS 50.0f
#define TIME_MAX  20

Shiba_AI::Shiba_AI()
{
    timeUp = 0;
    timeDown = 0;
}


Shiba_AI::~Shiba_AI()
{
}

void Shiba_AI::Update( Component_Game_Actor& shiba, float timeStep )
{
    if( timeUp < TIME_MAX && timeDown >= 0 ) {
        timeUp += TIME_PLUS * timeStep;
        timeDown = timeUp;
    } else { 
        if( timeDown <= 0 ) {
            timeDown = 0;
            timeUp = 0;
        } else {
            timeDown -= TIME_PLUS * timeStep;
        }
    }

    if( timeUp >= 0.0f && timeUp < TIME_MAX )
        shiba.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
    else if( timeUp >= TIME_MAX )
        shiba.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
}