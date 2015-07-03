#pragma once
#include "Component_Graphics.h"

class Abstract_Actor_Graphics : public Component_Graphics
{
public:
    
    /*=====================================================
    *Constructor: setup pointer to the renderer being used, 
        initialize destination for sprite

    *Parameters:
        gRenderer: renderer from main loop
    =======================================================*/
    Abstract_Actor_Graphics( Game_Renderer* gRenderer );
    ~Abstract_Actor_Graphics();

    //Overridden in children
    virtual void Update( Component_Game_Actor& character, SDL_Rect camera, const float timeStep ) = 0;

    /*=====================================================
    *Draw: Show each frame of animation

    *Parameters:
    =======================================================*/
    virtual void Draw();

    virtual void        SetDestinationX( int x ) { destination.x = x; }
    virtual void        SetDestinationY( int y ) { destination.y = y; }
    virtual SDL_Rect    GetDestination()         { return destination; }
   
protected:
    Game_Renderer* renderer;        //For drawing the sprite
    Sprite*        sprite;          //which sprite will be shown.
    SDL_Rect       destination;     //Where the sprite will be shown
};

