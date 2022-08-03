#ifndef _IO_
#define _IO_

#include "Mechanics.h"
#include <tuple>

using namespace std;

class IO
{
public:
    int GetTilePlace(int row, int col);
    tuple<int,int> ReturnRowCol(int tileNo);
};


#endif