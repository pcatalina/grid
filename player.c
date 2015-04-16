#include "player.h"

point get_position(player* p)
{
	return p->position;
}

void set_position(player* p, point pt)
{
	p->position.x = pt.x;
	p->position.y = pt.y;
}



