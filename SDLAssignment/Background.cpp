#include "Background.h"
#include <SDL_image.h>

Background::Background()
{
	isStatic = true;
}

void Background::Initialise(Screen& screen)
{
	m_image.Load("Assets/Images/gaERSZ.png", screen);
	m_image.SetSpriteDimension(1280, 720);
	m_image.SetImageDimension(1, 1, 1280, 720);
}

void Background::Render(Screen& screen)
{
	// This function is to react with resizing of the screen.
	//m_image.SetSpriteDimension(screen.GetResolution().x, screen.GetResolution().y);
	///////////////////////////////////////////////////////////////////////////////////
	m_image.Render(this->GetPosition().x, this->GetPosition().y, screen);
}

void Background::Update(Input& input)
{
}

void Background::ShutDown()
{
	m_image.Unload();
}