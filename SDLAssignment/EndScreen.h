#pragma once
#include <SDL_ttf.h>
#include <vector>
#include "Screen.h"
#include "Player.h"
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

	EndScreen(Screen& screen);
	~EndScreen();

	void RenderEndScreen(Screen& screen, int state);
	void SetPosition(int x, int y);
	void SetDimension(int w, int h);
	void Unload();

private:

	TTF_Font* font = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect textBox = {0, 0, 0, 0};

	Sprite m_sprite;
	TextToScreen m_textToScreen;
};

