#pragma once
#include "Abstract_Game_Actor.h"

#define MAX_HUSKY_LIVES  1
#define HUSKY_INIT_LIVES 1
#define HUSKY_MAX_HEALTH 250
#define HUSKY_HEIGHT     96
#define HUSKY_WIDTH      96

class Enemy_Husky : public Abstract_Game_Actor
{
public:
    /*=====================================================
    *Constructor: setup components and AI

    *Parameters:
        renderer: for passing to components for rendering and testing
        startX: where the enemy will spawn
    =======================================================*/
    Enemy_Husky( Game_Renderer* renderer, int startX, int startY );
    ~Enemy_Husky();
};

