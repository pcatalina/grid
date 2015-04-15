#include "player.h"



void move_player(char* file_name)
{
	player p;
	p.position = load_point(file_name);
	grid g = load_grid(file_name);
	char new_position;
	printf("Control keys:\nI *up*\nL *right*\nK *down*\nJ *left*\n");
	int n = 0;
	while (n < MAX_LIVES)
	{
		scanf("%c", &new_position);

		if ((new_position == 'd') && 
			(g.plan[p.position.x + 1][p.position.y] != 1))
		{
			g.plan[p.position.x + 1][p.position.y] = 2;


		}
		else if ((new_position == 's') && (g.plan[p.position.x][p.position.y - 1] != 1))
		{
			g.plan[p.position.x][p.position.y - 1] = 2;


		}
		else if ((new_position == 'a') && (g.plan[p.position.x - 1][p.position.y] != 1))
		{
			g.plan[(p.position.x) - 1][p.position.y] = 2;


		}
		else if ((new_position == 'w') && (g.plan[p.position.x][p.position.y + 1] != 1))
		{
			g.plan[p.position.x][p.position.y + 1] = 2;


		}

		g.plan[p.position.x][p.position.y] = 0;
		print_grid(g);
		n++;
	}
}