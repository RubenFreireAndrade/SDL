#include "TextToScreen.h"
#include <SDL_ttf.h>
#include "Screen.h"

bool TextToScreen::Initialise()
{
	if (TTF_Init() == -1) return false;
	return true;
}

TextToScreen::TextToScreen()
{
}

void TextToScreen::SetText(const std::string& text)
{
	m_line = text;
	m_isDirty = true;
}

void TextToScreen::SetColor(const SDL_Color& color)
{
	m_color = color;
	m_isDirty = true;
}

void TextToScreen::SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
	m_isDirty = true;
}

void TextToScreen::SetDimension(const int width, const int height)
{
	m_dimension = { width, height };
}

bool TextToScreen::Load(const std::string& filename, const int fontSize)
{
	m_font = TTF_OpenFont(filename.c_str(), fontSize);
	if (!m_font)
	{
		return false;
	}
	return true;
}

void TextToScreen::Render(const int xPos, const int yPos, Screen& screen)
{
	m_targetRect.x = xPos;
	m_targetRect.y = yPos;
	m_targetRect.w = m_dimension.x;
	m_targetRect.h = m_dimension.y;
	if (m_isDirty)
	{
		SDL_DestroyTexture(m_texture);
		m_textData = TTF_RenderText_Blended(m_font, m_line.c_str(), m_color);
		m_texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), m_textData);
		SDL_FreeSurface(m_textData);
		m_isDirty = false;
	}
	SDL_RenderCopy(screen.GetRenderer(), m_texture, nullptr, &m_targetRect);
}

SDL_Point TextToScreen::GetDimension() const
{
	return m_dimension;
}

void TextToScreen::ShutDown()
{
	TTF_CloseFont(m_font);
}
