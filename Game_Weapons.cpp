#include "Game_Weapons.h"
#include "Component_Game_Actor.h"
#include "Weapon.h"
#include "Enemy_Handler.h"
#include "Game_Collision.h"

Game_Weapons::Game_Weapons( Game_Renderer* gRenderer )
{
    renderer = gRenderer;
    currentW = &revolver;//object
    weapon   = REVOLVER;//enum value
}

Game_Weapons::~Game_Weapons()
{
    delete currentW;
    currentW = NULL;
    bullets.clear();
}

void Game_Weapons::SetWeapon( Weapon_List newWeapon )
{
    weapon = newWeapon;
    switch( weapon )
    {
    case REVOLVER:
        currentW = &revolver;
        break;
    case SHOTGUN:
        currentW = &shotgun;
        break;
    case UZI:
        currentW = &uzi;
        break;
    case BAZOOKA:
        currentW = &bazooka;
        break;
    default:
        break;
    }
}

void Game_Weapons::FireWeapon( Component_Game_Actor& actor, float timeStep )
{
    if( actor.GetState() == ACTOR_LEFT || actor.GetState() == ACTOR_RIGHT )
        facing = actor.GetState();

    //Check if the weapon is reloading
    if( currentW->GetReload() <= 0 ) 
    {
        currentW->ResetReload();

        switch( facing )
        {
        //Shoot the bullet left
        case ACTOR_LEFT:
            switch( weapon )
            {
            case REVOLVER:            
                bullets.push_back( new Bullet( -REVOLVER_BULLET_SPEED, REVOLVER_DIST, actor.GetGraphics()->GetDestination().x, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, REVOLVER_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            case SHOTGUN:
                bullets.push_back( new Bullet( -SHOTGUN_BULLET_SPEED, SHOTGUN_DIST, actor.GetGraphics()->GetDestination().x, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, SHOTGUN_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            case UZI:
                bullets.push_back( new Bullet( -UZI_BULLET_SPEED, UZI_DIST, actor.GetGraphics()->GetDestination().x, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, UZI_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            case BAZOOKA:
                bullets.push_back( new Bullet( -BAZOOKA_BULLET_SPEED, BAZOOKA_DIST, actor.GetGraphics()->GetDestination().x, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, BAZOOKA_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            } 
            break;
        //Shoot the bullet right
        case ACTOR_RIGHT:
            switch( weapon )
            {
            case REVOLVER:
                bullets.push_back( new Bullet( REVOLVER_BULLET_SPEED, REVOLVER_DIST, actor.GetGraphics()->GetDestination().x + actor.GetGraphics()->GetDestination().w, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, REVOLVER_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            case SHOTGUN:
                bullets.push_back( new Bullet( SHOTGUN_BULLET_SPEED, SHOTGUN_DIST, actor.GetGraphics()->GetDestination().x + actor.GetGraphics()->GetDestination().w, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, SHOTGUN_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            case UZI:
                bullets.push_back( new Bullet( UZI_BULLET_SPEED, UZI_DIST, actor.GetGraphics()->GetDestination().x + actor.GetGraphics()->GetDestination().w, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, UZI_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            case BAZOOKA:
                bullets.push_back( new Bullet( BAZOOKA_BULLET_SPEED, BAZOOKA_DIST, actor.GetGraphics()->GetDestination().x + actor.GetGraphics()->GetDestination().w, actor.GetGraphics()->GetDestination().y + actor.GetHeight() / 3, BAZOOKA_DAMAGE, currentW->GetBulletClip(), renderer->LoadTexture( BULLETS_PATH ) ) );
                currentW->SetAmmo( -1 );
                break;
            }  
        }
    }
}

void Game_Weapons::UpdateBullets( float timeStep, Map &map )
{
    //time in between bullets = timeStep * firerate
    currentW->SubtractReload( timeStep );
    
    for( int i = 0; i < bullets.size(); i++ ){
        //Check if the bullets gone it's length
        if( bullets[ i ]->GetDistance() <= 0 ) {
            //Delete the element at x
            delete bullets[ i ];
            bullets[ i ] = NULL;
            bullets.erase( bullets.begin() + i );
        } else {
            //count how far the bullet has travelled
            bullets[ i ]->SubtractDistance( timeStep );

            //Calculate the bullet's next position
            bullets[ i ]->SetDestinationX( (int)( bullets[ i ]->GetDestination().x + ( bullets[ i ]->GetVelocity() * timeStep ) ) );
            //Check if the next tile it's in is a collision, if it is, delete bullet
            if( bullets[ i ]->GetDestination().x < 0 ) {
                delete bullets[ i ];
                bullets[ i ] = NULL;
                bullets.erase( bullets.begin() + i );
            } 
        }
    }
}

void Game_Weapons::TestCollision( Enemy_Handler &enemies )
{
    //Run through all the bullets and enemies and see if anything is hit, if so delete it.
    for( int i = 0; i < bullets.size(); i++ ) {
        for( int x = 0; x < enemies.GetEnemyVecSize(); x++ ) {
            if( Game_Collision::CheckCollisionBox( bullets[ i ]->GetDestination(), enemies.GetEnemy( x )->GetGraphics()->GetDestination() ) ) {
                enemies.GetEnemy( x )->Damage( bullets[ i ]->GetDamage() );
                if( enemies.GetEnemy( x )->GetHealth() <= 0 )
                    enemies.Delete( x );
                delete bullets[ i ];
                bullets[ i ] = NULL;
                bullets.erase( bullets.begin() + i );
                break;
            }
        }
    }
}

void Game_Weapons::DrawBullets( SDL_Rect camera )
{
    for( int i = 0; i < bullets.size(); i++ ) {
        renderer->DrawScreen( bullets[ i ]->GetSprite().GetTexture(), &bullets[ i ]->GetDestination(), &bullets[ i ]->GetSprite().GetClip() );
    }
}