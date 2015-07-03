#pragma once
#include "Game_Renderer.h"
#include "Map.h"

#define TILE_SIZE         32
#define NEGATIVE_MOVEMENT true
#define POSITIVE_MOVEMENT false

class Component_Game_Actor;

//Interface for all movement stuff
class Component_Physics
{
public:
    virtual ~Component_Physics() {}
    virtual void Move( Component_Game_Actor& actor, Map &map, float timeStep ) = 0;	//Update the character's position
    virtual void SetXVelocity( bool xVel ) = 0;								//Set the x velocity of the object
    virtual void SetYVelocity( bool yVel ) = 0;
    virtual void DecelX() = 0;										//Decrease the velocity
    virtual void DecelY() = 0;
    virtual void StopX() = 0;                                               //Auto set the velocities to 0
    virtual void StopY() = 0;
    virtual float GetXPos() = 0;											//Return the x or y position of the object
    virtual float GetYPos() = 0;
    virtual float GetXVel() = 0;
    virtual float GetYVel() = 0;
    virtual int GetXTile() = 0;
    virtual int GetYTile() =0;
    virtual void Jump( Component_Game_Actor& actor, float timeStep ) = 0;        //climb the y until max jump and fall until hitting something
    virtual void Fall( Component_Game_Actor& actor, float timeStep ) = 0;        //Fall until hitting something
};


