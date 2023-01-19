#pragma once
#include"Sprite.h"
#include"GameObject.h"
#include"TextToScreen.h"

class ChatBox : public GameObject
{
public:
	ChatBox(const std::string fileName, Screen& screen);
	~ChatBox();
	// Inherited via GameObject
	void Initialise(Screen& screen);
	void Update(Input& input);
	void Render(Screen& screen);
	void UpdateText();
	char* GetMsgReceived(char* msg);
	void Shutdown();

private:
	Sprite m_image;
	TextToScreen m_text;
};