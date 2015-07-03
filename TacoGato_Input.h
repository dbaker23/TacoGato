#pragma once
#include "Abstract_Actor_Input.h"

class TacoGato_Input : public Abstract_Actor_Input
{
public:
    TacoGato_Input();
    ~TacoGato_Input();

    /*=====================================================
    *Update: depending on the keystrokes and behaviors, relay
        specific information to the other components: 
        physics, graphics

    *Parameters: 
        taco: the hero cat, used to update it's components
        timeStep: amount of time used in rendering 1 frame
    =======================================================*/
    virtual void Update( Component_Game_Actor& taco, float timeStep );
};

