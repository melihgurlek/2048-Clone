#include "IO.h"
#include <iostream>
#include <string>
#include <tuple>

int IO::GetTilePlace(int row, int col){
    // Increments both row and col by one
    switch (row)
    {
    case 0:
		switch (col)
		{
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		}
		break;
	case 1:
		switch (col)
		{
		case 0:
			return 4;
			break;
		case 1:
			return 5;
			break;
		case 2:
			return 6;
			break;
		case 3:
			return 7;
			break;
		}
		break;
	case 2:
		switch (col)
		{
		case 0:
			return 8;
			break;
		case 1:
			return 9;
			break;
		case 2:
			return 10;
			break;
		case 3:
			return 11;
			break;
		}
		break;
	case 3:
		switch (col)
		{
		case 0:
			return 12;
			break;
		case 1:
			return 13;
			break;
		case 2:
			return 14;
			break;
		case 3:
			return 15;
			break;
		}
		break;
    }
}

tuple<int, int> IO::ReturnRowCol(int tileNo)
{
	int row, col;

	if (tileNo <= 3)
	{
		row = 0;
		switch (tileNo)
		{
		case 0:
			col = 0;
			break;
		case 1:
			col = 1;
			break;
		case 2:
			col = 2;
			break;
		case 3:
			col = 3;
			break;
		}
	}
	else if (tileNo >= 4 && tileNo <= 7)
	{
		row = 1;
		switch (tileNo)
		{
		case 4:
			col = 0;
			break;
		case 5:
			col = 1;
			break;
		case 6:
			col = 2;
			break;
		case 7:
			col = 3;
			break;
		}
	}
	else if (tileNo >= 8 && tileNo <= 11)
	{
		row = 2;
		switch (tileNo)
		{
		case 8:
			col = 0;
			break;
		case 9:
			col = 1;
			break;
		case 10:
			col = 2;
			break;
		case 11:
			col = 3;
			break;
		}
	}
	else if (tileNo >= 12 && tileNo <= 15)
	{
		row = 3;
		switch (tileNo)
		{
		case 12:
			col = 0;
			break;
		case 13:
			col = 1;
			break;
		case 14:
			col = 2;
			break;
		case 15:
			col = 3;
			break;
		}
	}

	return { row, col };
}