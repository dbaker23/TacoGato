#pragma once
#include "Tile.h"
#include "Sprite.h"
#include <string>
#include <algorithm>
#include <sstream>
#include "Game_Renderer.h"
#include "tinyxml\tinyxml.h"
#include <xtgmath.h>
#include <vector>
using namespace std;

class Component_Game_Actor;

//Base class for all the different levels
class Map
{
public:
    //eNUM FOR reading in the enemies
    enum Game_Enemies {
        NONE        = 0,
        CORGI       = 1,
        GREYHOUND   = 2,
        HUSKY       = 3,
        SHIBA       = 4,
        BULLDOG     = 5
    };
    /*=====================================================
    *Constructor: resize( width ) resizes the first dimension
        of the array to the capacity of the width, and the for
        loop resizes each of the width elements to the capacity
        of the height

    *Parameters:
		gRenderer: drawing to the screen and loading textures
		spriteSheetPath: the spritesheet path
        cameraX/Y: starting position of the x and y of the camera
    =======================================================*/
    Map( Game_Renderer* gRenderer, char* spriteSheetPath, int cameraX, int cameraY )
    {
		renderer = gRenderer;
		mapTexture = renderer->LoadTexture( spriteSheetPath );
        camera.x = cameraX;
        camera.y = cameraY;
        camera.w = renderer->GetScreenWidth();
        camera.h = renderer->GetScreenHeight();
        drawingRect.w = TILE_SIZE;
        drawingRect.h = TILE_SIZE;
        drawingRect.x = camera.x;
        drawingRect.y = camera.y;
    }
    ~Map() {
        backTiles.clear();
        backTiles.shrink_to_fit();

        mapTexture = NULL;
    }

    /*=====================================================
    *DrawBackground: Everything that the characters can walk over
        and in front of is drawn on this layer. 

    *Parameters:
        renderer: the graphics renderer used to show the background
                  sprites
    =======================================================*/
    void DrawBackground() {
        for( int y = camera.y / TILE_SIZE; y < mapHeight; y++ ) {
            //Check if the y tile is within the camera bounds
            //if( y * TILE_SIZE >= camera.y && y * TILE_SIZE <= camera.y + camera.h ) {
                for( int x = camera.x / TILE_SIZE; x < mapWidth; x++ ) {
                    //Check if the x is in the camera bounds
                    //if( x * TILE_SIZE >= camera.x - TILE_SIZE && x * TILE_SIZE <= camera.x + camera.w ) {
                    drawingRect.x = ( x * TILE_SIZE ) - camera.x;
                    drawingRect.y = ( y * TILE_SIZE ) - camera.y;
                    renderer->DrawScreen( mapTexture, &drawingRect, &backTiles[ y ][ x ]->GetClip() );
                }
            //}
        }
    }

   // virtual void DrawTest( Game_Renderer &renderer ) {
     //   for( int i = 0; i < MAP_WIDTH; i++ ) {
         //   renderer.DrawScreen( backTiles[ 14 ][ i ]->GetSprite()->GetTexture(), &backTiles[ 14 ][ i ]->GetDestination(), &backTiles[ 14 ][ i ]->GetSprite()->GetClip() );
       // }
      //  renderer.DrawScreen( backTiles[ 3 ][ 20 ]->GetSprite()->GetTexture(), &backTiles[ 3 ][ 20 ]->GetDestination(), &backTiles[ 3 ][ 20 ]->GetSprite()->GetClip() ) ;
    //}

    /*=====================================================
    *DrawForeground: Everything that the character walks behind on
        the screen gets drawn in this layer

    *Parameters:
        renderer: the graphics renderer used to show the background
                  sprites
    =======================================================*/
    void DrawForeground( Game_Renderer* renderer ) {
        for( int y = 0; y < mapWidth; y++ ) {
            for( int x = 0; x < mapHeight; x++ ) {
               // renderer->DrawScreen( foreTiles[ x ][ y ]->GetSprite()->GetTexture(), &foreTiles[ x ][ y ]->GetDestination(), &foreTiles[ x ][ y ]->GetSprite()->GetClip() );
            }
        }
    }

    /*=====================================================
    *UpdateCamera: depending on player movement, update camera left
        or right or up or down or whatever

    *Parameters:
        actor: the hero of the game, focused on him.
    =======================================================*/
    void UpdateCamera( Component_Game_Actor& actor, float timeStep );

    /*=====================================================
    *DrawObjects: anything that the characters can interact with
        "powerups" and ammo barrels and shit go in this layer.

        not implemented yet

    *Parameters:
        renderer: the graphics renderer used to show the background
                  sprites
    =======================================================*/
    //void DrawObjects( Game_Renderer* renderer );

    /*=====================================================
    *CreateMap: read in the map from a map file, and place the tiles into
		appropriate tiles

    *Parameters:
        
    =======================================================*/
	void CreateMap( vector<vector<Tile*> >& tiles, char* path, int numSpritesRow );

    /*=====================================================
    *CheckLevelEnd: check if the cat reached the end

    *Parameters:
        tacogato: the cat that's killing the doggies
    =======================================================*/
    bool CheckLevelEnd( Component_Game_Actor& taco );


    //Getters
    const int       GetMapWidth()                { return mapPixWidth; }
    const int       GetMapHeight()               { return mapPixHeight; }
    const int       GetMapTileHeight()           { return mapHeight; }
    const int       GetMapTileWidth()            { return mapWidth; }
    const bool      GetCollision( int x, int y ) { return backTiles[ y ][ x ]->GetCollision(); }
    const bool      GetLadder( int x, int y )    { return backTiles[ y ][ x ]->GetIsLadder(); }
    const int       GetEnemy( int x, int y )     { return backTiles[ y ][ x ]->GetEnemy(); }
   // const int       GetEnemy( int y )            { return enemies[ y ]; }
   // const int       GetEnemySize()               { return enemies.size(); }
    const SDL_Rect  GetTileDest( int x, int y )  { return backTiles[ y ][ x ]->GetDestination(); }
    const SDL_Rect  GetCamera()                  { return camera; }

private:
	SDL_Texture*    mapTexture;
    SDL_Rect        drawingRect; //Use this to draw to the screen with correct tile positioning
    SDL_Rect        camera;     //What's shown on the screen.
	Game_Renderer*	renderer;
    int             mapPixWidth;   //How many tiles are x
    int             mapPixHeight;  //How many tiles are y
    int             mapWidth;       // width and height in pixels
    int             mapHeight;

protected:
    vector<vector<Tile*> > backTiles;       //holds the level tiles that are static in the background and in the same z-order of the characters
                                            //An array of tiles representing the level
    //vector<int > enemies; //array of enemies in the level
    //vector<object*>        objects;    //a list of the objects in the level that can be interacted with (ammo barrels etc)
};

