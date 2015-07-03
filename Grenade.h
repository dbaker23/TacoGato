#pragma once
#include "Weapon.h"

#define GRENADE_SINGLE          true
#define GRENADE_AMMO            100
#define GRENADE_DAMAGE          300
#define GRENADE_DIST            500 
#define GRENADE_RATE            60
#define GRENADE_BULLET_SPEED    1100
#define GRENADE_SPLASH_R        10
#define GRENADE_SPLASH_D        30

#define GRENADE_SPRITE_X    32
#define GRENADE_SPRITE_Y    0
#define GRENADE_SPRITE_W    32
#define GRENADE_SPRITE_H    32

#define GRENADE_NAME "Guacamole Grenade"

//GUACAMOLE GRENADE: slows enemies, stronger enemies (bulldogs) don't take much effect
class Grenade : public Weapon 
{
public:
    Grenade() : Weapon( GRENADE_SINGLE, GRENADE_AMMO, GRENADE_DAMAGE, GRENADE_DIST, GRENADE_RATE, GRENADE_SPLASH_R, GRENADE_SPLASH_D ) {
        bulletClip.x = GRENADE_SPRITE_X;
        bulletClip.y = GRENADE_SPRITE_Y;
        bulletClip.w = GRENADE_SPRITE_W;
        bulletClip.h = GRENADE_SPRITE_H;
    }
};