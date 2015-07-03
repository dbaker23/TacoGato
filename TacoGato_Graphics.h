#pragma once
#include "Abstract_Actor_Graphics.h"

#define TACO_STARTING_Y 0
#define TACO_STARTING_X 100
#define SPRITE_PATH "Sprites/TacoGato/TacoGato.png"

class Component_Game_Actor;

class TacoGato_Graphics : public Abstract_Actor_Graphics
{
public:
    TacoGato_Graphics( Game_Renderer* renderer );
    ~TacoGato_Graphics();

    /*=====================================================
    *Update: Move the taco's sprite depending on which way it's moving,
        also update to the next frame of animation

    *Parameters:
        
    =======================================================*/
    virtual void Update( Component_Game_Actor& taco, SDL_Rect camera, const float timeStep );
};

