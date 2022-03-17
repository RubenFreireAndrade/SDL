#pragma once
#include <SDL_ttf.h>
#include "Screen.h"
#include "Player.h"

class EndScreen
{
	enum ConditionState
	{
		WIN,
		LOSS
	};

public:

	EndScreen();
	~EndScreen();

	void RenderEndScreen(Screen& screen, int state);
	void Unload();

private:

	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Color color;
	SDL_Rect textBox = {0, 0, 0, 0};

	TTF_Font* font = nullptr;
};

