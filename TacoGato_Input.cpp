#include "TacoGato_Input.h"
#include "Taco_Gato.h"

#include <iostream>
using namespace std;

TacoGato_Input::TacoGato_Input()
{
}


TacoGato_Input::~TacoGato_Input()
{
}

void TacoGato_Input::Update( Component_Game_Actor& taco, float timeStep )
{
    //move left
    if( keys[ left ] || keys[ a ] ) {
        taco.SetState( ACTOR_LEFT );
        taco.GetPhysics()->SetXVelocity( NEGATIVE_MOVEMENT );
    }
    //Move Right
    if( keys[ right ] || keys[ d ] ) {
        taco.SetState( ACTOR_RIGHT );
        taco.GetPhysics()->SetXVelocity( POSITIVE_MOVEMENT );
    }
    //Climb ladder
 /*   if( keys[ up ] || keys[ w ] ) {
        taco.SetState( ACTOR_CLIMB );
        taco.GetPhysics()->StopX();
        taco.GetPhysics()->SetYVelocity( NEGATIVE_MOVEMENT ); 
    }*/
    //Descend ladder
    if( keys[ down ] || keys[ s ] ) {
        taco.SetState( ACTOR_CLIMB );
        taco.GetPhysics()->StopX();
        taco.GetPhysics()->SetYVelocity( POSITIVE_MOVEMENT );
    }
    //Jump
    if( keys[ spaceBar ] || keys[ up ] ) {
        taco.SetState( ACTOR_JUMP );
        taco.GetPhysics()->Jump( taco, timeStep );
    }

    //Change weapon to revolver
    if( keys[ n1 ] ){
        taco.GetWeapon()->SetWeapon( Game_Weapons::Weapon_List::REVOLVER );
    }
    else if( keys[ n2 ] ) {
        taco.GetWeapon()->SetWeapon( Game_Weapons::Weapon_List::SHOTGUN );
    }
    else if( keys[ n3 ] ) {
        taco.GetWeapon()->SetWeapon( Game_Weapons::Weapon_List::UZI );
    }
    else if( keys[ n4 ] ) {
        taco.GetWeapon()->SetWeapon( Game_Weapons::Weapon_List::BAZOOKA );
    }

    //Fire
    if( mouseLeft || keys[ ctrl ] ) {
        taco.GetWeapon()->FireWeapon( taco, timeStep );
    }
    if( !keys[ left ] && !keys[ a ] && !keys[ right ] && !keys[ d ] ) {
        taco.GetPhysics()->DecelX();
    }
    if( !keys[ up ] && !keys[ w ] && !keys[ down ] && !keys[ s ] ) {
        if( taco.GetState() == ACTOR_CLIMB )
            taco.GetPhysics()->StopY();
    }
    if( !keys[ spaceBar ] && !keys[ up ] && !keys[ w ] && !keys[ down ] && !keys[ s ] ) {
        /*if( taco.GetState() != ACTOR_CLIMB || taco.GetState() ! )
            taco.GetPhysics()->Fall( taco, timeStep ); */
    }

    
    //If nothing pressed, clear all input
    if( !keys[ left ] && 
        !keys[ a ] && 
        !keys[ right ] && 
        !keys[ d ] && 
        !keys[ spaceBar ] && 
        !keys[ up ] && 
        !keys[ w ] &&
        !keys[ down ] &&
        !keys[ s ] &&
        !keys[ ctrl ] ) {
        keys.clear();
    } 
}