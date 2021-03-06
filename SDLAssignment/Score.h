#pragma once
#include "TextToScreen.h"
#include "Player.h"

class Score
{
public:
	Score();
	~Score();

	void Initialise(Screen& screen, Player* p);
	void Render(Screen& screen);
	void AddToScore();
private:
	TextToScreen m_text = {};
	Player* m_player = {};

	int scorePosX = 0;
	int scorePosY = 0;
};

