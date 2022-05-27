#include "Background.h"

Background::Background(const std::string& fileName, Screen& screen)
{
	m_image.Load("Assets/Images/" + fileName + ".png", screen);
	m_image.SetSpriteDimension(1280, 720);
	m_image.SetImageDimension(1, 1, 1280, 720);
}

void Background::Initialise(Screen& screen)
{
}

void Background::Render(Screen& screen)
{
	m_image.Render(this->GetPosition().x, this->GetPosition().y, screen);
}

void Background::Update(Input& input)
{
}

void Background::ShutDown()
{
	m_image.Unload();
}