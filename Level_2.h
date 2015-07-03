#pragma once
#include "Map.h"

class Game_Renderer;

class Level_2  : public Map
{
public:
    /*=====================================================
    *Constructor: Set the dimensions of the map and setup the
        background, foreground, and object vectors

    *Parameters:
    =======================================================*/
    Level_2( Game_Renderer* renderer );

    ~Level_2();
};

