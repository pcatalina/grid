/**
* @file		play.c
* @bref		Game functions
*/
#include <curses.h>

#include "play.h"
/**
* @bref		Print a grid replacing numbers with specific signs
* @param	grid g
*/
void print_grid(grid g)
{
	int i, j, k;
	for (i = 0; i < g.lines; i++)
	{
		if (i == 0)
		{
			for (k = 0; k <= (g.columns + 1); k++)
			{
				printw("_");
			}
			printw("\n");
		}
		for (j = 0; j < g.columns; j++)
		{
			if (j == 0)
			{
				printw("|");
			}
			if (g.plan[i][j] == 0)
			{
				printw(" ");      //replace 0 with space
			}
			else if (g.plan[i][j] == 1)
			{
				printw("#");
			}
			else if (g.plan[i][j] == 2)
			{
				printw("%c", 234);
			}
			else if (g.plan[i][j] == 3)
			{
				printw("%c", 248);
			}
			else if (g.plan[i][j] == 4)
			{
				printw("%c", 251);
			}
			else if (g.plan[i][j] == 5)
			{
				printw("%c", 224);
			}
			else if (g.plan[i][j] == 6)
			{
				printw("%c", 42);
			}
			else if (g.plan[i][j] == 7)
			{
				printw("%c", 239);
			}
			else if (g.plan[i][j] == 8)
			{
				printw("o");
			}
			else if (g.plan[i][j] == 9)
			{
				printw("!");
			}
			else if (g.plan[i][j] == 10)
			{
				printw(" ");
			}
			else if (g.plan[i][j] == 11)
			{
				printw("<");
			}
			if (j == (g.columns - 1))
			{
				printw("|");
			}
		}
		printw("\n");

		if (i == (g.lines - 1))
		{
			for (k = 0; k <= (g.columns + 1); k++)
			{
				printw("^");
			}
			printw("\n");
		}
	}
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