#pragma once
#include "Weapon.h"

#define UZI_SINGLE          false
#define UZI_AMMO            300
#define UZI_DAMAGE          25
#define UZI_DIST            600
#define UZI_RATE            5
#define UZI_BULLET_SPEED    800

#define UZI_SPLASH_R        0
#define UZI_SPLASH_D        0

#define UZI_SPRITE_X    64
#define UZI_SPRITE_Y    0
#define UZI_SPRITE_W    32
#define UZI_SPRITE_H    32

#define UZI_NAME "Enchilada Uzi"

//ENCHILADA UZI: rapid-fire Uzi with low damage but high DPS, longer range than revolver
class Uzi : public Weapon
{
public:
    Uzi() : Weapon( UZI_SINGLE, UZI_AMMO, UZI_DAMAGE, UZI_DIST, UZI_RATE, UZI_SPLASH_R, UZI_SPLASH_D ) {
        bulletClip.x = UZI_SPRITE_X;
        bulletClip.y = UZI_SPRITE_Y;
        bulletClip.w = UZI_SPRITE_W;
        bulletClip.h = UZI_SPRITE_H;
    }
};