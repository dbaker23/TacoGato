#include "Bulldog_Physics.h"
#include "Enemy_Bulldog.h"
#include "Map.h"
#include "Game_Collision.h"

Bulldog_Physics::Bulldog_Physics( Game_Renderer* renderer, Component_Game_Actor& bulldog ) :
    Abstract_Actor_Physics( renderer->GetScreenHeight(), renderer->GetScreenWidth(), bulldog.GetGraphics()->GetDestination().x, bulldog.GetGraphics()->GetDestination().y, BULLDOG_WIDTH, BULLDOG_HEIGHT,
                            MAX_SPEED, MAX_CLIMB, MAX_FALL, MAX_ACCEL, MAX_DECEL, MAX_JUMP_ACCEL, MAX_JUMP_ADD, MAX_JUMP_HEIGHT )
{
}


Bulldog_Physics::~Bulldog_Physics()
{
}

void Bulldog_Physics::Move( Component_Game_Actor& actor, Map &map, float timeStep )
{        
    int previousx = tempNewX;
    int previousy = tempNewY;
    //Temporary holdings for the speeds
    tempNewX += (int)xVelocity * timeStep;
    tempNewY += (int)yVelocity * timeStep;    

    actorBox.x = tempNewX;
    actorBox.y = tempNewY;

    //moving right
    if( xVelocity > 0 )
    {
        //Check out of bounds right
        if( tempNewX + actorBox.w > map.GetMapWidth() ) {
            tempNewX = map.GetMapWidth() - actor.GetGraphics()->GetDestination().w;
            StopX();
            SetXVelocity( NEGATIVE_MOVEMENT );
        }
    }

    //moving left
    else if( xVelocity < 0 )
    {
        //Check out of bounds left
        if( tempNewX < 0 ) {           
            tempNewX = 0;
            StopX();
            SetXVelocity( POSITIVE_MOVEMENT );
        }
    }

    actor.GetGraphics()->SetDestinationX( tempNewX );
    actor.GetGraphics()->SetDestinationY( tempNewY );
}
