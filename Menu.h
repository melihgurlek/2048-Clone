#ifndef _MENU_
#define _MENU_

#include "GUI.h"
#include "Mechanics.h"

using namespace std;

class Menu : public GUI
{
public:
    int PrintInterface(Mechanics& mechanics);
    void MenuSelect();
};


#endif