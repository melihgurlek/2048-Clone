#ifndef _PLAYER_
#define _PLAYER_

#include <string>
using namespace std;

class Player
{
private:
    int score;
    string playerName;
public:
    Player(string playerName, int score);
    string GetPlayerName();
    int GetScore();
};


#endif