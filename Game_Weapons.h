#pragma once
#include <SDL_image.h>
#include "Bullet.h"
#include "Revolver.h"
#include "Shotgun.h"
#include "Bazooka.h"
#include "Uzi.h"
#include "Game_Renderer.h"
#include "Map.h"
#include <vector>
using std::vector;

#define BULLETS_PATH "Sprites/TacoGato/Bullets.png"

class Weapon;
class Component_Game_Actor;
class Enemy_Handler;
enum Actor_States;

//The abstract template for all the different weapons in the game, friend class to Enemy handler
class Game_Weapons
{
public:
    enum Weapon_List {
        REVOLVER,
        SHOTGUN,
        UZI,
        BAZOOKA
    };

    /*=====================================================
    *Constructor: setup memory for each of the weapons so they 
        retain their ammo and other stuff for the duration of play.

    *Parameters:
        renderer: loading up textures of bullets and guns and shit
    =======================================================*/
    Game_Weapons( Game_Renderer* gRenderer );
    ~Game_Weapons();

    /*=====================================================
    *FireWeapon: depending on the way the character is facing, left
        or right, create a bullet object and propel it on the x-axis
        until time expires

    *Parameters:
        actor: used for finding which way to fire the bullet, and 
            finding where they are on the map
    =======================================================*/
    void FireWeapon( Component_Game_Actor& actor, float timeStep );

    /*=====================================================
    *SetWeapon: set the enum to the new weapona and use the enum to
        set a pointer to the existing weapon object.

    *Parameters:
        newWeapon: the enum for the new weapon for faster swapping
    =======================================================*/
    void SetWeapon( Weapon_List newWeapon );

    /*=====================================================
    *UpdateBullets: go through the vector of bullets and update the
        positions, checking if there is a collision or not

    *Parameters:
        timeStep: amount of time it takes to render 1 frame, used for
            movement
        map: for testing if the bullets hit objects and unpassable tiles
    =======================================================*/
    void UpdateBullets( float timeStep, Map &map );

    /*=====================================================
    *TestCollision: test if the enemies are hit or not

    *Parameters:
        
    =======================================================*/
    void TestCollision( Enemy_Handler &enemies );

    /*=====================================================
    *DrawBullets: draw the bullets with updated positions

    *Parameters:
    =======================================================*/
    void DrawBullets( SDL_Rect camera );

private:
    int              facing;  //Which way the bullets will shoot in case of jumping and climbing bitchassmotherfucker             
    Weapon_List      weapon;  //Which weapon is equipped, for testing and fast swapping
    Weapon*          currentW;    //The weapon currently equipped
    Revolver         revolver;
    Shotgun          shotgun;
    Uzi              uzi;
    Bazooka          bazooka;
    vector<Bullet* > bullets;    //List of bullets that need updating
    Game_Renderer*   renderer;
};