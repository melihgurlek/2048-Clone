#ifndef _MECHANICS_
#define _MECHANICS_

#include "Game.h"

using namespace std;

class Mechanics : public Game
{
public:
    Mechanics() : Game(){}
    Mechanics(array<array<int,4>, 4> tilesInput, int score) : Game(tilesInput, score){}

    void GameOverCheck();

    int RandomTileGen();
    int RandomRowColGen();
    void SpawnInitialRandomTile();
    void SpawnRandomTile();

    string PlayerInput();
    bool moveTilesUp();
	bool moveTilesLeft();
	bool moveTilesDown();
	bool moveTilesRight();
    bool confirmKS();
	bool processKS();

	void launchGame(bool loadedGame);
};



#endif