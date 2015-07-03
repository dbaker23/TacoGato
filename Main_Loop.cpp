#include "Main_Loop.h"

Main_Loop::Main_Loop()
{
    quit        = false;
    timeStep    = 0.0f;
    renderer    = new Game_Renderer();
    tacoGato    = new Taco_Gato( renderer );
    world       = new World( renderer );
}


Main_Loop::~Main_Loop()
{
    delete tacoGato;
    delete renderer;
    delete world;
    world = NULL;
    renderer = NULL;
    tacoGato = NULL;

    IMG_Quit();
    SDL_Quit();
}

void Main_Loop::Run()
{
    GameLoop();
}

void Main_Loop::GameLoop()
{
    enemies.LoadEnemies( renderer, *world->GetMap() );

    //loop until quitting
    bool gameQuit = false;
    stepTimer.Start();

    while( !gameQuit )
    {
        //Clear the screen first
        renderer->ClearScreen();

        //==============================
        // Taking input for updating 
        //==============================
		//Loop until the pipeline of events is empty
        while( SDL_PollEvent( &gameEvent ) != 0 ) 
        {
            switch( gameEvent.type ) 
            {
            case SDL_QUIT:
                gameQuit = true;
                break;

            case SDL_MOUSEBUTTONDOWN:
                tacoGato->GetInput()->HandleInput( gameEvent );
                break;

            case SDL_MOUSEBUTTONUP:
                tacoGato->GetInput()->HandleInput( gameEvent );
                break;

				//If a key was pressed
            case SDL_KEYDOWN:
                if( gameEvent.key.keysym.sym == SDLK_ESCAPE ) {     //quit game
                    gameQuit = true;
                    break; 
                }
                else                                               //Get input
                    tacoGato->GetInput()->HandleInput( gameEvent );
                    break;

            

				//If it a key was let go
            case SDL_KEYUP:
                tacoGato->GetInput()->HandleInput( gameEvent );
                break;            
            }
        }

		//use time for any animations or movement, so every machine will play the same rather than depnding on Frames per second
        timeStep = stepTimer.GetTicks() / 1000.0f;
        //Make sure the timestep is not so insignificant
        if( timeStep < 0.001f )
            timeStep = 0.01f;

        //==============================
        // Update the Game
        //==============================        

        //Update taco's inputs
        tacoGato->GetInput()->Update( *tacoGato, timeStep );
        enemies.UpdateAI( world->GetMap()->GetCamera(), timeStep );

        //Update the cat's position
        tacoGato->GetPhysics()->Move( *tacoGato, *world->GetMap(), timeStep );
        enemies.UpdatePhysics( timeStep, *world->GetMap() );

        //Update the camera
        world->GetMap()->UpdateCamera( *tacoGato, timeStep );

        //Update the graphics
        tacoGato->GetGraphics()->Update( *tacoGato, world->GetMap()->GetCamera(), timeStep );
        enemies.UpdateGraphics( world->GetMap()->GetCamera(), timeStep );

        //Update the bullets
        tacoGato->GetWeapon()->UpdateBullets( timeStep, *world->GetMap() );
        tacoGato->GetWeapon()->TestCollision( enemies );        

        //Update if next level
        if( world->GetMap()->CheckLevelEnd( *tacoGato ) ) {
            delete tacoGato;
            tacoGato = NULL;
            tacoGato = new Taco_Gato( renderer );
            world->SwitchLevel( renderer );
            enemies.LoadEnemies( renderer, *world->GetMap() );
        }

		//restart the step timer to ensure the same time is used in all calculations, so the Frames per second indirectly affect the game
        stepTimer.Start();

        //==============================
        // Drawing the next frame
        //==============================
        world->DrawBackground();
        tacoGato->GetGraphics()->Draw();
        tacoGato->GetWeapon()->DrawBullets( world->GetMap()->GetCamera() );
        enemies.DrawEnemies( world->GetMap()->GetCamera() );
        renderer->UpdateScreen();
    }
    //Stop game stuff
    renderer->ClearScreen();
}