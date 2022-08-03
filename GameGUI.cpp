#include "GameGUI.h"
#include "Mechanics.h"

int GameGUI::DigitAmount(int number)
{
    if (number < 10)
        return 1;
    if (number < 100)
        return 2;
    if (number < 1000)
        return 3;
    if (number < 10000)
        return 4;
}

void GameGUI::CenterTile(int number)
{
    int width = 7;
    int remainingWidth = width - this->DigitAmount(number);
    int rightWidth = remainingWidth / 2;
    int leftWidth = remainingWidth - rightWidth;

    for (int i = 0; i < leftWidth; i++)
        cout << " ";

    cout << number;
    for (int i = 0; i < rightWidth; i++)
        cout << " ";
}

int GameGUI::PrintScreen(Mechanics& mechanics)
{
    this->ClearScreen();
    cout << " *************************************" << endl;
    cout << " *  Join the tiles and get to 2048!  *" << endl;
    cout << " *************************************" << endl;
    cout << endl;


    for (int k = 0; k < 4; k++) {
        cout << "--------";
    }
    cout << '-' << endl;

    for (int i = 0; i < 4; i++) {
        cout << "|";

        for (int j = 0; j < 4; j++)
        {
            if (mechanics.getTileNum(i, j) > 1)
                this->CenterTile(mechanics.getTileNum(i, j));
            else if (mechanics.getTileNum(i, j) == 0)
                cout << "       ";
            cout << "|";
        }

        cout << endl;
        for (int k = 0; k < 4; k++)
            cout << "--------";
        cout << '-' << endl;

    }

    cout << endl;
    cout << " SCORE : ";
    cout << mechanics.getScore() << endl;
    this->printControls();

    return 0;
}

void GameGUI::PrintInvalidKeystroke()
{
    cout << endl;
    cout << " Wrong keystroke! Please try again" << endl;
}

void GameGUI::printLostGame(Mechanics& mechanics)
{
    cout << " You Lost!" << endl;
    cout << " Score: " << mechanics.getScore() << endl << endl;
}

void GameGUI::printWinGame(Mechanics& mechanics)
{
    cout << " You Won!" << endl;
    cout << " Score: " << mechanics.getScore() << endl << endl;

}

void GameGUI::printControls()
{
        cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << " x CONTROLS:                                   x" << endl;
        cout << " x---------------------------------------------x" << endl;
        cout << " x N: New Game      X: Save Game  L: Load Game x" << endl;
        cout << " x Q: Quit                                     x" << endl;
        cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << endl;
}