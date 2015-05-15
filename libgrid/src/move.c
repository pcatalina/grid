/**
* @file		play.c
* @bref		Move player functions
*/
#include "move.h"
#define MAX_LIVES 10
#define MAX_TOOLS 2 // max number of tools -1 !!!

/**
* @bref		Control player moves in each situation 
* @param	p player*
* @param	g grid*
* @param	direction point
* @return
*/
void go(player* p, grid* g, point direction)
{
	int life = countCases(*g, 6);
	int tool = countCases(*g, 8);
	point old_position = get_position(p);
	point new_position = sum_points(old_position, direction);
	if (is_in_bounds(new_position, g) && is_not_a_wall(new_position, g))
	{
		if ((get_cell(g, new_position) == 3) && (p->lives <= (MAX_LIVES - 2)))	//win 2 lives
		{
			p->lives += 2;

			int i;
			for (i = 0; i < life + 2; i++)
			{

				point live_position = { (g->lines - 1), i };
				if (get_cell(g, live_position) == 7)
				{
					set_cell(g, live_position, 6);
				}
			}

		}
		else if (get_cell(g, new_position) == 4)	//lose 2 lives
		{
			p->lives -= 2;
			int i;
			for (i = life; i >= life - 2; i--)
			{
				point live_position = { (g->lines - 1), i };
				if (get_cell(g, live_position) == 6)
				{
					set_cell(g, live_position, 7);
				}
			}
		}
		else if ((get_cell(g, new_position) == 5) && (p->lives < MAX_LIVES))	//get max lives
		{
			p->lives = MAX_LIVES;
			int i;
			for (i = 0; i < MAX_LIVES; i++)
			{

				point live_position = { (g->lines - 1), i };
				if (get_cell(g, live_position) == 7)
				{
					set_cell(g, live_position, 6);
				}
			}
		}
		else if (get_cell(g, new_position) == 11)	//grab the tools
		{
			int i;
			for (i = 0; i < tool + 1; i++)
			{

				point tool_position = { (g->lines - 2), i };
				if (get_cell(g, tool_position) == 10)
				{
					set_cell(g, tool_position, 8);
				}
			}
		}
		else if (get_cell(g, new_position) == 9)	//meet the monster
		{
			int i;

			for (i = tool; i >= tool - 1; i--)
			{
				point tool_position = { (g->lines - 2), i };
				if (get_cell(g, tool_position) == 8)
				{
					set_cell(g, tool_position, 10);

				}
				if (tool == 0)
				{
					p->lives = 0;
					int j;
					for (j = life; j >= 0; j--)
					{
						point live_position = { (g->lines - 1), j };
						if (get_cell(g, live_position) == 6)
						{
							set_cell(g, live_position, 7);
						}
					}
				}
			}
		}
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

