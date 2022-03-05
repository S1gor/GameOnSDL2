#include"CommonFunc.h"

void DeInit(int error)
{
	if (ren != NULL) SDL_DestroyRenderer(ren);
	if (win != NULL) SDL_DestroyWindow(win);
	IMG_Quit();
	SDL_Quit();
	exit(error);
}

void Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Не удалось инициализировать SDL!");
		DeInit(1);
	}

	win = SDL_CreateWindow("GameOnSDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_width, win_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == NULL)
	{
		printf("Не удалось создать окно!");
		DeInit(1);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL)
	{
		printf("Не удалось создать рисовальщик!");
		DeInit(1);
	}

	int res;
	if ((res = (IMG_INIT_PNG | IMG_INIT_JPG)) == 0)
	{
		printf("Не удалось инициализировать SDL_Image!");
		DeInit(1);
	}
	if (res & IMG_INIT_PNG) printf("Инициализирована библиотека PNG.\n"); else printf("Не удалось инициализировать библиотеку PNG.");
	if (res & IMG_INIT_JPG) printf("Инициализирована библиотека JPG.\n"); else printf("Не удалось инициализировать библиотеку JPG.");
}

SDL_Texture* loadTextureFromFile(const char* filename, SDL_Rect* rect)
{
	SDL_Surface* surface = IMG_Load(filename);
	if (surface == NULL)
	{
		printf("Не удалось загрузить картинку!");
		DeInit(1);
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	*rect = { 0,0,surface->w,surface->h };
	SDL_FreeSurface(surface);
	return texture;
}

int main(int args, char* argv[])
{
	system("chcp 1251"); system("cls");
	Init();

	SDL_Rect back_rect;
	SDL_Texture* back_tex = loadTextureFromFile("back.png", &back_rect);




	bool isRunning = true;
	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			}

			SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
			SDL_RenderClear(ren);

			SDL_RenderCopy(ren, back_tex, &back_rect, NULL);
		}
		SDL_RenderPresent(ren);
		SDL_Delay(50);	
	}

	SDL_DestroyTexture(back_tex);

	DeInit(0);
	return 0;
}