#pragma once
#include "Abstract_Actor_Graphics.h"

#define SPRITE_PATH "Sprites/Bulldog.png"

class Bulldog_Graphics : public Abstract_Actor_Graphics
{
public:
    Bulldog_Graphics( Game_Renderer * renderer, int startX, int startY );
    ~Bulldog_Graphics();

    /*=====================================================
    *Update: Move the taco's sprite depending on which way it's moving,
        also update to the next frame of animation

    *Parameters:
        bulldog: the enemy using this graphics adapter
        timeStep: time it takes to render one frame
    =======================================================*/
    virtual void Update( Component_Game_Actor& bulldog, SDL_Rect camera, const float timeStep );

private:
    const int STARTING_X;
    const int STARTING_Y;
};

