#pragma once
#include <SDL.h>
#include "Taco_Gato.h"
#include "Game_Renderer.h"
#include "Game_Timer.h"
#include "Enemy_Handler.h"
#include "World.h"

//Where the game loop happens: logic, updating, drawing
class Main_Loop
{
public:
    /*=====================================================
    *Constructor: Create objects and allocate pointers before entering the main loop

    *Parameters:
    =======================================================*/
    Main_Loop();
    ~Main_Loop();

    /*=====================================================
    *Game_Loop: logic, updating, and drawing will happen until the user quits

    *Parameters: 
    =======================================================*/
    void GameLoop();

    /*=====================================================
    *Run: interaction between both game states will happen

    *Parameters: 
    =======================================================*/
    void Run();

private:
    bool           quit;        //Game runs until quitting
    float          timeStep;    //Frame-independent movement
    int            character;   //which character will spawn
    Enemy_Handler  enemies;     //Updating enemies and such
    Taco_Gato*     tacoGato;    //Hero of the game, the taco cat!
    Game_Renderer* renderer;    //Updates the screen
    Game_Timer     stepTimer;   //used for movement and anything involving time
    SDL_Event      gameEvent;	//SDL tracks things happening in the system, and this tracks it
    World*         world;
};

