//============================================================================
// Name        : SDL.cpp
// Author      : Michael Mora
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "SDL2/SDL.h"

using namespace std;

int main(int argc, char* argv[]) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	bool quit = false;
	SDL_Event event;
	SDL_Renderer* renderer;
	SDL_Window *window;
	SDL_Texture *texture;
	Uint32 *buffer;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		cout << "SDL init failed" << endl;
		return 1;
	}

    window = SDL_CreateWindow("Dust Explosion",
                              SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    if(window == NULL){
    	SDL_Quit();
    	return 2;
    }

    //For changing background to black
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_PRESENTVSYNC);

	if(renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}



	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}


	buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_SetTextureColorMod(texture, 0, 97, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

    // Delay so that we can see the window appear
    //SDL_Delay(2000);

    while(!quit){

    	//Fetch the latest event
    	while(SDL_PollEvent(&event)){

    		if(event.type == SDL_QUIT){

    			quit = true;

    		}

    	}
    }

    // Cleanup and Quit
	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}
