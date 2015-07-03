#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include "tinyxml.h"
using namespace std;

enum Enemy {NONE=0, CORGI=1, HUSKY=2, GREYHOUND=3, SHIBA=4, BULLDOG=5};

// a Tile class that represents all of the details for one specific tile
class Tile {

public:
	// i should probably make these private and write some get methods
	int xPosition;
	int yPosition;
	bool collision;
	bool ladder;
	enum Enemy enemy;
	string spriteFilePath;
	int spriteXoffset;
	int spriteYoffset;

public:
	Tile(int xPosition, int yPosition, bool collision, bool ladder, enum Enemy enemy, string spriteFilePath, int spriteXoffset, int spriteYoffset) {
		this->xPosition = xPosition;
		this->yPosition = yPosition;
		this->collision = collision;
		this->ladder = ladder;
		this->enemy = enemy;
		this->spriteFilePath = spriteFilePath;
		this->spriteXoffset = spriteXoffset;
		this->spriteYoffset = spriteYoffset;
	}

	~Tile() {}

};

void generateTiles(int spritesPerRow) {

}

int main(int argc, char** argv) {

	// open the XML map file
	TiXmlDocument xmlFile("level_1.tmx");
	if(xmlFile.LoadFile()) {
		cout << "Successfully opened the XML map file.\n";
	} else {
		cout << "ERROR: Unable to open the XML map file. Exiting.\n";
		return 1;
	}

	// parse the XML
	// this code assumes that the layers exist in the XML file in this order: sprites, then collision, then ladders.
	int mapWidth = atoi(xmlFile.FirstChildElement("map")->Attribute("width"));
	int mapHeight = atoi(xmlFile.FirstChildElement("map")->Attribute("height"));
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
	vector< vector<Tile> > tiles; // ordered as [row][col]
	for(int row = 0; row < mapHeight; row++) {
		vector<Tile> currentRow;
		for(int column = 0; column < mapWidth; column++) {
			int xPosition = (i % mapWidth) * tileSize;
			int yPosition = (i / mapWidth) * tileSize;
			bool collision = collisionInts[i]; // non-zero sprite number indicates collision region
			bool ladder = ladderInts[i]; // non-zero sprite number indicates ladder region
			enum Enemy enemy;
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
			int spritesPerRow = 8;
			int spriteXoffset = ((spriteInts[i] - 1) % spritesPerRow) * tileSize;
			int spriteYoffset = ((spriteInts[i] - 1) / spritesPerRow) * tileSize;
			i++;
			currentRow.push_back(Tile(xPosition, yPosition, collision, ladder, enemy, spriteFilePath, spriteXoffset, spriteYoffset));
		}
		tiles.push_back(currentRow);

	}

	// for debugging: examine the contents of a tile
	cout << "There are " << tiles.size() << " rows, and " << tiles[0].size() << " columns.\n\n";
	int tileToExamine = 1;
	cout << "Details for tile #" << tileToExamine << ":\n\n";
	cout << "xPosition =       " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].xPosition << "\n";
	cout << "yPosition =       " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].yPosition << "\n";
	cout << "collision =       " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].collision << "\n";
	cout << "ladder =          " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].ladder << "\n";
	cout << "enemy =           " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].enemy << "\n";
	cout << "spriteFilePath =  " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].spriteFilePath << "\n";
	cout << "spriteXoffset =   " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].spriteXoffset << "\n";
	cout << "spriteYoffset =   " << tiles[tileToExamine / mapWidth][tileToExamine % mapWidth].spriteYoffset << "\n";
	cout << "\nDone.\n";
	return 0;
}
