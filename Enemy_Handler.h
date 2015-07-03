#pragma once
#include <SDL_image.h>
#include "Enemy_Corgi.h"
#include "Enemy_Bulldog.h"
#include "Enemy_Husky.h"
#include "Enemy_GreyHound.h"
#include "Enemy_Shiba.h"

class Enemy_Handler
{

public:
    Enemy_Handler();
    ~Enemy_Handler();

    	/*=====================================================
    *Update/draw: update and draw all the enemies in the array, or possibly
		only update the ones on screen if wanting to save space, change later.

    *Parameters:
        renderer: the graphics renderer used to show the background
                  sprites
    =======================================================*/
    void LoadEnemies( Game_Renderer* renderer, Map &map );
	void UpdateAI( SDL_Rect camera, float timeStep );
	void UpdatePhysics( float timeStep, Map &map );
	void UpdateGraphics( SDL_Rect camera, float timeStep );
	void DrawEnemies( SDL_Rect camera );
    void Delete( int i ) { delete enemies[ i ];  enemies[ i ] = NULL; enemies.erase( enemies.begin() + i ); }

    int                   GetEnemyVecSize() { return enemies.size(); }
    Component_Game_Actor* GetEnemy( int i ) { return enemies[ i ]; }

private:
    vector<Component_Game_Actor* > enemies;
    SDL_Texture* corgiSprites;
    SDL_Texture* greySprites;
    SDL_Texture* huskySprites;
    SDL_Texture* shibaSprites;
    SDL_Texture* bullSprites;
};

