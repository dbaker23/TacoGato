#pragma once
#include <SDL_image.h>
#include "Sprite.h"

class Bullet
{
public:
    /*=====================================================
    *Constructor: assign velocity to the bullet, along with its
        starting x/y coords and the width/height of the 

    *Parameters:
        v: velocity, how fast the bullet will travel
        d: distance the bullet can travel before being deleted.
        x/y: where the x and y coordinates of the bullet's origin will be
        c: clip of the sprite where the texture is on the sprite sheet
        t: texture, the sprite sheet
    =======================================================*/
    Bullet( float v, int d, int x, int y, int dmg, SDL_Rect c, SDL_Texture* t ) : 
        sprite( t, c.w, c.h, c.x, c.y )
    {
        distance = d;
        velocity = v;
        damage = dmg;
        destination.x = x;
        destination.y = y;
        destination.w = c.w;
        destination.h = c.h;
    }
    ~Bullet() { 
    }

    //Getters
    float        GetVelocity()    { return velocity; }
    SDL_Rect     GetDestination() { return destination; }
    Sprite       GetSprite()      { return sprite; }
    int          GetDistance()    { return distance; }
    int          GetDamage()      { return damage; }

    //Setters
    void SetDestinationX( int x )               { destination.x = x; }
    void SubtractDistance( float timeStep )     { 
        if( velocity > 0 )
            distance -= velocity * timeStep; 
        else 
            distance += velocity * timeStep; 
    }

private:
    float        velocity;
    int          damage;
    int          distance;      //Distance the bullet can travel before being deleted.
    SDL_Rect     destination; 
    Sprite       sprite;
};

