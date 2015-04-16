#include <curses.h>
#include <assert.h>
#include "player.h"

void bounceChecking()
{

}

void go_up(player* p, grid* g)
{
	p->position.x = p->position.x - 1;
	g->plan[p->position.x][p->position.y] = 2;
	print_grid(*g);

}

void go_right(player* p, grid* g)
{
	p->position.y = p->position.y + 1;
	g->plan[p->position.x][p->position.y] = 2;
	print_grid(*g);
}


void go_down(player* p, grid* g)
{
	p->position.x = p->position.x + 1;
	g->plan[p->position.x][p->position.y] = 2;
	print_grid(*g);
}

void go_left(player* p, grid* g)
{
	p->position.y = p->position.y - 1;
	g->plan[p->position.x][p->position.y] = 2;
	print_grid(*g);
}

void move_player(char* file_name)
{
	WINDOW * mainwin;

	if ((mainwin = initscr()) == NULL) 
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}
	noecho();
	player p;
	p.position = load_point(file_name);
	grid g = load_grid(file_name);
	

	printf("Control keys:\nw *up*\nd *right*\ns *down*\na *left*\n");
	int n = 0;


	char move ;
	print_grid(g);
	while (move = getch())
	{
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

	g.plan[p.position.x][p.position.y] = 0;
	refresh();
	}
	//getchar();
}