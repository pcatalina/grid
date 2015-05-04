#ifndef _PLAY_H_
#define _PLAY_H_

#include "player.h"
#include "grid.h"

void go(player* p, grid* g, point direction);

void go_up(player* p, grid* g);

void go_right(player* p, grid* g);

void go_down(player* p, grid* g);

void go_left(player* p, grid* g);

void play(char* file_name);

#endif // _PLAY_H_
