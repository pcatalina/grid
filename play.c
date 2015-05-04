/**
* @file		play.c
* @bref		Move player functions	
*/
#include <curses.h>

#include "play.h"



/**
* @bref		Moves player
* @param	p player*
* @param	g grid*
* @param	direction point
* @return	
*/
void go(player* p, grid* g, point direction)
{
	point old_position = get_position(p);
	point new_position = sum_points(old_position, direction);
	if (is_in_bounds(new_position, g) && is_not_a_wall(new_position, g))
	{
		set_cell(g, new_position, 2);
		set_cell(g, old_position, 0);
		set_position(p, new_position);
		print_grid(*g);
	}
	else
	{
		set_position(p, old_position);
		print_grid(*g);
	}

}

/**
* @bref		Directs player up
* @param	p player*
* @param	g grid*
* @return	
*/
void go_up(player* p, grid* g)
{
	point position = { -1, 0 };
	go(p, g, position);

}

/**
* @bref		Directs player to the right
* @param	p player*
* @param	g grid*
* @return
*/
void go_right(player* p, grid* g)
{
	point position = { 0, 1 };
	go(p, g, position);
}

/**
* @bref		Directs player down
* @param	p player*
* @param	g grid*
* @return
*/
void go_down(player* p, grid* g)
{
	point position = { 1, 0 };
	go(p, g, position);
}

/**
* @bref		Directs player to the left
* @param	p player*
* @param	g grid*
* @return
*/
void go_left(player* p, grid* g)
{
	point position = { 0, -1 };
	go(p, g, position);
}

/**
* @bref		Opens window to play in the game
* @param	file_name char*
* @return	
*/
void play(char* file_name)
{
	WINDOW * mainwin = initscr();

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