#ifndef _PLAY_SDL_H_
#define _PLAY_SDL_H_

#include "move.h"
#include "SDL.h"

void drawRectCairo(SDL_Surface *screen);

void print_grid(grid g);

void play(char* file_name);

#endif // _PLAY_SDL_H_
