#include "point.h"



point sum_points(point p, point q)
{
	point t;
	t.x = p.x + q.x;
	t.y = p.y + q.y;
	return t;
}

