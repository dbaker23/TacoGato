#pragma once
#include "Game_Window.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>

//Where the actual updating of the window will take place, along with turning surfaces into textures for hardware acceleration
class Game_Renderer : public Game_Window
{
public:
    /*=====================================================
    *Default Constructor: Use deafult values for window size and window flags

    *Parameters: 
    =======================================================*/
    Game_Renderer();

    /*=====================================================
    *Overloaded Constructor: Use user-defined resolution and flags

    *Parameters: 
            screenHeight: window resolution height
            screenWidth: window resolution width
            windowFlags: window options for full screen and stuff
    =======================================================*/
    Game_Renderer( const int screenHeight, const int screenWidth, const int windowFlags, const int rendererFlags );

    //Destructor
    ~Game_Renderer();

    /*=====================================================
    *LoadTexture: returns a texture of passed-in image

    *Parameters: 
            imgPath: string defining where the image is located in file
    =======================================================*/
    SDL_Texture* LoadTexture( const char* imgPath );


    /*=====================================================
    *LoadTTFTexture: returns a texture of the written message

    *Parameters: 
        text: what will be written to the screen
        textColor: what color the text will be written as
        font: the font
    =======================================================*/
    SDL_Texture* LoadTTFTexture( std::string text, SDL_Color textColor, TTF_Font* font );

    /*=====================================================
    *ClearScreen: fill the screen with a default color before drawing

    *Parameters:
    =======================================================*/
    void ClearScreen();

    /*=====================================================
    *DrawScreen: Display texture at the destination rectangle using said clip of a spritesheet

    *Parameters:
            texture: Will be displayed
            destination: rectangle where the texture will be displayed (NULL if whole screen)
            clip: rectangle from sprite sheet that will be used (NULL if whole thing)
    =======================================================*/
    void DrawScreen( SDL_Texture* texture, SDL_Rect* destination, SDL_Rect* clip );

    /*=====================================================
    *UpdateScreen: Simply tells SDL to update the window

    *Parameters:
    =======================================================*/
    void UpdateScreen();

    SDL_Window*     GetWindow()     { return window; }		//Returns the window object holding dimensions and the window being updated
    SDL_Renderer*   GetRenderer()   { return renderer; }	//returns the renderer which uses the GPU to draw all things on the screen

private:
    SDL_Renderer* renderer;     //Renderer object for loading textures and displaying them
};
