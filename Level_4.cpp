#include "Level_4.h"
#include "Game_Renderer.h"

#define MAP_PATH        "Sprites/level_4.tmx"
#define LEVEL_1_TILESET "Sprites/Jungle_Terrain.png"
#define NUM_SPRITES_ROW 28
#define CAMERA_X        0
#define CAMERA_Y        0

Level_4::Level_4( Game_Renderer* renderer ) : Map( renderer, LEVEL_1_TILESET, CAMERA_X, CAMERA_Y )
{
	CreateMap( backTiles, MAP_PATH, NUM_SPRITES_ROW ); 
}


Level_4::~Level_4(void)
{
}
