#pragma once
#include "Abstract_Game_Actor.h"

#define MAX_GREYHOUND_LIVES  1
#define GREYHOUND_INIT_LIVES 1
#define GREYHOUND_MAX_HEALTH 200
#define GREYHOUND_HEIGHT     96
#define GREYHOUND_WIDTH      96

class Enemy_GreyHound : public Abstract_Game_Actor
{
public:
    /*=====================================================
    *Constructor: setup components and AI

    *Parameters:
        renderer: for passing to components for rendering and testing
        startX: where the enemy will spawn
    =======================================================*/
    Enemy_GreyHound( Game_Renderer* renderer, int startX, int startY );
    ~Enemy_GreyHound();
};

