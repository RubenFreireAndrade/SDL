#include "ChatBox.h"

ChatBox::ChatBox(const std::string fileName, const std::string& message, Screen& screen)
{
	this->isStatic = true;
	m_image.Load("Assets/Images/" + fileName + ".png", screen);
	m_image.SetImageDimension(1, 1, 1280, 720);
	m_image.SetSpriteDimension(300, 100);

	m_text.Load("Assets/Fonts/impact.ttf", 100);
	m_text.SetColor(255, 255, 255, 255);
	m_text.SetDimension(250, 40);

	m_incomingText = message;
}

ChatBox::~ChatBox()
{
}

void ChatBox::Initialise(Screen& screen)
{
}

void ChatBox::Update(Input& input)
{
}

void ChatBox::Render(Screen& screen)
{
	// Setting Chat box position on the screen.
	this->SetPosition((screen.GetResolution().x / 2) - m_image.GetSpriteDimension().x / 2, (screen.GetResolution().y / 2) - m_image.GetSpriteDimension().y / 2);
	m_image.Render(this->GetPosition().x, this->GetPosition().y + 300, screen);

	m_text.SetText(SetIncomingText());
	// Setting Text inside the Chat box.
	m_text.Render(this->GetPosition().x + 25, this->GetPosition().y + 300, screen);
}

std::string ChatBox::SetIncomingText()
{
	return m_incomingText;
}

void ChatBox::Shutdown()
{
}

std::string ChatBox::GetIncomingText(std::string incomingText)
{
	return m_incomingText = incomingText;
}
