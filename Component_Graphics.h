#pragma once
#include "Sprite.h"

class Component_Game_Actor;      //Forward declaration to prevent looping dependencies

//Base interface for every graphics component
class Component_Graphics
{
public:
    virtual ~Component_Graphics() {}
    virtual void Update( Component_Game_Actor& character, SDL_Rect camera, const float timeStep ) = 0;	//Update the current character's position
    virtual void Draw() = 0;															//Draw to the screen the updated sprite
    virtual void SetDestinationX( int x ) = 0;											//Set x position of the sprite
    virtual void SetDestinationY( int y ) = 0;											//set y position of the sprite
    virtual SDL_Rect GetDestination() = 0;												//Get the rectangle where the sprite is located
};

