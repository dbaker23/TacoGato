#pragma once
#include "Component_Physics.h"
#include "Game_Collision.h"
//Abstraction for physics interface
class Abstract_Actor_Physics : public Component_Physics
{
public:
    /*=====================================================
    *Move: move taco a certain amount in screen using the 
        forumla: xVelocity * timeStep

    *Parameters: 
        windowHeight: the y resolution of the game's window
        windowWidth: the x resolution of the game's window
        startX: starting x coordinate of the character
        startY: starting y coordinate of the character
        maxSpeed: max x-velocity
        maxClimb: max climbing velocity
        maxFall: max free-fall velocity
        maxAccel: max x-acceleration
        maxDecel: max x-deceleration
        maxJAccel: max jump acceleration
        maxJAdd: max jump increment
        maxJHeight: max jump height
    =======================================================*/
    Abstract_Actor_Physics( int windowHeight, int windowWidth, int startX, int startY, int actorWidth, int actorHeight,
                            float maxSpeed, float maxClimb, float maxFall, float maxAccel, 
                            float maxDecel, float maxJAccel, float maxJAdd, float maxJHeight );
    ~Abstract_Actor_Physics() {}

    /*=====================================================
    *Move: move taco a certain amount in screen using the 
        forumla: xVelocity * timeStep

    *Parameters: 
        actor: the hero, enemy, or boss that will use this move function
        map: the current map to test if certain tiles are passable
        timeStep: the amount of time it took to render 1 frame, used for movement
    =======================================================*/
    virtual void Move( Component_Game_Actor& actor, Map &map, float timeStep ) = 0;

    /*=====================================================
    *DecelX: slow the x movement speed

    *Parameters: 
    =======================================================*/
    virtual void DecelX();

    /*=====================================================
    *DecelY: decelerate according the the decelerations rate

    *Parameters: 
    =======================================================*/
    virtual void DecelY();

    /*=====================================================
    *SetXVelocity: depeding on corresponding keypresses,
        add or subtract to the velocity

    *Parameters: 
        xVel: Tells if the cat is moving left or right
    =======================================================*/
    virtual void SetXVelocity( bool xVel );

    /*=====================================================
    *SetYVelocity: Used for climbing ladders and inclines and stuff,
        negative is moving up and positive is moving down due to how
        graphing is taken care of in SDL, use Jump() for jumping

    *Parameters: 
        yVel: Says if the cat is moving up or down
    =======================================================*/
    virtual void SetYVelocity( bool yVel );

    /*=====================================================
    *Jump: climb until max height and fall until hitting something

    *Parameters: 
        actor: the hero, enemy, or boss that will use this move function
        map: the current map to test if certain tiles are passable
        timeStep: the amount of time it took to render 1 frame, used for movement
    =======================================================*/
    virtual void Jump( Component_Game_Actor& actor, float timeStep );

    /*=====================================================
    *Fall: fall down until hitting something or dying, use MAX_FALL

    *Parameters: 
        actor: the hero, enemy, or boss that will use this move function
        timeStep: the amount of time it took to render 1 frame, used for movement
    =======================================================*/
    virtual void Fall( Component_Game_Actor& actor, float timeStep );

    //Getters and Setters
    virtual void    StopX()     { xVelocity = 0; }
    virtual void    StopY()     { yVelocity = 0; }
    virtual float   GetXPos()   { return tempNewX; }
    virtual float   GetYPos()   { return tempNewY; }
    virtual int     GetXTile()  { return xTile; }
    virtual int     GetYTile()  { return yTile; }
    virtual float   GetXVel()   { return xVelocity; }
    virtual float   GetYVel()   { return yVelocity; }

protected:
    float    xVelocity;      //x and y current velocities
    float    yVelocity;
    float    tempNewX;       //Temporary holdings for the new x and y positions after updates
    float    tempNewY;
    float    xPos;           //Decimal point accurate on-screen positions
    float    yPos;
    int      xTile;          //Current 32x32 tile the dodger is on
    int      yTile;
    int      jumpTotal;      //The total amount of jump, test against max jump height to see if character needs to fall
    SDL_Rect actorBox;       //The destination of the actor for testing where it is on-screen

    //Constants for movement
    const int   SCREEN_HEIGHT;      //game's y resolution
    const int   SCREEN_WIDTH;       //Game's x resolution
    const float MAX_SPEED;          //max x-movement of the character
    const float MAX_CLIMB;          //max y movement of the character (climbing ladders and stuff)
    const float MAX_FALL;           //max free-fall gravity for the character
    const float MAX_ACCEL;          //max acceleration for x-movement
    const float MAX_DECEL;          //max deceleration for x-movement
    const float MAX_JUMP_ACCEL;     //max jump acceleration
    const float MAX_JUMP_INC;       //max jump increment, these add up to jump height
    const float MAX_JUMP_HEIGHT;    //max height of the jump, when attained the character falls until hitting something or dying
};

