#include "Game_Renderer.h"

//Default
Game_Renderer::Game_Renderer() : Game_Window()
{
    // Initialize image loading for PNGs
    int imgFlags = IMG_INIT_PNG;
    IMG_Init( imgFlags );

    //Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}

    //Setup Renderer
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( renderer == NULL )
    {
        printf( "Renderer not created, Error: %s\n", SDL_GetError() );
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

//overloaded
Game_Renderer::Game_Renderer( const int screenHeight, const int screenWidth, const int windowFlags, const int rendererFlags ) :
    Game_Window( screenHeight, screenWidth, windowFlags )
{
    // Initialize image loading for PNGS
    int imgFlags = IMG_INIT_PNG;
    IMG_Init( imgFlags );

    //Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}

    //Setup Renderer
    renderer = SDL_CreateRenderer( window, -1, rendererFlags );
    if( renderer == NULL )
    {
        printf( "Renderer not created, Error: %s\n", SDL_GetError() );
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

//Destructor
Game_Renderer::~Game_Renderer() 
{
    SDL_DestroyRenderer( renderer );
    renderer = NULL;
}


// Load up and return certain textures
SDL_Texture* Game_Renderer::LoadTexture( const char* imgPath )
{
    // Final texture
    SDL_Texture* newTexture = NULL;

    // Load image
    SDL_Surface* loadedSurface = IMG_Load( imgPath );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_Image Error: %s\n", imgPath, IMG_GetError() );
    }
    // Create texture
    else
    {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture, SDL Error: %s\n", imgPath, SDL_GetError() );
        }

        // Get rid of old texture
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

//Load up a picture of text
SDL_Texture* Game_Renderer::LoadTTFTexture( std::string text, SDL_Color textColor, TTF_Font* font )
{
    SDL_Surface* surface = TTF_RenderText_Solid( font, text.c_str(), textColor );
	if( surface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

    else
    {
        SDL_Texture* texture;
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( renderer, surface );

      	if( texture == NULL )
	    {
		    printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
	    }
		
        //Make sure no reference to unallocated memory
        if( surface != NULL )
        {
            SDL_FreeSurface( surface );
            surface = NULL;
        }

        return texture;
    }

    return NULL;
}

// Clear Screen
void Game_Renderer::ClearScreen()
{
    SDL_RenderClear( renderer );
}


// Render texture
void Game_Renderer::DrawScreen( SDL_Texture* texture, SDL_Rect* destination, SDL_Rect* clip )
{
    SDL_RenderCopy( renderer, texture, clip, destination );
}


// Update screen
void Game_Renderer::UpdateScreen()
{
    SDL_RenderPresent( renderer );
}