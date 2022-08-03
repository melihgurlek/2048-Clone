#ifndef _GAME_
#define _GAME_

#include <iostream>
#include <string>
#include <array>
#include <time.h>
using namespace std;

class Game
{
private:
    array<array<int, 4>, 4> tiles;
    int score;
    bool isGameWon;
    bool isGameOver;
public:
    Game(){
        srand((int)time(0));
        tiles.fill({0});
        this->SetScore(0);
        this->SetIsGameWon(false);
        this->SetIsGameOver(false);

    }

    Game(array<array<int, 4>, 4> tilesInput, int score)
		{
			srand((int)time(0));
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
					this->setTileNum(row, col, tilesInput[row][col]);
			}
			this->SetScore(score);
			this->SetIsGameWon(false);
			this->SetIsGameOver(false);
		}

    int getTileNum(int row, int col) {
        return tiles[row][col];
        }

	void setTileNum(int row, int col, int num) {
        tiles[row][col] = num;
        }

    void ChangeTileNumFromTile(int rowNew, int colNew, int rowSource, int colSource) {
        tiles[rowNew][colNew] = tiles[rowSource][colSource];
        }

    void mulTileByTwo(int row, int column) {
        tiles[row][column] *= 2;
        }

	bool isTilesEmpty();


    int getScore() {
        return score;
        }

	void setScore(int score) {
        this->score = score;
        }

	void addToScore(int rowSource, int colSource) {
        score += tiles[rowSource][colSource];
        }

	void subtFromScore(int rowSource, int colSource) {
        score -= tiles[rowSource][colSource];
        }

    void SetScore(int score){
        this->score = score;
    }
    

    bool getIsGameWon() {
        return isGameWon;
    }
    void SetIsGameWon(bool isGameWon){
        this->isGameWon = isGameWon;
    }
    bool getIsGameOver() {
        return isGameOver;
    }
    void SetIsGameOver(bool isGameOver){
        this->isGameOver = isGameOver;
    }

};



#endif