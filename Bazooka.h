#pragma once
#include "Weapon.h"

#define BAZOOKA_SINGLE          false
#define BAZOOKA_AMMO            5
#define BAZOOKA_DAMAGE          500
#define BAZOOKA_DIST            1000
#define BAZOOKA_RATE            100
#define BAZOOKA_BULLET_SPEED    950
#define BAZOOKA_SPLASH_R        50
#define BAZOOKA_SPLASH_D        100

#define BAZOOKA_SPRITE_X    96
#define BAZOOKA_SPRITE_Y    0
#define BAZOOKA_SPRITE_W    32
#define BAZOOKA_SPRITE_H    32

#define BAZOOKA_NAME "Burrito Bazooka"

//BURRITO BAZOOKA: one-shot kill, long reload, entire-screen's distance
class Bazooka : public Weapon
{
public:
    Bazooka() : Weapon( BAZOOKA_SINGLE, BAZOOKA_AMMO, BAZOOKA_DAMAGE, BAZOOKA_DIST, BAZOOKA_RATE, BAZOOKA_SPLASH_R, BAZOOKA_SPLASH_D ) {
        bulletClip.x = BAZOOKA_SPRITE_X;
        bulletClip.y = BAZOOKA_SPRITE_Y;
        bulletClip.w = BAZOOKA_SPRITE_W;
        bulletClip.h = BAZOOKA_SPRITE_H;
    }
};