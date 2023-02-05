#include "ServerText.h"

ServerText::ServerText(const std::string& message, Screen& screen)
{
	this->isStatic = true;

	m_serverTxt.Load("Assets/Fonts/impact.ttf", 100);
	m_serverTxt.SetColor(255, 255, 255, 255);
	m_serverTxt.SetDimension(250, 40);

	m_incomingText = message;
}

ServerText::~ServerText()
{
}

void ServerText::Initialise(Screen& screen)
{
}

void ServerText::Update(Input& input, GameState& state)
{
}

void ServerText::Render(Screen& screen)
{
	m_serverTxt.SetText(GetIncomingText());
	m_serverTxt.Render((screen.GetResolution().x / 2) - m_serverTxt.GetDimension().x / 2, (screen.GetResolution().y - screen.GetResolution().y) - m_serverTxt.GetDimension().y / 2 + 20, screen);
}

void ServerText::Shutdown()
{
	m_serverTxt.ShutDown();
}

void ServerText::SetIncomingText(std::string text)
{
	m_incomingText = text;
}

std::string ServerText::GetIncomingText()
{
	return m_incomingText;
}
