#pragma once
#include <SDL_pixels.h>
#include <SDL_timer.h>

//For all time-based movement and animations, acts like a stopwatch
class Game_Timer
{
public:
    Game_Timer();
    ~Game_Timer();

    void Start();
    void Stop();
    void Pause();
    void Unpause();

    /*=====================================================
    *GetTicks: Gets the timer's time

    *Parameters:
    =======================================================*/
    Uint32 GetTicks();

    bool IsStarted() { return mStarted; }
    bool IsPaused()  { return mPaused && mStarted; }

private:
    Uint32  mStartTicks;    //Time when the timer started
    Uint32  mPausedTicks;   //Time when timer was paused
    bool    mPaused;        //Status for pause
    bool    mStarted;       //Status for start
};
