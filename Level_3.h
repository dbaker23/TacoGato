#pragma once
#include "Map.h"

class Game_Renderer;

class Level_3: public Map
{
public:
    /*=====================================================
    *Constructor: Set the dimensions of the map and setup the
        background, foreground, and object vectors

    *Parameters:
    =======================================================*/
    Level_3( Game_Renderer* renderer );
    ~Level_3();
};

