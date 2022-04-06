#include "Background.h"
#include <SDL_image.h>

Background::Background()
{
	isStatic = true;
	//this->SetSize(1280, 720);
}

void Background::Initialise(Screen& screen)
{
	m_image.Load("Assets/Images/gaERSZ.png", screen);
	m_image.SetSpriteDimension(1280, 720);
	m_image.SetImageDimension(1, 1, 1280, 720);
}

void Background::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, screen);
}

void Background::Update(Input& input)
{
	//m_image.SetSpriteDimension();
}
