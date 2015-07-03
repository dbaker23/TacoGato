#pragma once
#include "Abstract_Actor_Input.h"

class Husky_AI : public Abstract_Actor_Input
{
public:
    Husky_AI();
    ~Husky_AI();

    /*=====================================================
    *Update: depending on the keystrokes and behaviors, relay
        specific information to the other components: 
        physics, graphics

    *Parameters: 
        husky: the hero cat, used to update it's components
        timeStep: amount of time used in rendering 1 frame
    =======================================================*/
    virtual void Update( Component_Game_Actor& husky, float timeStep );
};

