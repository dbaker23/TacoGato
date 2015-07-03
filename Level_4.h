#pragma once
#include "Map.h"

class Game_Renderer;

class Level_4 : public Map
{
public:
    /*=====================================================
    *Constructor: Set the dimensions of the map and setup the
        background, foreground, and object vectors

    *Parameters:
    =======================================================*/
    Level_4( Game_Renderer* renderer );
    ~Level_4();
};

