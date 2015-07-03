#pragma once
#include "Weapon.h"

#define REVOLVER_SINGLE         false
#define REVOLVER_AMMO           9999
#define REVOLVER_DAMAGE         50
#define REVOLVER_DIST           600
#define REVOLVER_RATE           30
#define REVOLVER_BULLET_SPEED   500
#define REVOLVER_SPLASH_R       0
#define REVOLVER_SPLASH_D       0

#define REVOLVER_SPRITE_W 32
#define REVOLVER_SPRITE_H 32
#define REVOLVER_SPRITE_X 0
#define REVOLVER_SPRITE_Y 0

#define REVOLVER_NAME "Tequito Revolver"

//TEQUITO REVOLVER: slow shooting, low-damage, but unlimited ammo
class Revolver : public Weapon
{
public:
    Revolver() : Weapon( REVOLVER_SINGLE, REVOLVER_AMMO, REVOLVER_DAMAGE, REVOLVER_DIST, REVOLVER_RATE, REVOLVER_SPLASH_R, REVOLVER_SPLASH_D ) {
        bulletClip.x = REVOLVER_SPRITE_X;
        bulletClip.y = REVOLVER_SPRITE_Y;
        bulletClip.w = REVOLVER_SPRITE_W;
        bulletClip.h = REVOLVER_SPRITE_H;
    }
};