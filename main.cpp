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
#include <Math.h>
#include "SDL2/SDL.h"

using namespace std;
using namespace asiamvl;

int main(int argc, char* argv[]) {

	Screen screen;

		if(screen.init() == false) {
			cout << "Error initialising SDL." << endl;
		}

		while (true) {
			// Update particles


			//Returns the num of miliseconds since the program started
			int elapsed = SDL_GetTicks();
			unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
			unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
			unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

			for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
				for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
					screen.setPixel(x, y, red, green, blue);
				}
			}

			// Draw the screen
			screen.update();

			// Check for messages/events
			if(screen.processEvents() == false) {
				break;
			}
		}

		screen.close();

		return 0;
	}
