#ifndef _GUI_
#define _GUI_

using namespace std;

class GUI
{
public:
    void ClearScreen();

    virtual int PrintScreen(Mechanics& mechanics) = 0;
};



#endif