#include "ChatBox.h"

ChatBox::ChatBox(const std::string fileName, Screen& screen)
{
	this->isStatic = true;
	m_image.Load("Assets/Images/" + fileName + ".png", screen);
	m_image.SetImageDimension(1, 1, 1280, 720);
	m_image.SetSpriteDimension(300, 100);

	m_textForServer.Load("Assets/Fonts/impact.ttf", 100);
	m_textForServer.SetColor(255, 255, 255, 255);
	m_textForServer.SetDimension(250, 40);

	m_chatText.Load("Assets/Fonts/impact.ttf", 100);
	m_chatText.SetColor(255, 255, 255, 255);
	m_chatText.SetDimension(250, 40);
}

ChatBox::~ChatBox()
{
}

void ChatBox::Initialise(Screen& screen)
{
}

void ChatBox::Update(Input& input, GameState& state)
{
}

void ChatBox::Render(Screen& screen)
{
	// Setting Chat box position on the screen.
	m_image.Render((screen.GetResolution().x / 2) - m_image.GetSpriteDimension().x / 2, (screen.GetResolution().y / 2) - m_image.GetSpriteDimension().y / 2 + 300, screen);

	/*m_textForServer.SetText(GetIncomingText());
	m_textForServer.Render((screen.GetResolution().x / 2) - m_textForServer.GetDimension().x / 2, (screen.GetResolution().y - screen.GetResolution().y + 20) - m_textForServer.GetDimension().y / 2, screen);*/

	m_chatText.SetText(GetChatInput());
	// Setting Chat Text position of Chat Box.
	m_chatText.Render((screen.GetResolution().x / 2) - m_chatText.GetDimension().x / 2, (screen.GetResolution().y / 2) - m_chatText.GetDimension().y / 2 + 300, screen);
}

void ChatBox::Shutdown()
{
	m_textForServer.ShutDown();
	m_chatText.ShutDown();
	m_image.Unload();
}

std::string ChatBox::GetIncomingText()
{
	return m_incomingText;
}

std::string ChatBox::GetChatInput()
{
	return m_chatInput;
}

void ChatBox::SetChatInput(std::string t)
{
	m_chatInput = t;
}

void ChatBox::SetIncomingText(std::string t)
{
	m_incomingText = t;
}
