#pragma once
#include "Abstract_Game_Actor.h"

#define MAX_SHIBA_LIVES  1
#define SHIBA_INIT_LIVES 1
#define SHIBA_MAX_HEALTH 100
#define SHIBA_HEIGHT     96
#define SHIBA_WIDTH      96

class Enemy_Shiba : public Abstract_Game_Actor
{
public:
    /*=====================================================
    *Constructor: setup components and AI

    *Parameters:
        renderer: for passing to components for rendering and testing
        startX: where the enemy will spawn
    =======================================================*/
    Enemy_Shiba( Game_Renderer* renderer, int startX, int startY );
    ~Enemy_Shiba();
};

