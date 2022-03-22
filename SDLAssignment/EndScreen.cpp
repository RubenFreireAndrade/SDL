#include "EndScreen.h"
#include <iostream>

EndScreen::EndScreen()
{
	m_textToScreen.Load("Assets/Fonts/impact.ttf", 300);
	m_textToScreen.SetColor(255, 153, 51, 255);
}

EndScreen::~EndScreen()
{

}

void EndScreen::RenderEndScreen(Screen& screen, int state)
{
	if (state == WIN)
	{
		const char* message = "";
		/*SetDimension(300, 150);
		SetPosition(525, 600 / 2);*/
		message = "You Win!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(300, 150);
	}
	else if(state == LOSS)
	{
		const char* message = "";
		/*SetDimension(700, 150);
		SetPosition(300, 600 / 2);*/
		message = "You Lost! Restart Game To Try Again!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(700, 150);
	}
	m_textToScreen.Render(textBox.x, textBox.y, screen);
	/*surface = TTF_RenderText_Solid(font, message, color);
	texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), surface);
	textBox.y = 600 / 2;
	textBox.h = 150;*/

	//SDL_RenderCopy(screen.GetRenderer(), texture, NULL, &textBox);
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
	TTF_CloseFont(font);
}
