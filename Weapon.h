#pragma once
#include <SDL_image.h>

//struct for all the weapons in the game
class Weapon
{
public:
    enum Weapon_State {
        WEAPON_STATE_ATTACK, //meaning it can fire
        WEAPON_STATE_RELOAD  //meaning it can't fire
    };
    Weapon( const bool isSingleUse, const int ammo, const int damage, const int distance, const int rate, const int splashR, const int splashD ) :
        SINGLE_USE( isSingleUse ),
        MAX_AMMO( ammo ),
        WEAPON_DAMAGE( damage ),    //the approximate damage of the weapon
        FIRE_DISTANCE( distance ),  //How far the weapon can attack
        FIRE_RATE( rate ),          
        SPLASH_RADIUS( splashR ),
        SPLASH_DAMAGE( splashD ){
            state = WEAPON_STATE_ATTACK;
            reload = 0;
    }     //If the weapon is melee or not

    ~Weapon() {}

    //Getters
    SDL_Rect GetBulletClip() { return bulletClip; }
    int      GetReload()     { return reload; }

    //setters
    void SetDestinationX( int x )         { destination.x = x; }
    void SetDestinationy( int y )         { destination.y = y; }
    void ResetReload()                    { reload = FIRE_RATE; }
    void SubtractReload( float timeStep ) { reload -= reload * timeStep; }

    //Set amount to negative if removing ammo
    void SetAmmo( int amount )    { ammo += amount; }

private:
    int        ammo;             //Amount of ammo in the gun
    int        reload;          //happens after every firing
    const bool SINGLE_USE;      //if the weapon will be retained after firing
    const int  MAX_AMMO;         //Max amount of ammo for the character
    const int  WEAPON_DAMAGE;    //the approximate damage of the weapon
    const int  FIRE_DISTANCE;  //How far the weapon can attack
    const int  FIRE_RATE;       //How fast the weapon fires
    const int  SPLASH_RADIUS;   //How far the radius for attack is
    const int  SPLASH_DAMAGE;   //how much damage is had from the splash radius

protected:
    Weapon_State state;
    SDL_Rect destination;
    SDL_Rect bulletClip;
};