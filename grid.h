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

void print_grid(grid g);

int countNotEmptyCases(grid g);

grid load_grid(char* file_name);

point load_point(char *file_name);
#endif // !_GRID_H_
