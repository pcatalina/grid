/**
* @file		main_nc.c
* @bref		Open game	
*/
#include <curses.h>
#include "play.h"

int main()
{
	play("../../data/grid.txt");
	getchar();
	return 0;
}

