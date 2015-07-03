#include "Game_Collision.h"

Game_Collision::Game_Collision()
{
}
Game_Collision::~Game_Collision()
{
}

bool Game_Collision::CheckCollisionBox( const SDL_Rect a, const SDL_Rect b )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int botA, botB;

    //Sides of rect A       sides of rect B
    leftA  = a.x;           leftB  = b.x;
    rightA = a.x + a.w;     rightB = b.x + b.w;
    topA   = a.y;           topB   = b.y;
    botA   = a.y + a.h;     botB   = b.y + b.h;

    //If any of the sides of A are outside of B
    if( botA <= topB )
        return false;
    if( topA >= botB )
        return false;
    if( rightA <= leftB )
        return false;
    if( leftA >= rightB )
        return false;

    return true;
}
