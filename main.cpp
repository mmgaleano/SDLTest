//============================================================================
// Name        : SDL.cpp
// Author      : Michael Mora
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <Math.h>
#include <time.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace std;
using namespace asiamvl;

int main(int argc, char* argv[]) {

	Screen screen;
	Swarm swarm;
	srand(time(NULL));

		if(screen.init() == false) {
			cout << "Error initializing SDL." << endl;
		}

		while (true) {
			// Update particles

			//Returns the num of miliseconds since the program started
			int elapsed = SDL_GetTicks();

			swarm.update(elapsed);

			unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
			unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
			unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

			const Particle* const pParticles = swarm.getParticles();

			for(int i = 0; i < Swarm::NPARTICLES; i++){

				Particle particle = pParticles[i];
				int x = ((particle.m_x) + 1) * (Screen::SCREEN_WIDTH/2);
				int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

				screen.setPixel(x, y, red, green, blue);
			}

			screen.boxBlur();

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
