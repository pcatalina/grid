/**
* @file		play.c
* @bref		Move player functions	
*/
#include <curses.h>

#include "play.h"

/**
* @bref		Checks if player is moving into a wall or out of the grid
* @param	future_player_pos point
* @param	g grid*
* @return	True if playes goes out of borders False if not
*/
int bounds_checking(point future_player_pos, grid* g)
{
	if ((get_cell(g, future_player_pos) == 1)||
		(future_player_pos.x==0)||
		(future_player_pos.y<0)||
		(future_player_pos.x>=g->lines-1)||
		(future_player_pos.y==g->columns))
		return 1;
	else
		return 0;
}

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
	if (bounds_checking(new_position, g) == 0)
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