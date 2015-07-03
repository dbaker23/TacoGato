#pragma once
#include "Abstract_Game_Actor.h"

#define MAX_CORGI_LIVES  1
#define CORGI_INIT_LIVES 1
#define CORGI_MAX_HEALTH 50
#define CORGI_HEIGHT     96
#define CORGI_WIDTH      96

//Abstract implementation for all enemies including bosses
class Enemy_Corgi : public Abstract_Game_Actor
{
public:
        /*=====================================================
    *Constructor: setup components and AI

    *Parameters:
        renderer: for passing to components for rendering and testing
        startX: where the enemy will spawn
    =======================================================*/
	Enemy_Corgi( Game_Renderer* renderer, int startX, int startY );
    ~Enemy_Corgi();
};

