#pragma once
#include <SDL_ttf.h>
#include "Screen.h"

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

private:

	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Color color;
	SDL_Rect textBox;

	TTF_Font* font;
	Screen m_renderer;
};

