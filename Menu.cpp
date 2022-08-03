#include "Menu.h"
#include "Mechanics.h"
#include "GameGUI.h"
#include <iostream>

int Menu::PrintInterface(Mechanics& mechanics){
    char choice;
    cout << "Welcome to 2048";
    cout << endl << endl;

    cout << " 1. Play" << endl;
	cout << " 2. Exit" << endl << endl;

    cout << " Enter choice: ";
	cin >> choice;

    if(choice == '1' || choice == '2')
        return (choice - '0');
    else
        return 0;
}

void Menu::MenuSelect()
{
	Mechanics mechanics;
	int choice;
	do {
		choice = this->PrintInterface(mechanics);
		switch (choice)
		{
		case 1:
			mechanics.launchGame(false);
			break;
		case 2:
			exit(0);
			break;
		default:
			GameGUI invalidKS;
			invalidKS.PrintInvalidKeystroke();
			cout << endl;
			break;
		}
	} while (choice != 2);
}