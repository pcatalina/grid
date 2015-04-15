#ifndef _GAMER_H_
#define _GAMER_H_

#include <stdlib.h>
#include <stdio.h>

#include "point.h"
#include "grid.h"

#define MAX_LIVES 10
#define MAX_MOVES 100

typedef struct
{
	point position;
	int lives;
	int attack;
	int defense;
	//char** inventory;
}player;


void move_player(char* file_name);
#endif // !_GAMER_H_
