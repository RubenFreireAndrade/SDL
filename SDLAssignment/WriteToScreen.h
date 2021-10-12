#pragma once

#include <SDL_ttf.h>
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class WriteToScreen
{

public:

	WriteToScreen(Player* p);
	~WriteToScreen();

	void RenderScore(Screen& screen);

private:

	Player* player;
	Bullet* bullet;

	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Color color;
	SDL_Rect textBox;

	TTF_Font* font;
	Screen m_renderer;
};
