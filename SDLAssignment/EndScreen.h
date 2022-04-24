#pragma once
#include <SDL_ttf.h>
#include <vector>
#include "Screen.h"
#include "Sprite.h"
#include "TextToScreen.h"

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

	void Initialise(Screen& screen);
	void Render(Screen& screen, int state);
	void ShutDown();

	void SetPosition(int x, int y);
	void SetDimension(int w, int h);

private:

	TTF_Font* font = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect textBox = {0, 0, 0, 0};

	int PosX = 0;
	int PosY = 0;
	Sprite m_sprite;
	TextToScreen m_textToScreen;
};

