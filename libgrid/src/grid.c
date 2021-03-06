/**
* @file		grid.c
* @bref		charge and change the grid
*/
#include "grid.h"
#define MAX_LINE 512

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <assert.h>

/**
* @bref		Initializes a grid
* @param	lines int
* @param	columns int
* @return	Empty grid
*/
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

/**
* @bref		Counts the number of specific cases 
* @param	g grid
* @return	number of specific cases
*/
int countCases(grid g, int cell)
{
	int i, j, counter = 0;
	for (i = 0; i < g.lines; i++)
	{
		for (j = 0; j < g.columns; j++)
		{
			if (g.plan[i][j] == cell)
				counter++;
		}
	}
	return counter;
}

/**
* @bref		Loads a grid from a file
* @param	file_name char*
* @return	Grid from the file
*/
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

/**
* @bref		Loads a grid size from a file
* @param	file_name char*
* @return	The size of a grid in a form of point 
*/
point load_size(char *file_name)
{
	FILE *pToFile = fopen(file_name, "r");

	int line = 0;

	int  nb_lines, nb_columns;
	fscanf(pToFile, "%d %d", &nb_lines, &nb_columns);
	point size = { nb_columns, nb_lines };

	fclose(pToFile);
	return size;
}

/**
* @bref		Loads initial position of the player
* @param	file_name char*
* @return	initial position of the player
*/
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

/**
* @bref		Checks if player is moving into a wall or out of the grid
* @param	future_player_pos point
* @param	g grid*
* @return	True if playes goes out of borders False if not
*/
int is_in_bounds(point future_player_pos, grid* g)
{
	return ((future_player_pos.x > (-1)) &&
		(future_player_pos.y > (-1)) &&
		(future_player_pos.x < g->lines) &&
		(future_player_pos.y < g->columns));
}

/**
* @bref		Checks if the position is not a wall
* @param	pos point
* @param	g grid*
* @return	True or False
*/
int is_not_a_wall(point pos, grid* g)
{
	return (get_cell(g, pos) != 1);
}

/**
* @bref		Gets the value of a cell from the grid
* @param	g grid*
* @param	pt point
* @return	Value of the chosen cell
*/
int get_cell(grid* g, point pt)
{
	//assert(is_in_bounds(pt, g));
	return g->plan[pt.x][pt.y];
}

/**
* @bref		Changes the value of a specific cell
* @param	g grid*
* @param	pt point
* @param	value int
* @return
*/
void set_cell(grid* g, point pt, int value)
{
	g->plan[pt.x][pt.y] = value;
}