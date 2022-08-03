#include "Player.h"

Player::Player(string playerName, int score){
    this ->playerName = playerName;
    this ->score = score;
}

string Player::GetPlayerName(){
    return playerName;
}

int Player::GetScore(){
    return score;
}