#pragma once
#include <SDL_ttf.h>
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"

class WriteToScreen
{

public:

	WriteToScreen(/*Player* p*/);
	~WriteToScreen();

	bool Initialise();
	void Unload();
	void RenderScore(Screen& screen);

private:

	Player player;

	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Color color;
	SDL_Rect textBox;

	TTF_Font* font;
	Screen m_renderer;
};
