#pragma once
#include "Component_Graphics.h"
#include "Component_Physics.h"
#include "Component_Input.h"
#include "Game_Weapons.h"

enum Actor_States {
    ACTOR_LEFT,
    ACTOR_RIGHT,
    ACTOR_CLIMB,
    ACTOR_JUMP,
    ACTOR_STAND
};

//Interface for all the characters in the game, from the protagonist to the bosses
class Component_Game_Actor
{
public:
	virtual ~Component_Game_Actor() {}
	virtual void Damage( int damage ) = 0;  //Subtract from the character's health
	virtual void Heal( int heal ) = 0;	//Add to the character's health
    virtual int GetHealth() = 0;//Returns the character's health
    virtual int GetLives() = 0;
    virtual void AddLife() = 0;
    virtual void SubLife() = 0;
    virtual int GetHeight() = 0;
    virtual int GetWidth() = 0;
    virtual void SetState( Actor_States newState ) = 0;
    virtual Actor_States GetState() = 0;
    virtual Component_Graphics* GetGraphics() = 0;
    virtual Component_Input*    GetInput()    = 0;
    virtual Component_Physics*  GetPhysics()  = 0;
    virtual Game_Weapons*       GetWeapon()   = 0;
};

