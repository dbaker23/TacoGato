#pragma once
#include "component_game_actor.h"

//Abstraction of base class game actor, implements nearly everything aside from setstate
class Abstract_Game_Actor : public Component_Game_Actor
{
public:
    Abstract_Game_Actor( int heal, int width, int height, int maxLives, int startLives ) :
		MAX_HEALTH( heal ),
        ACTOR_WIDTH( width ),
        ACTOR_HEIGHT( height ),
        MAX_LIVES( maxLives ) {
        health = MAX_HEALTH;
        lives  = startLives;
    }
	~Abstract_Game_Actor();

    //Does what they say stuff
    virtual void Damage( int damage ) { health -= damage; }//Subtract from the character's health
    virtual void Heal( int heal )     { health += heal; }  //Add to the character's health
    virtual void AddLife()            { lives++; }
    virtual void SubLife()            { lives--; }

    //Getters for the components of the character87
    virtual int                     GetHealth()         { return health; }
    virtual int                     GetHeight()         { return ACTOR_HEIGHT; }
    virtual int                     GetWidth()          { return ACTOR_WIDTH; }
    virtual Component_Graphics*     GetGraphics()       { return graphics; }
    virtual Component_Input*        GetInput()          { return input;}
    virtual Component_Physics*      GetPhysics()        { return physics; }
    virtual Game_Weapons*           GetWeapon()         { return weapon; }
    virtual Actor_States            GetState()          { return eState; }
    virtual int                     GetLives()          { return lives; }

    //Setters
    virtual void SetState( Actor_States newState ) { eState = newState; }    

private:
    int          health;      //Current health
    int          lives;       //How many lives the character has.
    SDL_Rect     destination; //Where the character is on screen
    const int    MAX_HEALTH;  //The maximum health for the character
    const int    ACTOR_WIDTH;   //static height and width of the actors
    const int    ACTOR_HEIGHT;
    const int    MAX_LIVES;     //Maximum lives the character can have.

protected:
    Actor_States            eState;      //eState = enum state, not the object
    Component_Graphics*     graphics;   //What the player sees, including animation
    Component_Physics*      physics;    //how the character moves across the screen, gravity and such
    Component_Input*        input;      //Either user input or AI built-in input for the enemies and NPCs
    Game_Weapons*           weapon;     //The current weapon that the character is holding
};

