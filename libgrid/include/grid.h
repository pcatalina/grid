#ifndef _GRID_H_
#define _GRID_H_



#include "point.h"

typedef struct
{
	int** plan;
	int lines;
	int columns;
}grid;

grid init_grid(int lines, int columns);

int countNotEmptyCases(grid g);

grid load_grid(char* file_name);

point load_size(char *file_name);

point load_point(char *file_name);

int is_in_bounds(point future_player_pos, grid* g);

int is_not_a_wall(point pos, grid* g);

int get_cell(grid* g, point pt);

void set_cell(grid* g, point pt, int value);

#endif // !_GRID_H_
