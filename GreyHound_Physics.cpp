#include "GreyHound_Physics.h"
#include "Enemy_GreyHound.h"
#include "Map.h"

GreyHound_Physics::GreyHound_Physics( Game_Renderer* renderer, Component_Game_Actor& greyHound ) :
    Abstract_Actor_Physics( renderer->GetScreenHeight(), renderer->GetScreenWidth(), greyHound.GetGraphics()->GetDestination().x, greyHound.GetGraphics()->GetDestination().y, GREYHOUND_WIDTH, GREYHOUND_HEIGHT,
                            MAX_SPEED, MAX_CLIMB, MAX_FALL, MAX_ACCEL, MAX_DECEL, MAX_JUMP_ACCEL, MAX_JUMP_ADD, MAX_JUMP_HEIGHT )
{
}


GreyHound_Physics::~GreyHound_Physics()
{
}

void GreyHound_Physics::Move( Component_Game_Actor& actor, Map &map, float timeStep )
{        
    int previousx = tempNewX;
    int previousy = tempNewY;
    //Temporary holdings for the speeds
    tempNewX += (int)xVelocity * timeStep;
    tempNewY += (int)yVelocity * timeStep;    

    actorBox.x = tempNewX;
    actorBox.y = tempNewY;

    //moving right
  /*  if( xVelocity > 0 )
    {
        //Check out of bounds right
        if( tempNewX + actorBox.w < map.GetMapWidth() ) {
            //Get the tile where the actor is
            xTile       = ( tempNewX + actorBox.w ) / TILE_SIZE;
            yTile       = tempNewY / TILE_SIZE;
            int midTile = ( tempNewY + ( actorBox.h / 2 ) ) / TILE_SIZE;
            //int botTile = ( tempNewY + actorBox.h - 1 ) / TILE_SIZE;
            //Check the tile just to the right
            if( map.GetCollision( xTile, yTile ) || map.GetCollision( xTile, midTile ) ) {
                //Check box collision for all tiles in front of the character.
                if( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, yTile ), actorBox ) ) {
                    actorBox.x = previousx;
                    tempNewX = previousx;
                } else if( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, midTile ), actorBox ) ) {
                    actorBox.x = previousx;
                    tempNewX = previousx;
                } /*else if( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, botTile ), actorBox ) ) {
                    actorBox.x = previousx;
                    tempNewX = previousx;
                } 
            }
            
        } else {
            tempNewX = map.GetMapWidth() - actor.GetGraphics()->GetDestination().w;
            StopX();
        }
    }

    //moving left
    else if( xVelocity < 0 )
    {
        //Check out of bounds left
        if( tempNewX > 0 ) {
            //Get the tile where the actor is
            xTile       = tempNewX / TILE_SIZE;
            yTile       = tempNewY / TILE_SIZE;
            int midTile = ( tempNewY + ( actorBox.h / 2 ) ) / TILE_SIZE;
            //int botTile = ( tempNewY + actorBox.h - 1) / TILE_SIZE;
            //Check the tile just to the right
            if( map.GetCollision( xTile, yTile ) || map.GetCollision( xTile, midTile ) ) {
                //Check box collision for all tiles in front of the character.a
                if( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, yTile ), actorBox ) ) {
                    actorBox.x = previousx;
                    tempNewX = previousx;
                } else if ( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, midTile ), actorBox ) ) {
                    actorBox.x = previousx;
                    tempNewX = previousx;
                }/* else if ( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, botTile ), actorBox ) ) {
                    actorBox.x = previousx;
                    tempNewX = previousx;
                }  
            }
        } else  {
            tempNewX = 0;
            StopX();
            }
    } */

    //Falling
   // if( yVelocity > 0 ) {
        //Check bounds bottom
        if( tempNewY + actor.GetGraphics()->GetDestination().h < SCREEN_HEIGHT ) {
            // left side of the sprite underneath
            yTile = ( tempNewY + actorBox.h ) / TILE_SIZE;
            xTile = tempNewX / TILE_SIZE;
            //middle underneath
            int midX   = ( tempNewX + ( actorBox.w / 2 ) ) / TILE_SIZE;
            // right side of the sprite underneath
            int rightX = ( tempNewX + actorBox.w ) / TILE_SIZE;
            //Check both undersides of the sprite to see if it should stop falling
            if( map.GetCollision( xTile, yTile ) || map.GetCollision( rightX, yTile ) || map.GetCollision( midX, yTile ) ) {
                if( Game_Collision::CheckCollisionBox( map.GetTileDest( xTile, yTile ), actorBox ) ) {
                        jumpTotal = 0;
                        tempNewY = map.GetTileDest( xTile, yTile ).y - actorBox.h;
                        actorBox.y = tempNewY;
                        StopY();
                } else if( Game_Collision::CheckCollisionBox( map.GetTileDest( rightX, yTile ), actorBox ) ) {
                        jumpTotal = 0;
                        tempNewY = map.GetTileDest( rightX, yTile ).y - actorBox.h;
                        actorBox.y = tempNewY;
                        StopY();
                } else if( Game_Collision::CheckCollisionBox( map.GetTileDest( midX, yTile ), actorBox ) ) {
                        jumpTotal = 0;
                        tempNewY = map.GetTileDest( midX, yTile ).y - actorBox.h;
                        actorBox.y = tempNewY;
                        StopY();
                }
            } else {
                yVelocity = MAX_FALL;
            }
        //Check bounds top
        } else if( tempNewY < 0 ) {
            tempNewY = 0;
            StopY();
        }
  //  }

    //Jumping up
    if( tempNewY < 0 ) {
        tempNewY = 0;

        StopY();
    }    

    if( jumpTotal == 0 )
        actor.SetState( ACTOR_STAND );
    actor.GetGraphics()->SetDestinationX( tempNewX );
    actor.GetGraphics()->SetDestinationY( tempNewY );
}
