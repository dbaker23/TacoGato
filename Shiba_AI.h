#pragma once
#include "Abstract_Actor_Input.h"

class Shiba_AI : public Abstract_Actor_Input
{
public:
    Shiba_AI();
    ~Shiba_AI();

    /*=====================================================
    *Update: depending on the keystrokes and behaviors, relay
        specific information to the other components: 
        physics, graphics

    *Parameters: 
        shiba: the hero cat, used to update it's components
        timeStep: amount of time used in rendering 1 frame
    =======================================================*/
    virtual void Update( Component_Game_Actor& shiba, float timeStep );

private:
    float timeUp; //time how long it moves in one direction.
    float timeDown; //time countdown
};

