#pragma once
#include "Abstract_Actor_Physics.h"

#define MAX_SPEED        200.0f //Max velocity
#define MAX_CLIMB        400.0f
#define MAX_FALL         1000.0f //Max falling speed.
#define MAX_ACCEL        200.0f  //Acceleration rate
#define MAX_DECEL        15.0f  //Deceleration rate
#define MAX_JUMP_ACCEL   800.0f
#define MAX_JUMP_ADD     100.0f   //this * timeStep until max jump height
#define MAX_JUMP_HEIGHT  15

class Bulldog_Physics : public Abstract_Actor_Physics
{
public:
    /*=====================================================
    *Constructor: set default values to velocities and temporary
        values

    *Parameters: 
        renderer: the game's renderer
        bulldog: the enemy, used just for getting the starting x and y positions
    =======================================================*/
    Bulldog_Physics( Game_Renderer* renderer, Component_Game_Actor& bulldog );
    ~Bulldog_Physics(void);

    /*=====================================================
    *Move: move taco a certain amount in screen using the 
        forumla: xVelocity * timeStep

    *Parameters: 
        actor: the hero, enemy, or boss that will use this move function
        map: the current map to test if certain tiles are passable
        timeStep: the amount of time it took to render 1 frame, used for movement
    =======================================================*/
    virtual void Move( Component_Game_Actor& actor, Map &map, float timeStep );
};

