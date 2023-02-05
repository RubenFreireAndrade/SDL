#include "MenuButton.h"

MenuButton::MenuButton(const std::string& fileName, int imgWidth, int imgHeight, Screen& screen)
{
	mousePosition = { 0, 0 };
	buttonPosition = { 0, 0 };
	buttonState = ButtonState::DEFAULT;

	this->SetTag(fileName);
	m_btnSprite.Load("Assets/Images/" + this->GetTag() + ".png", screen);
	m_btnSprite.SetImageDimension(2, 1, imgWidth, imgHeight);
	m_btnSprite.SetSpriteDimension(150, 50);
	m_btnSprite.SetImageCell(1, 1);
}

void MenuButton::Initialise(Screen& screen)
{
}

void MenuButton::Update(Input& input)
{
	this->GetButtonRect();
	mousePosition.x = input.GetMousePosition().x;
	mousePosition.y = input.GetMousePosition().y;
	if (SDL_PointInRect(&mousePosition, &buttonPosition))
	{
		buttonState = ButtonState::HOVER;
		if (input.IsMouseClicked())
		{
			buttonState = ButtonState::CLICKED;
		}
	}
	else
	{
		buttonState = ButtonState::DEFAULT;
	}
}

void MenuButton::Render(Screen& screen)
{
	if (buttonState == ButtonState::HOVER)
	{
		m_btnSprite.SetImageCell(2, 1);
	}
	if (buttonState == ButtonState::DEFAULT)
	{
		m_btnSprite.SetImageCell(1, 1);
	}
	this->SetPosition((screen.GetResolution().x / 2) - m_btnSprite.GetSpriteDimension().x / 2, this->GetPosition().y);
	m_btnSprite.Render(this->GetPosition().x, this->GetPosition().y, screen);
}

void MenuButton::GetButtonRect()
{
	buttonPosition.x = this->GetPosition().x;
	buttonPosition.y = this->GetPosition().y;
	buttonPosition.w = m_btnSprite.GetSpriteDimension().x;
	buttonPosition.h = m_btnSprite.GetSpriteDimension().y;
}

const MenuButton::ButtonState& MenuButton::GetState() const
{
	return buttonState;
}

void MenuButton::ShutDown()
{
	m_btnSprite.Unload();
}