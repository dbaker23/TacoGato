#include "Abstract_Actor_Physics.h"
#include "Component_Game_actor.h"
#include "Game_Collision.h"

#include <iostream>
using namespace std;

Abstract_Actor_Physics::Abstract_Actor_Physics( int windowHeight, int windowWidth, int startX, int startY, int actorWidth, int actorHeight,
                                                float maxSpeed, float maxClimb, float maxFall, float maxAccel, 
                                                float maxDecel, float maxJAccel, float maxJAdd, float maxJHeight  ) : 
        SCREEN_HEIGHT( windowHeight ),
        SCREEN_WIDTH( windowWidth ),
        MAX_SPEED( maxSpeed ),          //max x-movement of the character
        MAX_CLIMB( maxClimb ),          //max y movement of the character (climbing ladders and stuff)
        MAX_FALL( maxFall ),           //max free-fall gravity for the character
        MAX_ACCEL( maxAccel ),          //max acceleration for x-movement
        MAX_DECEL( maxDecel ),         //max deceleration for x-movement
        MAX_JUMP_ACCEL( maxJAccel ),     //max jump acceleration
        MAX_JUMP_INC( maxJAdd ),       //max jump increment, these add up to jump height
        MAX_JUMP_HEIGHT( maxJHeight )    //max height of the jump, when attained the character falls until hitting something or dying
{
            jumpTotal  = 0;
            xVelocity  = 0;
            yVelocity  = 0;
            tempNewX   = startX;
            tempNewY   = startY;
            actorBox.x = startX;
            actorBox.y = startY;
            actorBox.w = actorWidth;
            actorBox.h = actorHeight;
}

void Abstract_Actor_Physics::DecelX()
{
    //Decelerate right
    if( xVelocity > 0 ) 
    {
        if( xVelocity != 0 && !( xVelocity - MAX_DECEL < 0 ) )
            xVelocity -= MAX_DECEL;
        else
            xVelocity = 0;
    }
    //Decelerate left
    else
    {
        if( xVelocity != 0 && !( xVelocity + MAX_DECEL > 0 ) )
            xVelocity += MAX_DECEL;
        else
            xVelocity = 0;
    }
}

void Abstract_Actor_Physics::DecelY()
{
    yVelocity = MAX_FALL;
}

void Abstract_Actor_Physics::SetXVelocity( bool xVel )
{
    	//Find out if the player is moving left or right on the screen
	//Positive movement is right
    if( xVel == POSITIVE_MOVEMENT )
    {
		//check if not max velocity, if not, increase by the acceleration rate
        if( xVelocity < MAX_SPEED )
            xVelocity += MAX_ACCEL;
		//If max V, then set to max V
        else
            xVelocity = MAX_SPEED;
    }
	//Negative movement is left
    else
    {
        if( xVelocity > -MAX_SPEED )
            xVelocity -= MAX_ACCEL;
        else
            xVelocity = -MAX_SPEED;
    }
}

void Abstract_Actor_Physics::SetYVelocity( bool yVel )
{
    //climbing up
    if( yVel == POSITIVE_MOVEMENT )
    {
        yVelocity = MAX_CLIMB;
    }
    //Climbing down
    else
    {
        yVelocity = -MAX_CLIMB;
    }
}

void Abstract_Actor_Physics::Jump( Component_Game_Actor& actor, float timeStep )
{
  //  cout << jumpTotal << endl;
    //If jump hasn't reached its apex
    if( jumpTotal != MAX_JUMP_HEIGHT && jumpTotal < MAX_JUMP_HEIGHT )
    {
        jumpTotal += MAX_JUMP_INC * timeStep;
        yVelocity = -MAX_JUMP_ACCEL;
    }
}

void Abstract_Actor_Physics::Fall( Component_Game_Actor& actor, float timeStep )
{
    yVelocity = MAX_FALL;
}