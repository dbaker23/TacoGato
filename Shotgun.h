#pragma once
#include "Weapon.h"

#define SHOTGUN_SINGLE          false
#define SHOTGUN_AMMO            100
#define SHOTGUN_DAMAGE          200
#define SHOTGUN_DIST            500 
#define SHOTGUN_RATE            60
#define SHOTGUN_BULLET_SPEED    1200
#define SHOTGUN_SPLASH_R        10
#define SHOTGUN_SPLASH_D        30

#define SHOTGUN_SPRITE_X    32
#define SHOTGUN_SPRITE_Y    0
#define SHOTGUN_SPRITE_W    32
#define SHOTGUN_SPRITE_H    32

#define SHOTGUN_NAME "Tamale Shotgun"

//TAMALE SHOTGUN: burst damage over a small distance with some splash, medium effect
class Shotgun : public Weapon 
{
public:
    Shotgun() : Weapon( SHOTGUN_SINGLE, SHOTGUN_AMMO, SHOTGUN_DAMAGE, SHOTGUN_DIST, SHOTGUN_RATE, SHOTGUN_SPLASH_R, SHOTGUN_SPLASH_D ) {
        bulletClip.x = SHOTGUN_SPRITE_X;
        bulletClip.y = SHOTGUN_SPRITE_Y;
        bulletClip.w = SHOTGUN_SPRITE_W;
        bulletClip.h = SHOTGUN_SPRITE_H;
    }
};