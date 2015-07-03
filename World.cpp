#include "World.h"


World::World( Game_Renderer* gRenderer )
{   
    renderer = gRenderer;
    map   = new Level_1( gRenderer );
    level = LEVEL_1;
}


World::~World()
{
}

void World::DrawBackground()
{
	map->DrawBackground();
}

void World::SwitchLevel( Game_Renderer* gRenderer )
{
    switch( level ) {
    case LEVEL_1:
        level = LEVEL_2;
        map   = new Level_2( gRenderer );
        break;
    case LEVEL_2:
        level = LEVEL_3;
        map   = new Level_3( gRenderer );
        break;
    case LEVEL_3:
        level = LEVEL_4;
        map   = new Level_4( gRenderer );
        break;
    default:
        level = LEVEL_1;
        map   = new Level_1( gRenderer );
    }
}