#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "point.h"


typedef struct
{
	point position;
	int lives;
	int attack;
	int defense;
	//char** inventory;
}player;

point get_position(player* p);

void set_position(player* p, point pt);

#endif // !_PLAYER_H_
