#include "ChatBox.h"

ChatBox::ChatBox(const std::string fileName, Screen& screen)
{
	this->isStatic = true;
	m_image.Load("Assets/Images/" + fileName + ".png", screen);
	m_image.SetImageDimension(1, 1, 1280, 720);
	m_image.SetSpriteDimension(500, 400);

	m_inputLine.Load("Assets/Fonts/impact.ttf", 100);
	m_inputLine.SetColor(255, 255, 255, 255);
	m_inputLine.SetDimension(250, 40);

	for (int i = 0; i < 5; i++) {
		auto text = TextToScreen();
		text.Load("Assets/Fonts/impact.ttf", 100);
		text.SetColor(255, 255, 255, 255);
		text.SetDimension(250, 40);
		m_chat.push_back(text);
	}
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

	m_inputLine.Render((screen.GetResolution().x / 2) - m_inputLine.GetDimension().x / 2, (screen.GetResolution().y / 2) - m_inputLine.GetDimension().y / 2 + 340, screen);

	// Setting Chat Text position of Chat Box.
	for (int i = 0; i < m_chat.size(); i++)
	{
		m_chat[i].Render((screen.GetResolution().x / 2) - m_chat[i].GetDimension().x / 2, (screen.GetResolution().y / 2) - m_chat[i].GetDimension().y / 2 + 125 + (40 * i), screen);
	}
}

void ChatBox::Shutdown()
{
	for (auto text : m_chat)
	{
		text.ShutDown();
	}
	m_image.Unload();
}

void ChatBox::SetChatInput(std::string t)
{
	m_inputLine.SetText("[     " + t + "     ]");
}

void ChatBox::AddChatText(std::string t)
{
	auto chatLastLine = m_chat.size() - 1;

	// Moving all the previous messages/lines up if a new one was added (ignoring last)
	for (int i = 0; i < chatLastLine; i++) {
		m_chat[i].SetText(m_chat[i + 1].GetText());
	}

	// Adding input to last element/line of the chat box
	m_chat[chatLastLine].SetText(t);
}

void ChatBox::AddIncomingText(std::string username, std::string t)
{
	AddChatText(username + ": " + t);
}

void ChatBox::AddOutgoingText(std::string t)
{
	AddChatText("You said: " + t);
}
