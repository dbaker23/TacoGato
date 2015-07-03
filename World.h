#pragma once
#include "Map.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Level_4.h"

//For rendering each of the levels and handling which level is displayed.
class World
{
public:
    enum Map_Level {
        LEVEL_1,
        LEVEL_2,
        LEVEL_3,
        LEVEL_4
    };

    /*=====================================================
    *Constructor: resize( width ) resizes the first dimension
        of the array to the capacity of the width, and the for
        loop resizes each of the width elements to the capacity
        of the height

    *Parameters:
        renderer: used to create a pointer to this object, used 
            to render the backgrounds and objects of the map
    =======================================================*/
    World( Game_Renderer* gRenderer );
    ~World();

    void DrawBackground();    
    void DrawObjects();
    void SwitchLevel( Game_Renderer* gRenderer );

    //Getters
    Map* GetMap() { return map; }

private:
    Game_Renderer* renderer;    //used to draw stuff to the screen
    Map*           map;         //point to the level being used
    Map_Level      level;       //easy enum for fining what level is next and such.
};

