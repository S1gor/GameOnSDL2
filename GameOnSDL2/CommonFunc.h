#ifndef _COMMON_FUNCTION_H_
#define _COMMON_FUNCTION_H_

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

static SDL_Window* win = NULL;
static SDL_Renderer* ren = NULL;
static SDL_Event event;

//Screen
const int win_width = 1280;
const int win_height = 640;

//Map
#define TILE_SIZE 64
#define MAX_MAP_X 400
#define MAX_MAP_Y 10

struct Map
{
	int start_x;
	int start_y;

	int max_x;
	int max_y;

	int tile[MAX_MAP_Y][MAX_MAP_X];
	char* filename;
};
#endif