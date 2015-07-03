#pragma once
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>
#include <map>

class Component_Game_Actor;      //Forward declaration to prevent looping dependencies

//class Component_Input: base interface for player input 
class Component_Input
{
public:
    virtual ~Component_Input() {}
    virtual void HandleInput( const SDL_Event& e ) = 0;		//Find out if the key is up or down
    virtual void Update( Component_Game_Actor& actor, float timeStep ) = 0;			//Depending on keys pressed, change the character's state to correspond and update movement if any
};