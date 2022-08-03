#include "Mechanics.h"
#include "Game.h"
#include "GameGUI.h"

void Mechanics::GameOverCheck(){
    bool anyFreeTiles = false;
    bool does2048Exist = false;

    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(this -> getTileNum(row, col) == 0)
                anyFreeTiles = true;
            if (this->getTileNum(row, col) == 2048)
			{
				does2048Exist = true;
				break;
			}
        }
        if(does2048Exist == true)
            break;
    }

    if (does2048Exist == true)
	{
		this->SetIsGameWon(true);
		this->SetIsGameOver(true);
	}
	else if (anyFreeTiles == false)
	{
		this->SetIsGameOver(true);
	}

}

int Mechanics::RandomTileGen(){
    int randomNum = (rand() % 2) + 1;

    if(randomNum == 1)
        return 2;
    else 
        return 4;
}

int Mechanics::RandomRowColGen(){
    int randomRowCol = rand() % 4;
    return randomRowCol;
}

void Mechanics::SpawnInitialRandomTile(){
    int firstValue = this->RandomTileGen();
	int secondValue = this->RandomTileGen();

	int randomRow1, randomRow2;
	int randomCol1, randomCol2;

	randomRow1 = this->RandomRowColGen();
	randomCol1 = this->RandomRowColGen();
	randomRow2 = this->RandomRowColGen();
	randomCol2 = this->RandomRowColGen();


    if (randomRow1 == randomRow2)
	{
		while (randomRow1 == randomRow2)
		{
			randomRow2 = this->RandomRowColGen();
		}
	}
    
    // Maybe encasing these with ifs would look cleaner
	while (randomCol1 == randomCol2)
	{
		randomCol2 = this->RandomRowColGen();
	}
    while (randomCol1 == randomCol2)
	{
		randomCol2 = this->RandomRowColGen();
	}

    this->setTileNum(randomRow1, randomCol1, firstValue);
	this->setTileNum(randomRow2, randomCol2, secondValue);
}

void Mechanics::SpawnRandomTile(){
    char randomValue = this -> RandomTileGen();
    int randomRow, randomCol;
    bool availableTile = false;

    while(availableTile == false){
        randomRow = this -> RandomRowColGen();
        randomCol = this -> RandomRowColGen();
        if (this->getTileNum(randomRow, randomCol) == 0)
		{
			availableTile = true;
			this->setTileNum(randomRow, randomCol, randomValue);
		}
    }
}

string Mechanics::PlayerInput(){
    cout << "Enter your next move: ";

	char keystroke;
	cin >> keystroke;
	if (keystroke == 'W' || keystroke == 'w')
		return "MOVE_UP";
	else if (keystroke == 'A' || keystroke == 'a')
		return "MOVE_LEFT";
	else if (keystroke == 'S' || keystroke == 's')
		return "MOVE_DOWN";
	else if (keystroke == 'D' || keystroke == 'd')
		return "MOVE_RIGHT";
	else if (keystroke == 'N' || keystroke == 'n')
		return "NEW_GAME";
	else if (keystroke == 'Q' || keystroke == 'q')
		return "QUIT";
	else
		return "BAD_KEYSTROKE";
}

// Could've used switch cases for the whole movement
bool Mechanics::moveTilesUp()
{
	bool tilesMoved = false;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			// 'row2' is used to compare two rows with each other
			for (int row2 = row + 1; row2 <= 3; row2++)
			{
				if (this->getTileNum(row2, col) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->ChangeTileNumFromTile(row, col, row2, col);
						this->setTileNum(row2, col, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row2, col))
						{
							//two mine tiles colliding
							this->mulTileByTwo(row, col);
							this->setTileNum(row2, col, 0);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Mechanics::moveTilesLeft()
{
	bool tilesMoved = false;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			// 'col2' is used to compare two columns with each other
			for (int col2 = col + 1; col2 <= 3; col2++)
			{
				if (this->getTileNum(row, col2) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->ChangeTileNumFromTile(row, col, row, col2);
						this->setTileNum(row, col2, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row, col2))
						{
							this->mulTileByTwo(row, col);
							this->getTileNum(row, col2);
							this->addToScore(row, col);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Mechanics::moveTilesDown()
{
	bool tilesMoved = false;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 3; row >= 0; row--)
		{
			// 'row2' is used to compare two rows with each other
			for (int row2 = row - 1; row2 >= 0; row2--)
			{
				if (this->getTileNum(row2, col) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->ChangeTileNumFromTile(row, col, row2, col);
						this->setTileNum(row2, col, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row2, col))
						{
							this->mulTileByTwo(row, col);
							this->setTileNum(row2, col, 0);
							this->addToScore(row, col);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Mechanics::moveTilesRight()
{
	bool tilesMoved = false;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 3; col > 0; col--)
		{
			for (int col2 = col - 1; col2 >= 0; col2--)
			{
				if (this->getTileNum(row, col2) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->ChangeTileNumFromTile(row, col, row, col2);
						this->setTileNum(row, col2, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row, col2))
						{
							this->mulTileByTwo(row, col);
							this->setTileNum(row, col2, 0);
							this->addToScore(row, col);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Mechanics::processKS()
{
	bool tilesMoved = true, tilesNotMoved = false;
	string keystroke;
	keystroke = this->PlayerInput();
	GameGUI InvalidKeystroke;

	if (keystroke == "MOVE_UP")
	{
		bool haveTilesMoved = this->moveTilesUp();
		if (haveTilesMoved == false)
		{
			InvalidKeystroke.PrintInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "MOVE_LEFT")
	{
		bool haveTilesMoved = this->moveTilesLeft();
		if (haveTilesMoved == false)
		{
			InvalidKeystroke.PrintInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "MOVE_DOWN")
	{
		bool haveTilesMoved = this->moveTilesDown();
		if (haveTilesMoved == false)
		{
			InvalidKeystroke.PrintInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "MOVE_RIGHT")
	{
		bool haveTilesMoved = this->moveTilesRight();
		if (haveTilesMoved == false)
		{
			InvalidKeystroke.PrintInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "NEW_GAME")
	{
		bool haveTilesMoved = this->confirmKS();
		if (haveTilesMoved == false)
		{
			InvalidKeystroke.PrintInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "QUIT")
		exit(0);
	else if (keystroke == "BAD_KEYSTROKE")
	{
		GameGUI keystrokeAlert;
		keystrokeAlert.PrintInvalidKeystroke();
		return tilesNotMoved;
	}
}

void Mechanics::launchGame(bool loadedGame)
{
	GameGUI gameGUI;

	bool isKeystrokeValid = true;

	if (this->isTilesEmpty() == true)
		this->SpawnInitialRandomTile();

	do {
		this->GameOverCheck();
		gameGUI.PrintScreen(*this);

		if (this->getIsGameWon() == true)
		{
			string playerName;
			gameGUI.printWinGame(*this);
		}
		else if (this->getIsGameOver() == true)
			gameGUI.printLostGame(*this);
		else
		{
			if (loadedGame == true)
			{
				loadedGame = false;
				isKeystrokeValid = false;
			}
			if (isKeystrokeValid == true)
			{
				this->SpawnRandomTile();
			}
			isKeystrokeValid = this->processKS();
		}
	} while (this->getIsGameOver() == false);
}