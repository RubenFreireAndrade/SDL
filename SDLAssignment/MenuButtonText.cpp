#include "MenuButtonText.h"

MenuButtonText::MenuButtonText(std::string text)
{
	mousePosition = { 0, 0 };
	buttonPosition = { 0, 0 };
	buttonState = ButtonState::DEFAULT;

	this->SetTag(text);
	m_btnText.Load("Assets/Fonts/impact.ttf", 100);
	m_btnText.SetText(this->GetTag());
	m_btnText.SetDimension(200, 70);
}

void MenuButtonText::Update(Input& input, GameState& state)
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

void MenuButtonText::Render(Screen& screen)
{
	if (buttonState == ButtonState::HOVER)
	{
		m_btnText.SetColor(0, 168, 255, 255);
	}
	if (buttonState == ButtonState::DEFAULT)
	{
		m_btnText.SetColor(255, 255, 255, 255);
	}
	this->SetPosition((screen.GetResolution().x / 2) - m_btnText.GetDimension().x / 2, this->GetPosition().y);
	m_btnText.Render(this->GetPosition().x, this->GetPosition().y, screen);
}

void MenuButtonText::ShutDown()
{
	m_btnSprite.Unload();
}

void MenuButtonText::GetButtonRect()
{
	buttonPosition.x = this->GetPosition().x;
	buttonPosition.y = this->GetPosition().y;
	buttonPosition.w = m_btnText.GetDimension().x;
	buttonPosition.h = m_btnText.GetDimension().y;
}

const MenuButtonText::ButtonState& MenuButtonText::GetState() const
{
	return buttonState;
}
