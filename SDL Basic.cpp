//============================================================================
// Name        : SDL.cpp
// Author      : Michael Mora
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "Screen.h"
#include "SDL2/SDL.h"

using namespace std;
using namespace asiamvl;

int main(int argc, char* argv[]) {

	Screen screen;

	if(screen.init() == false){

		cout << "Error initializing SDL!!!" << endl;
	}

    // Delay so that we can see the window appear
    //SDL_Delay(2000);

    while(true){

    	if(!screen.processEvents()){

    		break;
    	}

    }

    screen.close();
    return 0;
}
