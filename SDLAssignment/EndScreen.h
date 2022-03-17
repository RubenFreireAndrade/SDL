#pragma once
#include <SDL_ttf.h>
#include "Screen.h"
#include "TextToScreen.h"
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
	void SetPosition(int x, int y);
	void SetDimension(int w, int h);
	void Unload();

private:

	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect textBox = {0, 0, 0, 0};
	TTF_Font* font = nullptr;

	TextToScreen m_textToScreen;
	int textPosX = 0;
	int textPosY = 0;
};

