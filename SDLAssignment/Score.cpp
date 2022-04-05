#include "Score.h"

Score::Score()
{
}

Score::~Score()
{
}

void Score::Initialise(Screen& screen, Player* p)
{
	m_player = p;
	m_text.Load("Assets/Fonts/impact.ttf", 100);
	m_text.SetColor(255, 255, 255, 255);
	m_text.SetDimension(70, 50);
}

void Score::Render(Screen& screen)
{
	AddToScore();
	m_text.Render(scorePosX, scorePosY, screen);
}

void Score::AddToScore()
{
	m_text.SetText("Score: " + std::to_string(m_player->GetScore()));
}
