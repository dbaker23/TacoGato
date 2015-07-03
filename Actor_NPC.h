#pragma once
#include "Abstract_game_actor.h"

#define MAX_NPC_HEALTH 1

//Abstract implementation for all non-playable characters
class Actor_NPC : public Abstract_Game_Actor
{
public:
    Actor_NPC();
	~Actor_NPC();
};

