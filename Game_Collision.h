#pragma once
#include <SDL.h>

class Game_Collision
{
public:
    Game_Collision();
    ~Game_Collision();

    /*=====================================================
    *CheckCollisionBox: check if character's sprite box overlaps
        with doge's sprite box

    *Parameters:
        a/b: the two objects being checked for collision
    =======================================================*/
    static bool CheckCollisionBox( const SDL_Rect a, const SDL_Rect b );
};

