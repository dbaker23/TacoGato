#pragma once
#include "Abstract_Actor_Input.h"

//the "input" for the enemies
class Corgi_AI : public Abstract_Actor_Input
{
public:
    Corgi_AI();
    ~Corgi_AI();

    /*=====================================================
    *Update: depending on the keystrokes and behaviors, relay
        specific information to the other components: 
        physics, graphics

    *Parameters: 
        corgi: the hero cat, used to update it's components
        timeStep: amount of time used in rendering 1 frame
    =======================================================*/
    virtual void Update( Component_Game_Actor& corgi, float timeStep );
};

