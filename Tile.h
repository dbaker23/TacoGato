#pragma once
#include <SDL_image.h>
#define TILE_SIZE    32 //32 x 32 tiles
#define IS_PASSABLE  true
#define NOT_PASSABLE false

#include <iostream>
using namespace std;

//The objects that make up The background, foreground, and middle ground for all static things
class Tile
{
public:
    //Default constructor DO NOT USE
    Tile() { cout << "DEFAULT TILE CONSTRUCTOR USED, DO NOT USE" << endl; }

    /*=====================================================
    *Constructor: Setup the tile, the x/y position of it on-screen,
        if it's solid or just a background, the texture, and where the
        x and y coordinates are on the sprite sheet

    *Parameters:
        x/y: on-screen
        passable: if the characters can run over it or not
        tileSprite: the spritesheet where the tile is located
    =======================================================*/
    Tile( int x, int y, bool passable, bool isLadder, int newEnemy, int spriteX, int spriteY ) {
        destination.x = x;
        destination.y = y;
        destination.w = TILE_SIZE;
        destination.h = TILE_SIZE;

		clip.h = TILE_SIZE;
		clip.w = TILE_SIZE;
		clip.x = spriteX;
		clip.y = spriteY;

        collision = passable;
        ladder    = isLadder;
        enemy     = newEnemy;
    }

    ~Tile() { 
    }

    //Getters
    SDL_Rect    GetDestination()    { return destination; } 
	SDL_Rect	GetClip()			{ return clip; }
    bool        GetCollision()      { return collision; }
    bool        GetIsLadder()       { return ladder; }
    int         GetEnemy()          { return enemy; } //Check if theres an enemy to spawn at this tile

    //Setters
    void SetDestX( int x ) { destination.x = x; }
    void SetDestY( int y ) { destination.y = y; }

private: 
    int         enemy;         //if there is an enemy on the tile.
    SDL_Rect    destination;   //Where the tile is;
	SDL_Rect    clip;			 //The tile in the spritesheet's clip
    bool        collision;     //If the cat can walk over the tile or not
    bool        ladder;       //if the cat can climb up or down this tile
};

