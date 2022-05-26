#include "EndScreen.h"

EndScreen::EndScreen(const std::string& fileName, Screen& screen)
{
	this->SetTag(fileName);
	m_button.Load("Assets/Images/" + this->GetTag() + ".png", screen);
	m_button.SetImageDimension(2, 1, 1200, 200);
	m_button.SetSpriteDimension(150, 50);
	m_button.SetImageCell(1, 1);
}

EndScreen::~EndScreen()
{
}

void EndScreen::Initialise(Screen& screen)
{
}

void EndScreen::Update(Input& input)
{
}

void EndScreen::Render(Screen& screen, int state)
{
	m_button.Render((screen.GetResolution().x / 2) - m_button.GetSpriteDimension().x / 2, this->GetPosition().y, screen, Sprite::Flip::NO_FLIP);
}

void EndScreen::ShutDown()
{
	m_button.Unload();
	TTF_CloseFont(font);
}
