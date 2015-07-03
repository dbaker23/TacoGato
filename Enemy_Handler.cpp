#include "Enemy_Handler.h"


Enemy_Handler::Enemy_Handler()
{
}


Enemy_Handler::~Enemy_Handler()
{
    //Delete all of the data before clearing 
    for( int i = 0; i < enemies.size(); i++ )
        delete enemies[ i ];
    enemies.clear();
}

void Enemy_Handler::LoadEnemies( Game_Renderer* renderer, Map& map )
{
        //Delete all of the data before clearing 
    for( int i = 0; i < enemies.size(); i++ )
        delete enemies[ i ];
    enemies.clear();

    for( int y = 0; y < map.GetMapTileHeight(); y++ ) {
        for( int x = 0; x < map.GetMapTileWidth(); x++ ) {
            switch( map.GetEnemy( x, y ) )
            {
            case Map::NONE:
                break;
            case Map::CORGI:
                enemies.push_back( new Enemy_Corgi( renderer, map.GetTileDest( x, y ).x, map.GetTileDest( x, y ).y - 64 ) );
                break;
            case Map::GREYHOUND:
                enemies.push_back( new Enemy_GreyHound( renderer, map.GetTileDest( x, y ).x, map.GetTileDest( x, y ).y - 64 ) );
                break;
            case Map::HUSKY:
                enemies.push_back( new Enemy_Husky( renderer, map.GetTileDest( x, y ).x, map.GetTileDest( x, y ).y - 64 ) );
                break;
            case Map::SHIBA:
                enemies.push_back( new Enemy_Shiba( renderer, map.GetTileDest( x, y ).x, map.GetTileDest( x, y ).y - 64 ) );
                break;
            case Map::BULLDOG:
                enemies.push_back( new Enemy_Bulldog( renderer, map.GetTileDest( x, y ).x, map.GetTileDest( x, y ).y - 64 ) );
                break;
            }
        }
    }
}

//
//Update enemy shit beyond this point
//
void Enemy_Handler::UpdateAI( SDL_Rect camera, float timeStep ) 
{
	for( int i = 0; i < enemies.size(); i++ ) {
        if( enemies[ i ]->GetGraphics()->GetDestination().x > 0 && enemies[ i ]->GetGraphics()->GetDestination().x + enemies[ i ]->GetWidth() < camera.x + camera.w ) 
		    enemies[ i ]->GetInput()->Update( *enemies[ i ], timeStep );
	}
}

void Enemy_Handler::UpdatePhysics( float timeStep, Map &map )
{
	for( int i = 0; i < enemies.size(); i++ ) {
        enemies[ i ]->GetPhysics()->Move( *enemies[ i ], map, timeStep );
	}
}

void Enemy_Handler::UpdateGraphics( SDL_Rect camera, float timeStep )
{
   	for( int i = 0; i < enemies.size(); i++ ) {
        if( enemies[ i ]->GetGraphics()->GetDestination().x > 0 && enemies[ i ]->GetGraphics()->GetDestination().x < camera.x + camera.w ) 
		    enemies[ i ]->GetGraphics()->Update( *enemies[ i ], camera, timeStep );
	}
}

void Enemy_Handler::DrawEnemies( SDL_Rect camera )
{
  	for( int i = 0; i < enemies.size(); i++ ) {
        if( enemies[ i ]->GetGraphics()->GetDestination().x > 0 && enemies[ i ]->GetGraphics()->GetDestination().x < camera.x + camera.w ) 
            enemies[ i ]->GetGraphics()->Draw();
	}
}