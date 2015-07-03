#include "Game_Timer.h"


Game_Timer::Game_Timer()
{
    mStartTicks     = 0;
    mPausedTicks    = 0;
    mPaused         = false;
    mStarted        = false;
}


Game_Timer::~Game_Timer()
{
}

void Game_Timer::Start()
{
    mStarted = true;
    mPaused  = false;
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void Game_Timer::Stop()
{
    mStarted     = false;
    mPaused      = false;
    mStartTicks  = 0;
    mPausedTicks = 0;
}

void Game_Timer::Pause()
{
    if( mStarted && !mPaused )
    {
        mPaused      = true;
        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks  = 0;
    }
}

void Game_Timer::Unpause()
{
    if( mStarted && mPaused )
    {
        mPaused      = false;
        mStartTicks  = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

Uint32 Game_Timer::GetTicks()
{
    Uint32 time = 0;

    if( mStarted ){
        if( mPaused ) {
            time = mPausedTicks;
        } else {
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}