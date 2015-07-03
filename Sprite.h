#pragma once
#include "Game_Renderer.h"

#define DEFAULT_NUM 100

//Individual sprites with all information held within their objects
class Sprite
{
public:
    /*=====================================================
    *Default Constructor: For unknown sprites

    *Parameters: 
    =======================================================*/
    Sprite();

    /*=====================================================
    *Constructor: Sprite is the entire spritesheet

    *Parameters: 
        spriteSheet: the png where the sprite is located
        spriteWidth: width of each individual frame
        spriteHeight: height of each individual frame
    =======================================================*/
    Sprite( SDL_Texture* spriteSheet, const int spriteWidth, const int spriteHeight );

    /*=====================================================
    *Constructor: Sprite is the entire spritesheet

    *Parameters: 
        spriteSheet: the png where the sprite is located
        spriteWidth: width of each individual frame
        spriteHeight: height of each individual frame
        x/y: the x and y coordinates on the spritesheet where
             the certain sprite is located 
    =======================================================*/
    Sprite( SDL_Texture* spriteSheet, const int spriteWidth, const int spriteHeight, const int x, const int y );
    ~Sprite();

                //Getters/setters
    SDL_Texture* GetTexture() const     { return sprite; }
    SDL_Rect&    GetClip()              { return clip; }
    const int    GetSpriteWidth()       { return spriteWidth; }
    const int    GetSpriteHeight()      { return spriteHeight; }

private:
    const int    spriteHeight;     //height of the sprite
    const int    spriteWidth;      //Width of the sprite
    SDL_Texture* sprite;           //Sprite's texture for rendering
    SDL_Rect     clip;             //Clip in the sprite sheet
};