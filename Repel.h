#pragma once
#include "Weapon.h"

#define REPEL_SINGLE          true
#define REPEL_AMMO            100
#define REPEL_DAMAGE          30
#define REPEL_DIST            500 
#define REPEL_RATE            60
#define REPEL_BULLET_SPEED    1100
#define REPEL_SPLASH_R        10
#define REPEL_SPLASH_D        30

#define REPEL_SPRITE_X    32
#define REPEL_SPRITE_Y    0
#define REPEL_SPRITE_W    32
#define REPEL_SPRITE_H    32

#define REPEL_NAME "Sardine Salsa"

//SARDINE SALSA: a repellant, keeps enemies a distance from you, how do i implement this shit?
class Repel : public Weapon 
{
public:
    Repel() : Weapon( REPEL_SINGLE, REPEL_AMMO, REPEL_DAMAGE, REPEL_DIST, REPEL_RATE, REPEL_SPLASH_R, REPEL_SPLASH_D ) {
        bulletClip.x = REPEL_SPRITE_X;
        bulletClip.y = REPEL_SPRITE_Y;
        bulletClip.w = REPEL_SPRITE_W;
        bulletClip.h = REPEL_SPRITE_H;
    }
};