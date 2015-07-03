#pragma once
#include "Component_Input.h"

class Component_Game_Actor;

//Abstraction of the interface
class Abstract_Actor_Input : public Component_Input
{
public:
    typedef unsigned int SDLK_t;    //Give proper representation of the keys

    Abstract_Actor_Input();
    ~Abstract_Actor_Input();

    /*=====================================================
    *HandleInput: Take in input and designate pressed keys

    *Parameters: 
            e: Player input event
    =======================================================*/
    virtual void HandleInput( const SDL_Event& e );

    //Overridden in child classes.
    virtual void Update( Component_Game_Actor& actor, float timeStep ) = 0;

protected: 
    std::map<int, bool>    keys;    //Handle multiple keypresses

    //user-defined inputs
    //Keyboard
    SDLK_t spaceBar;    //Point to what spacebar does
    SDLK_t tilde;       //Tilde
    SDLK_t left;        //directional keys
    SDLK_t right;
    SDLK_t up;
    SDLK_t down;
    SDLK_t ctrl;
    SDLK_t w;           //WASD keys
    SDLK_t a;
    SDLK_t s;
    SDLK_t d;
    SDLK_t n1;  //#1 - 4
    SDLK_t n2;
    SDLK_t n3;
    SDLK_t n4;

    //Moose
    bool mouseLeft;
};

