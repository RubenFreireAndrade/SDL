#include "EndScreen.h"

EndScreen::EndScreen(const std::string& fileName, Screen& screen)
{
	/*endScreenBtnState = EndScreenButtonState::DEFAULT;*/
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
	/*m_textToScreen.Load("Assets/Fonts/impact.ttf", 300);
	m_textToScreen.SetColor(0, 168, 255, 255);*/

	//m_background.Load("Assets/Images/MountainBackgrundBlue.png", screen);
	//m_background.SetSpriteDimension(1280, 720);
	//m_background.SetImageDimension(1, 1, 1280, 720);
}

void EndScreen::Update(Input& input)
{
}

void EndScreen::Render(Screen& screen, int state)
{
	/*if (state == WIN)
	{
		const char* message = "";
		message = "You Win!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(300, 150);
	}
	else if (state == LOSS)
	{
		const char* message = "";
		message = "You Lost! Restart Game To Try Again!";
		m_textToScreen.SetText(message);
		m_textToScreen.SetDimension(700, 150);
	}
	m_background.Render(PosX, PosY, screen, m_background.NO_FLIP);
	m_textToScreen.Render((screen.GetResolution().x / 2) - m_textToScreen.GetDimension().x / 2, screen.GetResolution().y / 2 - m_textToScreen.GetDimension().y / 2, screen);*/
	m_button.Render((screen.GetResolution().x / 2) - m_button.GetSpriteDimension().x / 2, this->GetPosition().y, screen);

	//this->SetPosition((screen.GetResolution().x / 2) - m_btnSprite.GetSpriteDimension().x / 2, this->GetPosition().y);
}

void EndScreen::ShutDown()
{
	m_button.Unload();
	//m_background.Unload();
	//TTF_CloseFont(font);
}
