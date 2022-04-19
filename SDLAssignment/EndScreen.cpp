#include "EndScreen.h"
#include <iostream>

EndScreen::EndScreen(Screen& screen)
{
	m_textToScreen.Load("Assets/Fonts/impact.ttf", 300);
	m_textToScreen.SetColor(255, 153, 51, 255);

	m_sprite.Load("Assets/Images/darkBackground.png", screen);
	m_sprite.SetSpriteDimension(1280, 720);
	m_sprite.SetImageDimension(1, 1, 1280, 720);
}

EndScreen::~EndScreen()
{
}

void EndScreen::RenderEndScreen(Screen& screen, int state)
{
	if (state == WIN)
	{
		const char* message = "";
		message = "You Win!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(300, 150);
	}
	else if(state == LOSS)
	{
		const char* message = "";
		message = "You Lost! Restart Game To Try Again!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(700, 150);
	}
	m_sprite.Render(0, 0, screen, m_sprite.NO_FLIP);
	m_textToScreen.Render((screen.GetResolution().x / 2) - m_textToScreen.GetDimension().x / 2 , screen.GetResolution().y / 2 - m_textToScreen.GetDimension().y / 2, screen);
}

void EndScreen::SetPosition(int x, int y)
{
	textBox.x = x;
	textBox.y = y;
}

void EndScreen::SetDimension(int w, int h)
{
	textBox.w = w;
	textBox.h = h;
}

void EndScreen::Unload()
{
	m_sprite.Unload();
	TTF_CloseFont(font);
}
