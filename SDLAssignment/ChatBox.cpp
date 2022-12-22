#include "ChatBox.h"

ChatBox::ChatBox(const std::string fileName, Screen& screen)
{
	m_image.Load("Assets/Images/" + fileName + ".png", screen);
	m_image.SetSpriteDimension(300, 100);
	m_image.SetImageDimension(1, 1, 1280, 720);

	m_text.Load("Assets/Fonts/impact.ttf", 100);
	m_text.SetColor(255, 255, 255, 255);
	m_text.SetDimension(70, 50);
}

ChatBox::~ChatBox()
{
}

//void ChatBox::Initialise(Screen& screen, const std::string fileName, std::string msgText)
//{
//	m_image.Load("Assets/Images/" + fileName + ".png", screen);
//	m_image.SetSpriteDimension(1280, 720);
//	m_image.SetImageDimension(1, 1, 1280, 720);
//
//	m_text.Load("Assets/Fonts/impact.ttf", 100);
//	m_text.SetColor(255, 255, 255, 255);
//	m_text.SetDimension(70, 50);
//}

void ChatBox::Update(Input& input)
{
}

void ChatBox::Render(Screen& screen)
{
	this->SetPosition((screen.GetResolution().x / 2) - m_image.GetSpriteDimension().x / 2, (screen.GetResolution().y / 2 + 150) - m_image.GetSpriteDimension().y / 2 + 150);
	m_image.Render(this->GetPosition().x, this->GetPosition().y, screen);


}

void ChatBox::UpdateText()
{
	//m_text.SetText()
}

char* ChatBox::GetMsgReceived(char* msg)
{
	return msg;
}

void ChatBox::Shutdown()
{
}
