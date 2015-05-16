/**
* @file		play.c
* @bref		Game functions
*/

#include <cairo.h>
#include "SDL_image.h"
#include "grid.h"
#include "play_sdl.h"

#define SCREEN_SIZE	  load_size("../../data/grid.txt")
#define SPRITE_SIZE   50
#define STEP_SIZE	  50
#define SCREEN_WIDTH  SCREEN_SIZE.x*STEP_SIZE
#define SCREEN_HEIGHT SCREEN_SIZE.y*STEP_SIZE
/**
* @bref		Drow a rectangle on a SDL surface with help of CAIRO
* @param	SDL surface	on with the picture will apear
*/
void drawRectCairo(SDL_Surface *screen) {

	cairo_surface_t *cairosurf = cairo_image_surface_create_for_data(screen->pixels, CAIRO_FORMAT_RGB24,
		screen->w, screen->h, screen->pitch);

	cairo_t* cr = cairo_create(cairosurf);

	cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);

	cairo_set_line_width(cr, 5);

	cairo_rectangle(cr, SCREEN_WIDTH, SCREEN_HEIGHT, SPRITE_SIZE, STEP_SIZE);

	cairo_stroke(cr);
}
/**
* @bref		Print a grid replacing numbers with specific pictures
* @param	grid g
*/
void print_grid(grid g)
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	SDL_Surface *screen, *sprite, *backbg, *wall, *health, *poison, *life,
		*heart, *noHeart, *tool, *hunter, *noTool, *mask;
	SDL_Rect rcSprite, rcGrass, rcWater, rcHealth, rcPoison, rcLife, rcHeart,
		rcNoHeart, rcTool, rcHunter, rcNoTool, rcMask;
	int colorkey;

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

	sprite = IMG_Load("../../data/penguin.png");

	colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	backbg = IMG_Load("../../data/snow.png");

	wall = SDL_LoadBMP("../../data/water.bmp");

	health = IMG_Load("../../data/fish.png");

	poison = IMG_Load("../../data/bomb.png");

	life = IMG_Load("../../data/life.png");
	if (life == NULL)
		printf("IMG_Load: %s\n", SDL_GetError());

	heart = IMG_Load("../../data/heart.png");

	noHeart = IMG_Load("../../data/noheart.png");

	tool = IMG_Load("../../data/glasses.png");

	hunter = IMG_Load("../../data/hunter.png");

	noTool = IMG_Load("../../data/snow.png");

	mask = IMG_Load("../../data/glasses.png");

	int i, j;

	for (i = 0; i < g.lines; i++)
	{
		for (j = 0; j < g.columns; j++)
		{
			if (g.plan[i][j] == 0) //background
			{
				rcGrass.x = j * SPRITE_SIZE;
				rcGrass.y = i * SPRITE_SIZE;
				SDL_BlitSurface(backbg, NULL, screen, &rcGrass);
			}
			else if (g.plan[i][j] == 1) //wall
			{
				rcWater.x = j * SPRITE_SIZE;
				rcWater.y = i * SPRITE_SIZE;
				SDL_BlitSurface(wall, NULL, screen, &rcWater);
			}
			else if (g.plan[i][j] == 2) //player
			{
				rcSprite.x = j * SPRITE_SIZE;
				rcSprite.y = i * SPRITE_SIZE;
				SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
			}
			else if (g.plan[i][j] == 3) //health
			{
				rcHealth.x = j * SPRITE_SIZE;
				rcHealth.y = i * SPRITE_SIZE;
				SDL_BlitSurface(health, NULL, screen, &rcHealth);
			}
			else if (g.plan[i][j] == 4) //poison
			{
				rcPoison.x = j * SPRITE_SIZE;
				rcPoison.y = i * SPRITE_SIZE;
				SDL_BlitSurface(poison, NULL, screen, &rcPoison);
			}
			else if (g.plan[i][j] == 5) //full life
			{
				rcLife.x = j * SPRITE_SIZE;
				rcLife.y = i * SPRITE_SIZE;
				SDL_BlitSurface(life, NULL, screen, &rcLife);
			}
			else if (g.plan[i][j] == 6) //shown nb lives
			{
				rcHeart.x = j * SPRITE_SIZE;
				rcHeart.y = i * SPRITE_SIZE;
				SDL_BlitSurface(heart, NULL, screen, &rcHeart);
			}
			else if (g.plan[i][j] == 7) //shown nb no lives
			{
				rcNoHeart.x = j * SPRITE_SIZE;
				rcNoHeart.y = i * SPRITE_SIZE;
				SDL_BlitSurface(noHeart, NULL, screen, &rcNoHeart);
			}
			else if (g.plan[i][j] == 8) //have tool
			{
				rcTool.x = j * SPRITE_SIZE;
				rcTool.y = i * SPRITE_SIZE;
				SDL_BlitSurface(tool, NULL, screen, &rcTool);
			}
			else if (g.plan[i][j] == 9) //hunter (monster)
			{
				rcHunter.x = j * SPRITE_SIZE;
				rcHunter.y = i * SPRITE_SIZE;
				SDL_BlitSurface(hunter, NULL, screen, &rcHunter);
			}
			else if (g.plan[i][j] == 10) //don't have tool(absence of tools)
			{
				rcNoTool.x = j * SPRITE_SIZE;
				rcNoTool.y = i * SPRITE_SIZE;
				SDL_BlitSurface(noTool, NULL, screen, &rcNoTool);
			}
			else if (g.plan[i][j] == 11) //mask
			{
				rcMask.x = j * SPRITE_SIZE;
				rcMask.y = i * SPRITE_SIZE;
				SDL_BlitSurface(mask, NULL, screen, &rcMask);
			}
		}
	}
	drawRectCairo(screen);

	SDL_UpdateRect(screen, 0, 0, 0, 0);

	SDL_FreeSurface(sprite);
	SDL_FreeSurface(backbg);
	SDL_FreeSurface(wall);
	SDL_FreeSurface(health);
	SDL_FreeSurface(poison);
	SDL_FreeSurface(life);
	SDL_FreeSurface(heart);
	SDL_FreeSurface(noHeart);
	SDL_FreeSurface(tool);
	SDL_FreeSurface(hunter);
	SDL_FreeSurface(noTool);
	SDL_FreeSurface(mask);
}

/**
* @bref		Opens window to play in the game
* @param	file_name char*
*/
void play(char* file_name)
{
	SDL_Event event;
	Uint8 *keystate;

	player p;
	p.position = load_point(file_name);
	grid g = load_grid(file_name);


	SDL_Init(SDL_INIT_VIDEO);


	SDL_WM_SetCaption("Penguin", "Penguin");

	int gameover = 0;
	int pause = 0;


	while (!gameover)
	{

		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_QUIT:
				gameover = 1;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
				case SDLK_q:
					gameover = 1;
					break;
				case SDLK_p: pause = 1;
					break;
				case SDLK_r: pause = 0;
					break;
				default:
					break;
				}
				break;
			}


			if (!pause)
			{
				keystate = SDL_GetKeyState(NULL);
				if (keystate[SDLK_UP])
				{
					go_up(&p, &g);
				}
				else if (keystate[SDLK_DOWN])
				{
					go_down(&p, &g);
				}
				else if (keystate[SDLK_RIGHT])
				{
					go_right(&p, &g);
				}
				else if (keystate[SDLK_LEFT])
				{
					go_left(&p, &g);
				}

			}

			
		}
		print_grid(g);

	}
	SDL_Quit();
}
