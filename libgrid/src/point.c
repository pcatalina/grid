/**
* @file		point.c
* @bref		point functions	
*/
#include "point.h"

/**
* @bref		Adds two points
* @param	p point
* @param	q point
* @return	sum of the points
*/
point sum_points(point p, point q)
{
	point t;
	t.x = p.x + q.x;
	t.y = p.y + q.y;
	return t;
}
