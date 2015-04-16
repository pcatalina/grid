#include <curses.h>
#include "player.h"
#include "grid.h"

void go(player* p, grid* g, point direction)
{
	point old_position = get_position(p);
	int previous = get_cell(g, old_position);
	point new_position = sum_points(old_position, direction);
	set_cell(g, new_position, 2);
	set_cell(g, old_position, 0);
	set_position(p, new_position);
	print_grid(*g);
}
void go_up(player* p, grid* g)
{
	point position = { -1, 0 };
	go(p, g, position);

}

void go_right(player* p, grid* g)
{
	point position = { 0, 1 };
	go(p, g, position);
}


void go_down(player* p, grid* g)
{
	point position = { 1, 0 };
	go(p, g, position);
}

void go_left(player* p, grid* g)
{
	point position = { 0, -1 };
	go(p, g, position);
}

void play(char* file_name)
{
	WINDOW * mainwin=initscr();

	noecho();


	player p;
	p.position = load_point(file_name);
	point player_position = p.position;
	grid g = load_grid(file_name);


	//printw("Control keys:\nw *up*\nd *right*\ns *down*\na *left*\n");

	set_cell(&g, player_position, 2);
	print_grid(g);

	char move;

	while (move = getch())
	{

		clear();

		switch (move)
		{
		case'w': go_up(&p, &g);
			break;
		case'd': go_right(&p, &g);
			break;
		case's': go_down(&p, &g);
			break;
		case 'a': go_left(&p, &g);
			break;
		default: break;
		}

		refresh();
	}
	delwin(mainwin);
	endwin();
}