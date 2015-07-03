#pragma once
#include "Weapon.h"

#define FIRE_SINGLE          true
#define FIRE_AMMO            100
#define FIRE_DAMAGE          30
#define FIRE_DIST            500 
#define FIRE_RATE            60
#define FIRE_BULLET_SPEED    1100
#define FIRE_SPLASH_R        10
#define FIRE_SPLASH_D        30

#define FIRE_SPRITE_X    32
#define FIRE_SPRITE_Y    0
#define FIRE_SPRITE_W    32
#define FIRE_SPRITE_H    32

#define FIRE_NAME "Hot Sauce"

//HOT SAUCE: fire continuous flames from the front until expiration
class Fire : public Weapon 
{
public:
    Fire() : Weapon( FIRE_SINGLE, FIRE_AMMO, FIRE_DAMAGE, FIRE_DIST, FIRE_RATE, FIRE_SPLASH_R, FIRE_SPLASH_D ) {
        bulletClip.x = FIRE_SPRITE_X;
        bulletClip.y = FIRE_SPRITE_Y;
        bulletClip.w = FIRE_SPRITE_W;
        bulletClip.h = FIRE_SPRITE_H;
    }
};