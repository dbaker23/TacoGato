#include "Map.h"
#include "Component_Game_Actor.h"

#include <iostream>

//How far from the sides of the screen taco has to pass over for te camera to move
#define CAMERA_MARGIN 200
#define CAMERA_SPEED  500

void Map::CreateMap( vector<vector<Tile*> >& tiles, char* tmxFile, int numSpritesRow )
{
    //Clear out all the tiles
    backTiles.clear();
    backTiles.shrink_to_fit();

	// open the XML map file
	TiXmlDocument xmlFile( tmxFile );
	if(xmlFile.LoadFile()) {
		cout << "Successfully opened the XML map file.\n";
	} else {
		cout << "ERROR: Unable to open the XML map file.\n";
	}

	// parse the XML
	// this code assumes that the layers exist in the XML file in this order: sprites, then collision, then ladders.
	mapWidth = atoi(xmlFile.FirstChildElement("map")->Attribute("width"));
	mapHeight = atoi(xmlFile.FirstChildElement("map")->Attribute("height"));
	int tileSize = atoi(xmlFile.FirstChildElement("map")->Attribute("tilewidth"));
	string tileImageFilename = xmlFile.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("source");
	string spriteLayer = xmlFile.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();
	string collisionLayer = xmlFile.FirstChildElement("map")->FirstChildElement("layer")->NextSibling()->FirstChildElement("data")->GetText();
	string ladderLayer = xmlFile.FirstChildElement("map")->FirstChildElement("layer")->NextSibling()->NextSibling()->FirstChildElement("data")->GetText();
	string enemiesLayer = xmlFile.FirstChildElement("map")->FirstChildElement("layer")->NextSibling()->NextSibling()->NextSibling()->FirstChildElement("data")->GetText();

	// convert the CSV strings into vectors of ints
	// these ints are the sprite numbers for each tile. 0 would be the first sprite in the first row, etc.
	replace(spriteLayer.begin(), spriteLayer.end(), ',', ' '); // convert CSV to space-delimited
	stringstream a(spriteLayer);
	vector<int> spriteInts;
	string temp1;
	while(a >> temp1) {
		spriteInts.push_back(atoi(temp1.c_str()));
	}
	replace(collisionLayer.begin(), collisionLayer.end(), ',', ' '); // convert CSV to space-delimited
	stringstream b(collisionLayer);
	vector<int> collisionInts;
	string temp2;
	while(b >> temp2) {
		collisionInts.push_back(atoi(temp2.c_str()));
	}
	replace(ladderLayer.begin(), ladderLayer.end(), ',', ' '); // convert CSV to space-delimited
	stringstream c(ladderLayer);
	vector<int> ladderInts;
	string temp3;
	while(c >> temp3) {
		ladderInts.push_back(atoi(temp3.c_str()));
	}
	replace(enemiesLayer.begin(), enemiesLayer.end(), ',', ' '); // convert CSV to space-delimited
	stringstream d(enemiesLayer);
	vector<int> enemyInts;
	string temp4;
	while(d >> temp4) {
		enemyInts.push_back(atoi(temp4.c_str()));
	}


	// generate the vectors of tiles
	int i = 0;	
	for(int row = 0; row < mapHeight; row++) {
		vector<Tile*> currentRow;
		for(int column = 0; column < mapWidth; column++) {
			int xPosition = (i % mapWidth) * tileSize;
			int yPosition = (i / mapWidth) * tileSize;
			bool collision = collisionInts[i]; // non-zero sprite number indicates collision region
			bool ladder = ladderInts[i]; // non-zero sprite number indicates ladder region
            Game_Enemies enemy;
			if(enemyInts[i] == 377)
				enemy = CORGI;
			else if(enemyInts[i] == 378)
				enemy = HUSKY;
			else if(enemyInts[i] == 379)
				enemy = GREYHOUND;
			else if(enemyInts[i] == 380)
				enemy = SHIBA;
			else if(enemyInts[i] == 381)
				enemy = BULLDOG;
			else
				enemy = NONE;
			string spriteFilePath = tileImageFilename;
			int spritesPerRow = numSpritesRow;
			int spriteXoffset = ((spriteInts[i] - 1) % spritesPerRow) * tileSize;
			int spriteYoffset = ((spriteInts[i] - 1) / spritesPerRow) * tileSize;
			i++;
			currentRow.push_back( new Tile( xPosition, yPosition, collision, ladder, enemy, spriteXoffset, spriteYoffset ) );
		}
		tiles.push_back(currentRow);

	}

	// for debugging: examine the contents of a tile
	cout << "There are " << tiles.size() << " rows, and " << tiles[0].size() << " columns.\n\n";
	int tileToExamine = 1;
	cout << "Details for tile #" << tileToExamine << ":\n\n";
    cout << "xPosition =       " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetDestination().x << "\n";
	cout << "yPosition =       " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetDestination().y << "\n";
    cout << "collision =       " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetCollision() << "\n";
    cout << "ladder =          " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetIsLadder() << "\n";
    cout << "enemy =           " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetEnemy() << "\n";
	//cout << "spriteFilePath =  " <<  << "\n";
    cout << "spriteXoffset =   " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetClip().x << "\n";
    cout << "spriteYoffset =   " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth]->GetClip().y << "\n";
	cout << "\nDone.\n";

    
    //Get pixels width and height of the map also
    mapPixWidth = mapWidth * TILE_SIZE;
    mapPixHeight = mapHeight * TILE_SIZE;
}

void Map::UpdateCamera( Component_Game_Actor& actor, float timeStep )
{
   // cout << "camera: " << camera.x << endl;
    //cout << "charac: " << actor.GetGraphics()->GetDestination().x << endl;
   // cout << "camera: " << camera.x << endl;
    //cout << "x position: " << actor.GetGraphics()->GetDestination().x << endl;
   // camera.x = ( actor.GetGraphics()->GetDestination().x + actor.GetWidth() / 2 ) - camera.w / 2;
    camera.x = actor.GetGraphics()->GetDestination().x - renderer->GetScreenWidth() / 2;    

    if( camera.x < 0 )
        camera.x = 0;
    if( camera.x > mapPixWidth - camera.w )
        camera.x = mapPixWidth - camera.w;

    //x movement
    //Check right bound
  /*  if( actor.GetGraphics()->GetDestination().x >= ( camera.x + ( camera.w - CAMERA_MARGIN ) ) ) {
        if( camera.x + camera.w <= mapPixWidth ) {
        //If beyond threshold, move the camera
            camera.x = ( actor.GetGraphics()->GetDestination().x + actor.GetWidth() / 2 ) - camera.w; 
        } else {
            camera.x = mapPixWidth - camera.w;
        }
    //Check left bound
    } else if( actor.GetGraphics()->GetDestination().x <= ( camera.x + CAMERA_MARGIN ) ) {
        cout << camera.x;

        if( camera.x > 0 ) 
        {
            camera.x = ( actor.GetGraphics()->GetDestination().x + actor.GetWidth() / 2 ) - camera.w;
        }
    } */

    //y movement
    //Check top bound
    /*if( actor.GetGraphics()->GetDestination().y <= ( camera.y + CAMERA_MARGIN ) ) {
        if( camera.y > 0 )
            camera.y -= actor.GetPhysics()->GetYVel();
    //Check bottom bound
    } else if( actor.GetGraphics()->GetDestination().x >= ( camera.y + ( camera.h - CAMERA_MARGIN ) ) ) {
        if( camera.y + camera.h <= mapPixHeight )
            camera.y += actor.GetPhysics()->GetYVel();
    }*/
}

bool Map::CheckLevelEnd( Component_Game_Actor& taco )
{    
    if( taco.GetPhysics()->GetXPos() + taco.GetGraphics()->GetDestination().w >= mapPixWidth - TILE_SIZE ) {
        return true;
    }
    return false;
}