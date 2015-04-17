#include "grid.h"
#define MAX_LINE 512

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

grid init_grid(int lines, int columns)
{
	grid g;
	g.plan = malloc(lines*sizeof(int*));

	int i, j;
	for (i = 0; i < lines; i++)
	{
		g.plan[i] = malloc(columns*sizeof(int));
		for (j = 0; j < columns; j++)
			g.plan[i][j] = 0;

	}
	g.lines = lines;
	g.columns = columns;

	return g;
}

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
				printw("%c",234);
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

int countNotEmptyCases(grid g)
{
	int i, j, counter = 0;
	for (i = 0; i < g.lines; i++)
	{
		for (j = 0; j < g.columns; j++)
		{
			if (g.plan[i][j] != 0)
				counter++;
		}
	}
	return counter;
}

grid load_grid(char *file_name)
{
	FILE *pToFile = fopen(file_name, "r");

	int line = 0;

	

	int r, nb_lines, nb_columns, i, j, position_x, position_y;
	fscanf(pToFile, "%d %d", &nb_lines, &nb_columns);

	fscanf(pToFile, "%d %d", &position_x, &position_y);
	point p = { position_x, position_y };
	grid g = init_grid(nb_lines, nb_columns);

	for (i = 0; i < nb_lines; i++)
	{
		for (j = 0; j < nb_columns; j++)
		{
			fscanf(pToFile, "%d ", &r);
			g.plan[i][j] = r;
		}

	}

	fclose(pToFile);
	return g;
}

point load_point(char *file_name)
{
	FILE *pToFile = fopen(file_name, "r");

	int line = 0;

	int  nb_lines, nb_columns, position_x, position_y;
	fscanf(pToFile, "%d %d", &nb_lines, &nb_columns);

	fscanf(pToFile, "%d %d", &position_x, &position_y);
	point p = { position_x, position_y };

	fclose(pToFile);
	return p;
}

int get_cell(grid* g, point pt)
{
	return g->plan[pt.x][pt.y];
}

void set_cell(grid* g, point pt, int value)
{
	g->plan[pt.x][pt.y] = value;
}