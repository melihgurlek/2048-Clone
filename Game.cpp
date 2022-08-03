#include "Game.h"

using namespace std;

bool Game::isTilesEmpty(){
    bool TileIsEmpty = true;
    for (int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(getTileNum(row, col) != 0){
                TileIsEmpty = false;
                break;
            }
        }
        if(TileIsEmpty = false)
            break;
    }
    return TileIsEmpty;
}