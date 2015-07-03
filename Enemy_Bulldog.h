#pragma once
#include "Abstract_Game_Actor.h"

#define MAX_BULLDOG_LIVES  1
#define BULLDOG_INIT_LIVES 1
#define BULLDOG_MAX_HEALTH 1000
#define BULLDOG_HEIGHT     192
#define BULLDOG_WIDTH      192

class Enemy_Bulldog : public Abstract_Game_Actor
{
public:
    /*=====================================================
    *Constructor: setup components and AI

    *Parameters:
        renderer: for passing to components for rendering and testing
        startX: where the enemy will spawn
    =======================================================*/
    Enemy_Bulldog( Game_Renderer* renderer, int startX, int startY );
    ~Enemy_Bulldog();
};

