#pragma once
#include"Sprite.h"
#include"GameObject.h"
#include"TextToScreen.h"

class ChatBox : public GameObject
{
public:
	ChatBox(const std::string fileName, const std::string& message, Screen& screen);
	~ChatBox();
	// Inherited via GameObject
	void Initialise(Screen& screen);
	void Update(Input& input);
	void Render(Screen& screen);
	void Shutdown();

	std::string GetIncomingText();
	void SetIncomingText(std::string t);

private:
	std::string m_incomingText;

	Sprite m_image;
	TextToScreen m_text;
};