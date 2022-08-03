#ifndef _GAMEGUI_
#define _GAMEGUI_

#include "Mechanics.h"
#include "GUI.h"

using namespace std;

class GameGUI : public GUI
{
public:
    int DigitAmount(int number);
    void CenterTile(int number);
    int PrintScreen(Mechanics& mechanics);

    void PrintInvalidKeystroke();
    void printLostGame(Mechanics& mechanics);
	void printWinGame(Mechanics& mechanics);

	void printControls();
};

#endif