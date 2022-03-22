#include "Score.h"

Score::Score()
{
	m_text.Load("Assets/Fonts/impact.ttf", 100);
	m_text.SetColor(255, 255, 255, 255);
	m_text.SetDimension(70, 50);
	score = m_player.GetScore();
}

Score::~Score()
{
}

void Score::Render(Screen& screen)
{
	AddToScore();
	m_text.Render(scorePosX, scorePosY, screen);
}

void Score::AddToScore()
{
	m_text.SetText("Score: " + std::to_string(score));
}
