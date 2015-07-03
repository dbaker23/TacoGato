#pragma once
#include "Abstract_Game_Actor.h"

#define MAX_TACO_HEALTH 100
#define MAX_TACO_LIVES  9
#define TACO_INIT_LIVES 3
#define TACO_WIDTH      80
#define TACO_HEIGHT     96

//Abstract implementation for all heroes
class Taco_Gato : public Abstract_Game_Actor
{
public:
    Taco_Gato( Game_Renderer* renderer );
	~Taco_Gato();
};

