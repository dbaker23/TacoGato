#include "Abstract_Actor_Graphics.h"

//Set pointers to the only rendering object used throughout the whole project
Abstract_Actor_Graphics::Abstract_Actor_Graphics( Game_Renderer* gRenderer )
{
    renderer = gRenderer;
}

Abstract_Actor_Graphics::~Abstract_Actor_Graphics()
{
}

void Abstract_Actor_Graphics::Draw()
{
	//Draw the character from get texture at &destination with the dimensions of getclip()
    renderer->DrawScreen( sprite->GetTexture(), &destination, &sprite->GetClip() );
}