#include "grid.h"
#include "player.h"
#define MAX_LINE 512
//#define FILE "grid.txt"


int main()
{
	grid g = init_grid(7, 9);
	print_grid(g);
	point p = { 3, 4 };
	load_grid("grid.txt");
	move_player("grid.txt");
	getchar();
	return 0;
}

