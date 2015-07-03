#pragma once
#include "Weapon.h"

#define BOMB_SINGLE          true
#define BOMB_AMMO            1
#define BOMB_DAMAGE          200
#define BOMB_DIST            500 
#define BOMB_RATE            60
#define BOMB_BULLET_SPEED    1100
#define BOMB_SPLASH_R        10
#define BOMB_SPLASH_D        30

#define BOMB_SPRITE_X    32
#define BOMB_SPRITE_Y    0
#define BOMB_SPRITE_W    32
#define BOMB_SPRITE_H    32

#define BOMB_NAME "Tequila Bomb"

//TEQUILA BOMB: molotov-like, hurts enemies in a radius
class Bomb : public Weapon 
{
public:
    Bomb() : Weapon( BOMB_SINGLE, BOMB_AMMO, BOMB_DAMAGE, BOMB_DIST, BOMB_RATE, BOMB_SPLASH_R, BOMB_SPLASH_D ) {
        bulletClip.x = BOMB_SPRITE_X;
        bulletClip.y = BOMB_SPRITE_Y;
        bulletClip.w = BOMB_SPRITE_W;
        bulletClip.h = BOMB_SPRITE_H;
    }
};