#ifndef _MOVE_H_
#define _MOVE_H_

#include "player.h"
#include "grid.h"
#include "point.h"

void go(player* p, grid* g, point direction);

void go_up(player* p, grid* g);

void go_right(player* p, grid* g);

void go_down(player* p, grid* g);

void go_left(player* p, grid* g);

#endif // _MOVE_H_
