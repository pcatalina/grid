/**
* @file		player.c
* @bref		player's position functions	
*/
#include "player.h"

/**
* @bref		Gets present player position
* @param	p player
* @return	Player position
*/
point get_position(player* p)
{
	return p->position;
}
/**
* @bref		Sets player position
* @param	p player
* @param	pt point
* @return	
*/
void set_position(player* p, point pt)
{
	p->position.x = pt.x;
	p->position.y = pt.y;
}



