/*
 * Screen.h
 *
 *  Created on: Oct 22, 2017
 *      Author: BC
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include "SDL2/SDL.h"

namespace asiamvl {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
};

} /* namespace asiamvl */

#endif /* SCREEN_H_ */
